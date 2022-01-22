#include <bits/stdc++.h>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void search(int arr[], int target)
{
    int i=0;
    while(target>arr[i])
    {
        i++;
    }
    return;
}
/* Driver code */
int main()
{
    int set = 10;
    while (set < 31)
    {
        int *arr = new int[(1 << set) + 100]();
        for (int i = 0; i < 1 << set; i++)
        {
            arr[i]=rand()%(1<<31);
            insertionSort(arr, i);
        }
        clock_t Begin, End;
        Begin = clock();
        for(int i=0;i<100000;i++)
        {
            search(arr, rand()%(1<<31));
        }
        End = clock();
        double duration = double(End - Begin) / CLOCKS_PER_SEC;
        cout << fixed << setprecision(6) << duration << endl;
        set++;
        delete [] arr;
    }
    return 0;
}
