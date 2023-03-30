#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef chrono::milliseconds MSEC;
typedef chrono::high_resolution_clock HRC;

int partition(int arr[], int start, int stop)
{
    int pivot = arr[stop];
    int i = start - 1;

    for (int j = start; j <= stop - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[stop];
    arr[stop] = temp;
    return i;
}

void iterativeQuickSort(int arr[], int start, int stop)
{

    int stack[stop - start + 1];
    int topItem = -1;
    stack[++topItem] = start;
    stack[++topItem] = stop;

    for(int i = 0; topItem >=0; i++){
        stop = stack[topItem--];
        start = stack[topItem--];
        int pivot = partition(arr,start,stop);
        if (pivot - 1 > start) {
            stack[++topItem] = start;
            stack[++topItem] = pivot - 1;
        }
        if (pivot + 1 < stop) {
            stack[++topItem] = pivot + 1;
            stack[++topItem] = stop;
        }
    }
}

int main()
{
    srand(time(NULL));
    auto start = HRC::now();
    int a[25000] = {};
    for(int i = 0; i < 1000; i++){
       a[i] = rand() % 100;
    }
    int n = sizeof(a)/sizeof(a[0]);
    iterativeQuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    auto end = HRC::now();
    auto exec_time = chrono::duration_cast<MSEC>(end-start);
    cout << "Execution time = "<<exec_time.count()<<" miliseconds"<<endl;
    return 0;
}
