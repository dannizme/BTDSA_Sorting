#include <iostream>
#include <cmath>

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

int findTheLargestPrime(int arr[][100], int m, int n)
{
    int largest = -1;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isPrime(arr[i][j]) && arr[i][j] > largest)
            {
                largest = arr[i][j];
            }
        }
    }
    return largest;
}

void findRowsWithPrime(int arr[][100], int m, int n)
{
    int marked[100] = {0};
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isPrime(arr[i][j]))
            {
                marked[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        if (marked[i] == 1)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}

void findRowsWithOnlyPrime(int arr[][100], int m, int n)
{
    int marked[100] = {0};

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!isPrime(arr[i][j]))
            {
                marked[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        if (marked[i] == 0)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}

int main()
{
    int arr[4][100] = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10},
        {11, 13, 17}};

    int largestPrime = findTheLargestPrime(arr, 4, 3);
    std::cout << "The largest prime in the matrix: " << largestPrime << "\n";

    std::cout << "Rows with prime number: \n";
    findRowsWithPrime(arr, 4, 3);

    std::cout << "Rows with only prime number: \n";
    findRowsWithOnlyPrime(arr, 4, 3);

    return 0;
}