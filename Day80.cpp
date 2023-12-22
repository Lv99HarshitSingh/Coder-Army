// Linear search and binary search using recursion
#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int idx, int target) {
    if(idx == size) return -1;
    if(arr[idx] == target) return idx;
    return linearSearch(arr, size, idx+1, target);
}

int binarySearch(int arr[], int target, int start, int end) {
    // Base case
    if(start>end) return -1;

    int mid = start + (end-start)/2;
    if(arr[mid] == target) return mid;

    if(arr[mid] < target) {
        binarySearch(arr, target, mid+1, end);
    }
    else {
        binarySearch(arr, target, start, mid-1);
    }

}
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(arr)/sizeof(int);
    int target ;
    cout << "Enter the target to be searched: ";
    cin >> target;

    cout << linearSearch(arr, length, 0, target) << endl;

    cout << binarySearch(arr, target, 0, length-1) << endl;

    return 0;
}