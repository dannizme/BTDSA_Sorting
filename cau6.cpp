#include <iostream>

using namespace std;

void selectionSortEvens(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] != 0 && arr[i] % 2 == 0)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] != 0 && arr[j] % 2 == 0 && arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void selectionSortOdds(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] != 0 && arr[i] % 2 != 0)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] != 0 && arr[j] % 2 != 0 && arr[i] < arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
}

void sortArray(int arr[], int n)
{
    selectionSortEvens(arr, n);
    selectionSortOdds(arr, n);
}

int main()
{
    int arr[] = {10, 3, 0, 5, 8, 6, 0, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sortArray(arr, n);

    cout << "Array after sorting evens in ascending order and odds in descending order:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
