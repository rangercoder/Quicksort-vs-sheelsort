#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <stdlib.h>

using namespace std;
int counter_quickSort = 0;
int counter_shellSort = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        counter_quickSort++;
        if (arr[j] < pivot)
        {
            counter_quickSort++;
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << endl;
    cout << endl;
}

int shellSort(int arr[], int s)
{
    for (int gap = s / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < s; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                counter_shellSort++;
            }
            arr[j] = temp;
        }
    }
    return 0;
}

void printArrayShell(int arr[], int s)
{
    for (int i = 0; i < s; i++)
        cout << arr[i] << endl;
}

int main()
{

    srand(time(NULL));
    freopen("quick_vs_shell.txt", "w", stdout);
    int compArr_ShellSort[100];
    int compArr_QuickSort[100];
    int ind ;
    double k = 20;

    while (k <= 1000){

    ind = 0;


        while (ind < 100)
        {
            int arr1[1000];
            int arr2[1000];
            for (int i = 0; i < 1000; i++)
            {
                int ran = rand();
                int maxr = RAND_MAX;
                float r = ran / float(maxr);
                int u;
                double p;
                double y;
                y = r * k;
                modf(y, &p);
                u = 1 + p;
                arr1[i] = u;
                arr2[i] = u;
            }
            // quicksort
            int n = sizeof(arr1) / sizeof(arr1[0]);
            counter_quickSort = 0;
            quickSort(arr1, 0, n - 1);
            compArr_QuickSort[ind] = counter_quickSort;
            // shellsort
            counter_shellSort = 0;
            shellSort(arr2, n);
            compArr_ShellSort[ind++] = counter_shellSort;
        }
        // for(int mu = 0 ; mu < 100 ; mu ++){
        //     cout <<compArr_ShellSort[mu]<<" "<<compArr_QuickSort[mu]<<endl;
        // }
        // to find mean

        int sum_Quick = 0;
        int sum_Shell = 0;
        for (int i = 0; i < 100; i++)
        {
            sum_Quick = sum_Quick + compArr_QuickSort[i];
            sum_Shell = sum_Shell + compArr_ShellSort[i];
        }

        // cout<< "The value of K for this calculation is "<<k<<endl<<endl ;        
        int Quick_mean;
        int Shell_mean;
        Quick_mean = (sum_Quick / 100);
        Shell_mean = (sum_Shell / 100);
        cout /*<< "The mean of Quick sort is " */<< Quick_mean << endl;
        cout /*<< "The mean of shell sort is " */<< Shell_mean << endl;
        // to find variance
        int Quick_variance;
        int Shell_variance;
        int sqDiff_quick = 0;
        int sqDiff_shell = 0;
        for (int i = 0; i < 100; i++)
        {
            sqDiff_quick += (compArr_QuickSort[i] - Quick_mean) * (compArr_QuickSort[i] - Quick_mean);
            sqDiff_shell += (compArr_ShellSort[i] - Shell_mean) * (compArr_ShellSort[i] - Shell_mean);
        }
        Quick_variance = sqDiff_quick / 100; // to ask sir  which variance formula to use
        Shell_variance = sqDiff_shell / 100;
        // cout << "quicksort variance is " << Quick_variance << endl
            //  << "shell sort variance is " << Shell_variance << endl;
        // to find standard deviation
        float standard_quick;
        float standard_shell;
        standard_quick = sqrt(Quick_variance);
        standard_shell = sqrt(Shell_variance);

        // cout << "The standard deviation of quick sort is " << standard_quick << endl;
        // cout << "The standard deviation of shell sort is " << standard_shell << endl<<endl;



        k+=20;
    }

    return 0;
}
