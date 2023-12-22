// Merge Sort
// Quick Sort 
#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    vector<int> finalAns(end-start+1);

    int i=start, j=mid+1, k=0;

    while(i<=mid && j<=end) {
        if(arr[i] < arr[j]) {
            finalAns[k++] = arr[i++];
        }else {
            finalAns[k++] = arr[j++];
        }
    } 

    while(i<=mid) finalAns[k++]=arr[i++];
    while(j<=end) finalAns[k++]=arr[j++];

    // final merging into original arr
    k=0;
    while(start <= end)arr[start++]=finalAns[k++];
}

void mergeSort(int arr[], int start, int end) {
    // base case
    if(start == end) return;

    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}
 
int main() {

    int arr[] = {6,5,4,7,3,2,9,1,10,8};
    int length = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, length-1);

    for(int i=0; i<length; i++)
        cout << arr[i] << " ";
    return 0;
}
