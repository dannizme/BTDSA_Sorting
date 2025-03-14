#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <algorithm>

#define MAX_SIZE 30000

// Hàm để tạo dữ liệu ngẫu nhiên và lưu vào file
void generate_data(const std::string &filename, int num_elements = MAX_SIZE)
{
    std::ofstream outfile(filename);
    if (outfile.is_open())
    {
        for (int i = 0; i < num_elements; ++i)
        {
            outfile << rand() % 100000 + 1 << std::endl;
        }
        outfile.close();
    }
}

// Hàm đọc dữ liệu từ file
int read_data(const std::string &filename, int arr[], int max_size)
{
    std::ifstream infile(filename);
    int num_elements = 0;
    while (infile >> arr[num_elements] && num_elements < max_size)
    {
        ++num_elements;
    }
    return num_elements;
}

// Interchange Sort (Sắp xếp đổi chỗ trực tiếp)
void interchange_sort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

// Selection Sort (Sắp xếp chọn trực tiếp)
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

// Insertion Sort (Sắp xếp chèn trực tiếp)
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort (Sắp xếp nổi bọt)
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quick Sort (Sắp xếp nhanh)
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j)
        {
            if (arr[j] < pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Merge Sort (Sắp xếp trộn)
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Heap Sort (Sắp xếp cây)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Hàm đo thời gian cho từng thuật toán
double measure_time_interchange(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    interchange_sort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_selection(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    selection_sort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_insertion(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    insertion_sort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_bubble(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    bubble_sort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_quick(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_merge(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

double measure_time_heap(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    heap_sort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Hàm lưu kết quả vào file
void save_results(const std::string &filename, const std::string &name, double time_taken)
{
    std::ofstream outfile(filename, std::ios_base::app); // Append mode
    if (outfile.is_open())
    {
        outfile << name << ": " << time_taken << " seconds\n";
        outfile.close();
    }
}

int main()
{
    const std::string input_filename = "input_data.txt";
    const std::string output_filename = "output_results.txt";

    // Tạo dữ liệu ngẫu nhiên và lưu vào file
    generate_data(input_filename);

    // Đọc dữ liệu từ file
    int data[MAX_SIZE];
    int n = read_data(input_filename, data, MAX_SIZE);

    // Các thuật toán sắp xếp
    double time_taken;

    // Interchange Sort
    int data_copy[MAX_SIZE];
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_interchange(data_copy, n);
    save_results(output_filename, "Interchange Sort", time_taken);

    // Selection Sort
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_selection(data_copy, n);
    save_results(output_filename, "Selection Sort", time_taken);

    // Insertion Sort
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_insertion(data_copy, n);
    save_results(output_filename, "Insertion Sort", time_taken);

    // Bubble Sort
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_bubble(data_copy, n);
    save_results(output_filename, "Bubble Sort", time_taken);

    // Quick Sort
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_quick(data_copy, n);
    save_results(output_filename, "Quick Sort", time_taken);

    // Merge Sort
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_merge(data_copy, n);
    save_results(output_filename, "Merge Sort", time_taken);

    // Heap Sort
    std::copy(data, data + n, data_copy);
    time_taken = measure_time_heap(data_copy, n);
    save_results(output_filename, "Heap Sort", time_taken);

    std::cout << "Results saved to " << output_filename << std::endl;
    return 0;
}
