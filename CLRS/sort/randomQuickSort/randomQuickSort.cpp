#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int A[], int l, int r)
{
    int pivot = A[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (A[j] <= pivot)
        {
            i += 1;
            swap(A[j], A[i]);
        }
    }
    swap(A[r], A[++i]);
    return i;
}

int randomPartition(int A[], int l, int r)
{
    int i = rand() % (r - l + 1) + l;
    swap(A[i], A[r]);
    return partition(A, l, r);
}

void randomQuickSort(int A[], int l, int r)
{
    if (l >= r)
        return;
    int p = randomPartition(A, l, r);
    randomQuickSort(A, l, p-1);
    randomQuickSort(A, p+1, r);
}

int main()
{
    int a[10] = {8,9,6,4,2,0,1,3,5,7};
    randomQuickSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
        cout<<a[i]<<" ";
    return 0;
}