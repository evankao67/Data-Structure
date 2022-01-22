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
