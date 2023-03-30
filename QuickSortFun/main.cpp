#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef chrono::milliseconds MSEC;
typedef chrono::high_resolution_clock HRC;

int partition (int arr[], int start, int stop){
    int pivot = arr[stop];
    int i = start - 1;
    for (int j = start; j <= stop - 1; j++){
        if (arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp2 = arr[i];
    arr[i] = arr[stop];
    arr[stop] = temp2;
    return i;
}

void quickSort(int arr[], int start, int stop){
    if (start < stop){
        int pivot = partition(arr,start,stop);
        quickSort(arr,start, pivot - 1);
        quickSort(arr, pivot + 1, stop);}
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
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    auto end = HRC::now();
    auto exec_time = chrono::duration_cast<MSEC>(end-start);
    cout << "Execution time = "<<exec_time.count()<<" miliseconds"<<endl;
    return 0;

}
