#include <iostream>
#include <string>

struct Room
{
    int number;
    char house;
    int storageCap;
};

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void selectionSort(T arr[], int n, bool (*cmp)(T, T))
{
    for (int i = 0; i < n - 1; ++i)
    {
        int key = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (cmp(arr[key], arr[j]))
            {
                key = j;
            }
        }
        if (key != i)
        {
            Swap(arr[key], arr[i]);
        }
    }
}

bool cmpByHouseAndNumber(Room a, Room b)
{
    if (a.house == b.house)
    {
        return a.number > b.number;
    }
    return a.house > b.house;
}

bool cmpByHouseAndStorageCap(Room a, Room b)
{
    if (a.house == b.house)
    {
        return a.storageCap < b.storageCap;
    }
    return a.house > b.house;
}

bool cmpByStorageCap(Room a, Room b)
{
    return a.storageCap > b.storageCap;
}

void displayRooms(Room arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Room " << arr[i].number << " - " << arr[i].house << " - " << arr[i].storageCap << "\n";
    }
}

int main()
{
    Room rooms[] = {
        {101, 'A', 50},
        {102, 'B', 40},
        {103, 'C', 60},
        {104, 'D', 30},
        {105, 'A', 30},
        {106, 'A', 60}};

    int n = sizeof(rooms) / sizeof(rooms[0]);

    std::cout << "Original Rooms: " << std::endl;
    displayRooms(rooms, n);

    selectionSort(rooms, n, cmpByStorageCap);
    std::cout << "\nSorted by storageCap: " << std::endl;
    displayRooms(rooms, n);

    selectionSort(rooms, n, cmpByHouseAndNumber);
    std::cout << "\nSorted by House, after Number: " << std::endl;
    displayRooms(rooms, n);

    selectionSort(rooms, n, cmpByHouseAndStorageCap);
    std::cout << "\nSorted by House, after StorageCap: " << std::endl;
    displayRooms(rooms, n);

    return 0;
}
