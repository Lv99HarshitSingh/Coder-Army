// #include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

// print array in naive recursivce form
void printArray(int arr[], int n, int idx) {
    if(idx==n) return;

    cout << arr[idx] << " ";
    printArray(arr, n, idx+1);
}
// for reverse print recursivce function should be called first before printing

// its same recursive function without size, here we go recursively backwards from the last element
void printArray_noSize(int arr[], int idx) {
    if(idx<0) return;

    printArray_noSize(arr, idx-1);
    cout << arr[idx] << " ";
}


// again same as above but we have to return the sum of the elements
// Intuition is that: we have to calculate for 1 case and rest believe in recursion for other cases
// sum till current index is current sum + sum of elements in front
int sumOfArray(int arr[], int idx, int n) {
    if(idx == n) return 0;
    return arr[idx] + sumOfArray(arr, idx+1, n);
}


// it compares current index and min from the remaining array 
int minElement(int arr[], int idx, int n) {
    // Base Case
    if(idx == n-1) return arr[idx];

    return min(arr[idx], minElement(arr, idx+1, n));
}


// Homework Problems
// 1: Find the Maximum element in a given array of size N.
// 2: Find the Product of all elements in a given array of size N.
// 3: Find the Number of even elements in a given array of size N.


int maxElement(int arr[], int idx, int n) {
    if(idx == n-1) return arr[idx];

    return max(arr[idx], maxElement(arr, idx+1, n));
}

int productOfArray(int arr[], int idx, int n) {
    if(idx == n) return 1;

    return arr[idx] * productOfArray(arr, idx+1, n);
}

int evenCount(int arr[], int n, int idx) {
    if(idx == n) return 0;

    if( arr[idx]%2  == 0 ) return evenCount(arr, n, idx+1) + 1;
    else return evenCount(arr, n, idx+1);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int length = sizeof(arr)/sizeof(int);
    printArray(arr, length, 0);
    cout << endl;
    printArray_noSize(arr, length-1);
    cout << endl;

    cout << sumOfArray(arr, 0, length) << endl;

    cout << minElement(arr, 0, length) << endl;

    cout << maxElement(arr, 0, length) << endl;

    cout << productOfArray(arr, 0, length) << endl;

    cout << evenCount(arr, length, 0) << endl;

    return 0;
}