#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Interchange Sort (Traditional Bubble Sort)
void interchangeSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n, int &comparisons, int &swaps)
{
    int up = 0, down = n - 1;
    while (up < down)
    {
        for (int i = up; i < down; i++)
        {
            comparisons++;
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swaps++;
            }
        }
        down--;
        for (int i = down; i > up; i--)
        {
            comparisons++;
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swaps++;
            }
        }
        up++;
    }
}

// Shaker Sort (Cocktail Sort)
void shakerSort(int arr[], int n, int &comparisons, int &swaps)
{
    int up = 0, down = n - 1;
    while (up < down)
    {
        for (int i = up; i < down; i++)
        {
            comparisons++;
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swaps++;
            }
        }
        down--;
        for (int i = down; i > up; i--)
        {
            comparisons++;
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i - 1], arr[i]);
                swaps++;
            }
        }
        up++;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n, int &comparisons, int &assignments)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        comparisons++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            assignments++;
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
        assignments++;
    }
}

// Binary Insertion Sort
void binaryInsertionSort(int arr[], int n, int &comparisons, int &assignments)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            comparisons++;
            int mid = left + (right - left) / 2;
            if (arr[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        for (int j = i - 1; j >= left; j--)
        {
            arr[j + 1] = arr[j];
            assignments++;
        }
        arr[left] = key;
        assignments++;
    }
}

// Selection Sort
void selectionSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }
}

// Shell Sort
void shellSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            comparisons++;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                swaps++;
                j -= gap;
                comparisons++;
            }
            arr[j] = temp;
        }
    }
}

// Heap Sort
void heapify(int arr[], int n, int i, int &comparisons, int &swaps)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    comparisons++;
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    comparisons++;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        swaps++;
        heapify(arr, n, largest, comparisons, swaps);
    }
}

void heapSort(int arr[], int n, int &comparisons, int &swaps)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, comparisons, swaps);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        swaps++;
        heapify(arr, i, 0, comparisons, swaps);
    }
}

// Quick Sort
int partition(int arr[], int low, int high, int &comparisons, int &swaps)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int &comparisons, int &swaps)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right, int &comparisons, int &swaps)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        swaps++;
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        swaps++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
}

void mergeSort(int arr[], int left, int right, int &comparisons, int &swaps)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}

