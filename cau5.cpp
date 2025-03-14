#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    int k = sqrt(n);
    for (int i = 2; i <= k; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int sumOfRow(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

void findLargestSumofRow(int arr[][100], int m, int n)
{
    int largest = -1;
    int index = -1;
    for (int i = 0; i < m; ++i)
    {
        int sum = sumOfRow(arr[i], n);
        if (sum > largest)
        {
            largest = sum;
            index = i;
        }
    }

    std::cout << "Row " << index + 1 << " has the largest sum of " << largest << std::endl;
}

void sortBySumOfRow(int arr[][100], int m, int n)
{
    for (int i = 0; i < m - 1; ++i)
    {
        int maxIndex = i;
        for (int j = i + 1; j < m; ++j)
        {
            if (sumOfRow(arr[j], n) > sumOfRow(arr[maxIndex], n))
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            for (int k = 0; k < n; ++k)
            {
                swap(arr[i][k], arr[maxIndex][k]);
            }
        }
    }

    std::cout << "Matrix after sorting rows by sum (in descending order):\n";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    int arr[5][100] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};

    findLargestSumofRow(arr, 5, 4);
    sortBySumOfRow(arr, 5, 4);

    return 0;
}
