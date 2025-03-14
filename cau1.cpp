#include <iostream>
#include <cmath>

#define MAX_SIZE 30000

int sum_of_digits(int n)
{
    int sum = 0;
    n = abs(n);
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int remove_primes(int arr[], int &n)
{
    int new_size = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!is_prime(arr[i]))
        {
            arr[new_size++] = arr[i];
        }
    }
    n = new_size;
    return n;
}

void sort_descending(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort_by_digit_sum(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (sum_of_digits(arr[i]) > sum_of_digits(arr[j]))
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void find_k_largest_elements(int arr[], int n, int k)
{
    sort_descending(arr, n);

    std::cout << "The " << k << " largest elements are:\n";
    for (int i = 0; i < k && i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[MAX_SIZE];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cout << "Enter k: ";
    std::cin >> k;
    find_k_largest_elements(arr, n, k);

    sort_by_digit_sum(arr, n);
    std::cout << "Array sorted by the sum of digits: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    remove_primes(arr, n);
    std::cout << "Array after removing prime numbers: ";
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