// Generate random array
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000; // Random number between 0 and 9999
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation

    int n_values[] = {10, 100, 200, 500, 1000, 2000, 5000, 10000};
    int num_trials = 10;

    for (int i = 0; i < 8; i++)
    {
        int n = n_values[i];
        cout << "For n = " << n << ":\n";

        int total_comparisons_interchange = 0, total_swaps_interchange = 0;
        int total_comparisons_bubble = 0, total_swaps_bubble = 0;
        int total_comparisons_shaker = 0, total_swaps_shaker = 0;
        int total_comparisons_insertion = 0, total_assignments_insertion = 0;
        int total_comparisons_binary_insertion = 0, total_assignments_binary_insertion = 0;
        int total_comparisons_selection = 0, total_swaps_selection = 0;
        int total_comparisons_shell = 0, total_swaps_shell = 0;
        int total_comparisons_heap = 0, total_swaps_heap = 0;
        int total_comparisons_quick = 0, total_swaps_quick = 0;
        int total_comparisons_merge = 0, total_swaps_merge = 0;

        for (int j = 0; j < num_trials; j++)
        {
            int arr_interchange[n], arr_bubble[n], arr_shaker[n], arr_insertion[n], arr_binary_insertion[n], arr_selection[n], arr_shell[n], arr_heap[n], arr_quick[n], arr_merge[n];

            // Generate random arrays for each sorting algorithm
            generateRandomArray(arr_interchange, n);
            generateRandomArray(arr_bubble, n);
            generateRandomArray(arr_shaker, n);
            generateRandomArray(arr_insertion, n);
            generateRandomArray(arr_binary_insertion, n);
            generateRandomArray(arr_selection, n);
            generateRandomArray(arr_shell, n);
            generateRandomArray(arr_heap, n);
            generateRandomArray(arr_quick, n);
            generateRandomArray(arr_merge, n);

            // Interchange Sort
            int comparisons = 0, swaps = 0;
            interchangeSort(arr_interchange, n, comparisons, swaps);
            total_comparisons_interchange += comparisons;
            total_swaps_interchange += swaps;

            // Bubble Sort
            comparisons = 0;
            swaps = 0;
            bubbleSort(arr_bubble, n, comparisons, swaps);
            total_comparisons_bubble += comparisons;
            total_swaps_bubble += swaps;

            // Shaker Sort
            comparisons = 0;
            swaps = 0;
            shakerSort(arr_shaker, n, comparisons, swaps);
            total_comparisons_shaker += comparisons;
            total_swaps_shaker += swaps;

            // Insertion Sort
            comparisons = 0;
            swaps = 0;
            insertionSort(arr_insertion, n, comparisons, swaps);
            total_comparisons_insertion += comparisons;
            total_assignments_insertion += swaps;

            // Binary Insertion Sort
            comparisons = 0;
            swaps = 0;
            binaryInsertionSort(arr_binary_insertion, n, comparisons, swaps);
            total_comparisons_binary_insertion += comparisons;
            total_assignments_binary_insertion += swaps;

            // Selection Sort
            comparisons = 0;
            swaps = 0;
            selectionSort(arr_selection, n, comparisons, swaps);
            total_comparisons_selection += comparisons;
            total_swaps_selection += swaps;

            // Shell Sort
            comparisons = 0;
            swaps = 0;
            shellSort(arr_shell, n, comparisons, swaps);
            total_comparisons_shell += comparisons;
            total_swaps_shell += swaps;

            // Heap Sort
            comparisons = 0;
            swaps = 0;
            heapSort(arr_heap, n, comparisons, swaps);
            total_comparisons_heap += comparisons;
            total_swaps_heap += swaps;

            // Quick Sort
            comparisons = 0;
            swaps = 0;
            quickSort(arr_quick, 0, n - 1, comparisons, swaps);
            total_comparisons_quick += comparisons;
            total_swaps_quick += swaps;

            // Merge Sort
            comparisons = 0;
            swaps = 0;
            mergeSort(arr_merge, 0, n - 1, comparisons, swaps);
            total_comparisons_merge += comparisons;
            total_swaps_merge += swaps;
        }

        // Print the results for each sorting algorithm
        cout << "Interchange Sort\t - Comparisons: " << total_comparisons_interchange / num_trials
             << ", Swaps: " << total_swaps_interchange / num_trials << endl;
        cout << "Bubble Sort\t\t - Comparisons: " << total_comparisons_bubble / num_trials
             << ", Swaps: " << total_swaps_bubble / num_trials << endl;
        cout << "Shaker Sort\t\t - Comparisons: " << total_comparisons_shaker / num_trials
             << ", Swaps: " << total_swaps_shaker / num_trials << endl;
        cout << "Insertion Sort\t\t - Comparisons: " << total_comparisons_insertion / num_trials
             << ", Assignments: " << total_assignments_insertion / num_trials << endl;
        cout << "Binary Insertion Sort\t - Comparisons: " << total_comparisons_binary_insertion / num_trials
             << ", Assignments: " << total_assignments_binary_insertion / num_trials << endl;
        cout << "Selection Sort\t\t - Comparisons: " << total_comparisons_selection / num_trials
             << ", Swaps: " << total_swaps_selection / num_trials << endl;
        cout << "Shell Sort\t\t - Comparisons: " << total_comparisons_shell / num_trials
             << ", Swaps: " << total_swaps_shell / num_trials << endl;
        cout << "Heap Sort\t\t - Comparisons: " << total_comparisons_heap / num_trials
             << ", Swaps: " << total_swaps_heap / num_trials << endl;
        cout << "Quick Sort\t\t - Comparisons: " << total_comparisons_quick / num_trials
             << ", Swaps: " << total_swaps_quick / num_trials << endl;
        cout << "Merge Sort\t\t - Comparisons: " << total_comparisons_merge / num_trials
             << ", Swaps: " << total_swaps_merge / num_trials << endl;
        cout << "\n";
    }

    return 0;
}
