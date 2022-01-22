#include <bits/stdc++.h>
#include <iomanip>
#include <ctime>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/
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
        cout << "************" << endl;
        cout << "n=2^" << times << endl;
        while (count < 11)
        {
            for (int i = 0; i < 1 << times; i++)
            {
                arr[i] = rand() % 1000000 + 1;
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
        count = 1;
        delete[] arr;
    }
    return 0;
}
