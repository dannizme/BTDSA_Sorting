#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
            swap(arr[min], arr[i]);
    }
}

void printArrar(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {39, 5, 8, 1, 3, 6, 9, 12, 4, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printArrar(arr, n);
    return 0;
}