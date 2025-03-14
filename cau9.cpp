#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

struct Student
{
    char id[6];
    char lastName[21];
    char firstName[41];
    char dob[11];
    char gender[7];
    double gpa;

    void setString(char *dest, const std::string &src, size_t maxLen)
    {
        strncpy(dest, src.c_str(), maxLen - 1);
        dest[maxLen - 1] = '\0';
    }

    Student(const std::string &i, const std::string &ln, const std::string &fn,
            const std::string &d, const std::string &g, double gp) : gpa(gp)
    {
        setString(id, i, 6);
        setString(lastName, ln, 21);
        setString(firstName, fn, 41);
        setString(dob, d, 11);
        setString(gender, g, 7);
    }
    Student() {}
};

struct Index
{
    char id[6];
    long offset;
};

void inputStudentList(std::vector<Student> &students)
{
    students = {
        {"SV001", "Dang", "Thanh Dai", "2000-01-01", "Male", 9.5},
        {"SV002", "Ngo", "Gia Bao", "2000-02-15", "Male", 7.9},
        {"SV003", "Ho", "Huu Anh Tuan", "2000-03-10", "Male", 9.1},
        {"SV004", "Nguyen", "Thanh Vinh", "2000-04-12", "Male", 8.2},
        {"SV005", "Nguyen", "Minh Thuan", "2000-05-25", "Male", 7.8},
        {"SV006", "Nguyen", "Gia An", "2000-06-18", "Male", 9.3},
        {"SV007", "Le", "Thanh Thuy", "2000-07-30", "Female", 8.0},
        {"SV008", "Nguyen", "Lan Anh", "2000-08-20", "Female", 8.7},
        {"SV009", "Ho", "Trung Hieu", "2000-09-10", "Male", 7.5},
        {"SV010", "Nguyen", "Minh Hao", "2000-10-05", "Male", 8.3}};
}

void outputStudent(const Student &student)
{
    std::cout << "ID: " << student.id << "\n"
              << "Name: " << student.lastName << " " << student.firstName << "\n"
              << "Date of birth: " << student.dob << "\n"
              << "Gender: " << student.gender << "\n"
              << "GPA: " << student.gpa << "\n\n";
}

void saveStudentListToFile(const std::vector<Student> &students)
{
    std::ofstream file("STUDENTS.DAT", std::ios::binary);
    if (!file)
    {
        std::cerr << "Cannot open file STUDENTS.DAT!\n";
        return;
    }
    for (const auto &student : students)
    {
        file.write(reinterpret_cast<const char *>(&student), sizeof(Student));
    }
    file.close();
}

void sortByID(std::vector<Student> &students)
{
    int n = students.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(students[j].id, students[j + 1].id) > 0)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByName(std::vector<Student> &students)
{
    int n = students.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int cmp = strcmp(students[j].firstName, students[j + 1].firstName);
            if (cmp > 0 || (cmp == 0 && strcmp(students[j].lastName, students[j + 1].lastName) > 0))
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByGPA(std::vector<Student> &students)
{
    int n = students.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].gpa < students[j + 1].gpa)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void createIndexFile(const std::vector<Student> &students, const std::string &filename,
                     bool (*cmp)(const Student &, const Student &))
{
    std::vector<Index> indices;
    std::fstream dataFile("STUDENTS.DAT", std::ios::binary | std::ios::in);
    if (!dataFile)
    {
        std::cerr << "Cannot open file STUDENTS.DAT!\n";
        return;
    }

    long offset = 0;
    for (const auto &student : students)
    {
        Index idx;
        strcpy(idx.id, student.id);
        idx.offset = offset;
        indices.push_back(idx);
        offset += sizeof(Student);
    }

    int n = indices.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            Student sa, sb;
            dataFile.seekg(indices[j].offset);
            dataFile.read(reinterpret_cast<char *>(&sa), sizeof(Student));
            dataFile.seekg(indices[j + 1].offset);
            dataFile.read(reinterpret_cast<char *>(&sb), sizeof(Student));
            if (cmp(sa, sb))
            {
                Index temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    std::ofstream idxFile(filename, std::ios::binary);
    if (!idxFile)
    {
        std::cerr << "Cannot open file " << filename << "!\n";
        return;
    }
    idxFile.write(reinterpret_cast<const char *>(indices.data()), indices.size() * sizeof(Index));
    idxFile.close();
    dataFile.close();
}

void readFromIndexAndPrint(const std::string &idxFilename)
{
    std::ifstream idxFile(idxFilename, std::ios::binary);
    std::fstream dataFile("STUDENTS.DAT", std::ios::binary | std::ios::in);
    if (!idxFile || !dataFile)
    {
        std::cerr << "Cannot open file!\n";
        return;
    }

    Index idx;
    while (idxFile.read(reinterpret_cast<char *>(&idx), sizeof(Index)))
    {
        Student student;
        dataFile.seekg(idx.offset);
        dataFile.read(reinterpret_cast<char *>(&student), sizeof(Student));
        outputStudent(student);
    }
    idxFile.close();
    dataFile.close();
}

int main()
{
    std::vector<Student> students;

    inputStudentList(students);
    saveStudentListToFile(students);

    sortByID(students);
    std::cout << "List sorted by ID:\n";
    for (const auto &student : students)
        outputStudent(student);

    createIndexFile(students, "ID_INDEX.IDX",
                    [](const Student &a, const Student &b)
                    { return strcmp(a.id, b.id) > 0; });
    createIndexFile(students, "NAME_INDEX.IDX",
                    [](const Student &a, const Student &b)
                    {
                        int cmp = strcmp(a.firstName, b.firstName);
                        if (cmp != 0)
                            return cmp > 0;
                        return strcmp(a.lastName, b.lastName) > 0;
                    });
    createIndexFile(students, "GPA_INDEX.IDX",
                    [](const Student &a, const Student &b)
                    { return a.gpa < b.gpa; });

    std::cout << "\nList by ID index:\n";
    readFromIndexAndPrint("ID_INDEX.IDX");

    std::cout << "\nList by Name index:\n";
    readFromIndexAndPrint("NAME_INDEX.IDX");

    std::cout << "\nList by GPA index:\n";
    readFromIndexAndPrint("GPA_INDEX.IDX");

    return 0;
}