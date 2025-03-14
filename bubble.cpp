#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n)
{
    int up = 0, down = n - 1;
    while (up < down)
    {
        for (int i = up; i < down; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        down--;
        for (int i = down; i > up; i--)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
            }
        }
        up++;
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
    bubbleSort(arr, n);
    printArrar(arr, n);
    return 0;
}