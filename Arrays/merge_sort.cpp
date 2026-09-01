#include <iostream>
using namespace std;

void merge(int arr[], int l, int u, int mid, int b[]);

void mergesort(int arr[], int l, int u, int b[])
{
    if(l < u)
    {
        int mid = (l + u) / 2;
        mergesort(arr, l, mid, b);
        mergesort(arr, mid + 1, u, b);
        merge(arr, l, u, mid, b);
    }
}

void merge(int arr[], int l, int u, int mid, int b[])
{
    int i = l;
    int j = mid + 1;
    int k = l;

    while(i <= mid && j <= u)
    {
        if(arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while(j <= u)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for(int p = l; p <= u; p++)
    {
        arr[p] = b[p];
    }
}

int main()
{
    int n;
    cout << "Enter no.of elements:";
    cin >> n;

    int *arr = new int[n];
    int *b = new int[n];

    cout << "Fill the array:" << endl;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1, b);

    cout << "After sorting:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    delete[] arr;
    delete[] b;
}