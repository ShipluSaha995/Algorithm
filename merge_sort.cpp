/*
Merge sort is a divide and conqure sorting algorithm that splits an array in half 
recursively sorts each half then merge them back together in sorted array
*/

#include <bits/stdc++.h>
using namespace std;

void mergearray(vector<int>&arr, int left, int mid, int right){
    vector<int>temp;

    int i=left;
    int j=mid+1;

    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=right){
        temp.push_back(arr[j]);
        j++;
    }

    for(int k=0; k<temp.size(); k++){
        arr[left+k]=temp[k];
    }

}

void mergesort(vector<int>&arr, int left, int right){
    if(left>=right){
        return ;
    }

    int mid=left+(right-left)/2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    mergearray(arr, left, mid, right);
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    mergesort(arr, 0, n-1);
    for(int x:arr){
        cout<<x<<" ";
    }

    return 0;
}