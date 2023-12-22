// Recursion on Subsequences

#include<iostream>
#include<vector>
using namespace std;

void returnSubsequences(int arr[], int idx, int size, vector<int> &seq, vector<vector<int>> &sequences) {
    // base case
    if(idx==size) {
        sequences.push_back(seq);
        return;
    }

    // case when we have to add
    seq.push_back(arr[idx]);
    returnSubsequences(arr, idx+1, size, seq, sequences);

    // case when we don't have to add the digit
    seq.pop_back();
    returnSubsequences(arr, idx+1, size, seq, sequences);

}


// find number of valid parenthesis
void ValidParenthesis(int n, int left, int right, string &ans) {
    if(left==0 && right==0) {
        cout << ans << endl;
        return;
    }

    if(left == right) {
        ans.push_back('(');
        ValidParenthesis(n, left-1, right, ans);
        ans.pop_back();
    }else {
        if(left>0) {
            ans.push_back('(');
            ValidParenthesis(n, left-1, right, ans);
            ans.pop_back();
        }
        if(right>0) {
            ans.push_back(')');
            ValidParenthesis(n, left, right-1, ans);
            ans.pop_back();
        }
    }
}
int main() {

    int arr[] = {1,2,3};
    int length = sizeof(arr)/sizeof(int);
    vector<int>seq;
    vector<vector<int>> sequences;
    returnSubsequences(arr, 0, length, seq, sequences);

    for(int i=0; i<sequences.size(); i++) {
        for(int j=0; j<sequences[i].size(); j++) {
            cout << sequences[i][j] << " ";
        }
        cout << endl;
    }

    string parenthesis = "";
    int n = 4;
    ValidParenthesis(n, n, n, parenthesis);
    return 0;
}