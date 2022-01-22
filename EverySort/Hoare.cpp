// C++ program for 3-way quick sort
#include <bits/stdc++.h>
#include <iomanip>
#include <ctime>
using namespace std;

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true) {
		while (a[++i] < v)
			;
		while (v < a[--j])
			if (j == l)
				break;
		if (i >= j)
			break;
		swap(a[i], a[j]);
		if (a[i] == v) {
			p++;
			swap(a[p], a[i]);
		}
		if (a[j] == v) {
			q--;
			swap(a[j], a[q]);
		}
	}
	swap(a[i], a[r]);
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);
}
void quicksort(int a[], int l, int r)
{
	if (r <= l)
		return;

	int i, j;

	// Note that i and j are passed as reference
	partition(a, l, r, i, j);

	// Recur
	quicksort(a, l, j);
	quicksort(a, i, r);
}

// A utility function to print an array
void printarr(int a[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

// Driver code
int main()
{
    srand(time(NULL));
    int count = 1;
    int times = 10;
    //sint arr[1<<21];
    while (times < 31)
    {
        double add = 0, duration;
        int *arr = new int[(1 << times) + 100]();
        cout<<"************"<<endl;
        cout<<"n=2^"<<times<<endl;
        while (count < 11)
        {
            for (int i = 0; i < 1 << times; i++)
            {
                arr[i] = rand() % 1000 + 1;
            }
            clock_t Begin, End;
            Begin = clock();
            quicksort(arr, 0, (1 << times) - 1);
            End = clock();
            duration = double(End - Begin) / CLOCKS_PER_SEC;
            cout << fixed << setprecision(6) << duration << endl;
            //printf("Sorted array: \n");
            //printArray(arr, 1023);
            count++;
            add += duration;
        }
        cout << fixed << setprecision(6) << add / 10 << endl;
        times++;
        count=1;
        delete[] arr;
    }
    return 0;
}


evan@gaoyuwens-MacBook-Air datastr % ls
a.out		dutch.cpp	hoare.cpp	skiplist.cpp	test.cpp
a.out.dSYM	hashtable.cpp	lomuto.cpp	sortedsrray.cpp	treap.cpp
dijkstra	heap.cpp	merge.cpp	test.c
evan@gaoyuwens-MacBook-Air datastr % cat hoare.cpp 
/* C++ implementation of QuickSort using Hoare's
partition scheme. */
#include <bits/stdc++.h>
#include <iomanip>
#include <ctime>
using namespace std;

/* This function takes first element as pivot, and places
all the elements smaller than the pivot on the left side
and all the elements greater than the pivot on
the right side. It returns the index of the last element
on the smaller side*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
		at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver Code
int main()
{
    srand(time(NULL));
    int count = 1;
    int times = 10;
    //sint arr[1<<21];
    while (times < 31)
    {
        double add = 0, duration;
        int *arr = new int[(1 << times) + 100]();
        cout<<"************"<<endl;
        cout<<"n=2^"<<times<<endl;
        while (count < 11)
        {
            for (int i = 0; i < 1 << times; i++)
            {
                arr[i] = rand() % 1000 + 1;
            }
            clock_t Begin, End;
            Begin = clock();
            quickSort(arr, 0, (1 << times) - 1);
            End = clock();
            duration = double(End - Begin) / CLOCKS_PER_SEC;
            cout << fixed << setprecision(6) << duration << endl;
            //printf("Sorted array: \n");
            //printArray(arr, 1023);
            count++;
            add += duration;
        }
        cout << fixed << setprecision(6) << add / 10 << endl;
        times++;
        count=1;
        delete[] arr;
    }
    return 0;
}
