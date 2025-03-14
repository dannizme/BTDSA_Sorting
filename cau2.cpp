#include <iostream>

struct Term
{
    float coeff;
    int degree;
};

void swap(Term &a, Term &b)
{
    Term temp = {0, 0};
    temp.degree = a.degree;
    a.degree = b.degree;
    b.degree = temp.degree;
}

void selectionSort(Term arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[min].degree > arr[j].degree)
            {
                min = j;
            }
        }
        if (min != i)
            swap(arr[min], arr[i]);
    }
}

void display_terms(Term arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Coefficient: " << arr[i].coeff << ", Degree: " << arr[i].degree << "\n";
    }
}

int main()
{
    Term terms[] = {{3.2, 5}, {1.5, 2}, {4.7, 8}, {2.1, 1}, {0.5, 7}};
    int n = sizeof(terms) / sizeof(terms[0]);

    std::cout << "Before sorting:" << "\n";
    display_terms(terms, n);

    selectionSort(terms, n);

    std::cout << "\nAfter sorting:" << "n\n";
    display_terms(terms, n);

    return 0;
}