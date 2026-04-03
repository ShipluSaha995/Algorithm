/*
Quick sort is a divide and conqure algorithm that picks a pivot element partitions the array
so element<=pivot go left and element>pivot go right and recursively sorts the left and right
*/

#include <bits/stdc++.h>
using namespace std;

int partitions(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
    
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pi=partitions(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quicksort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}