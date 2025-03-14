#include <iostream>
using namespace std;

void sortEvenOdd(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        while (left < n && arr[left] % 2 == 0)
        {
            left++;
        }
        while (right >= 0 && arr[right] % 2 != 0)
        {
            right--;
        }

        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
}

int main()
{
    int arr[] = {3, 1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortEvenOdd(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
