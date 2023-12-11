#include<iostream>
using namespace std;

// Fibonacci Number 0 1 1 2 3 5 8 13 21 ...
// recursive solution 
int fib(int n) {
    if(n<=1) return n;

    return fib(n-1) + fib(n-2);
}

// iterative
int fib_iterative(int n) {
    
}

// nth stair when 1,2 steps can be taken
// Recursion method
int nthStair(int n) {
    if(n <= 2) return n;

    return nthStair(n-1) + nthStair(n-2);
}

int nthStair_Iterative(int n) {
    int ans = 0;
    int finalAns = 1;
    for(int i=1; i<=n; i++) {
        int temp = finalAns;
        finalAns += ans;
        ans = temp;
    }

    return finalAns;
}


int gcd(int a, int b) {
    if(b == 0) return a;

    return gcd(b, a%b);
}

int main() {

    // nth stair
    // int n;
    // cout<<"Enter the number of stairs: ";
    // cin>>n;

    // cout << nthStair(n) << endl;
    // cout << nthStair_Iterative(n) << endl;


    // GCD calculation
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    cout<<gcd(a,b);
}