// RECURSION ON STRINGS
#include<iostream>
#include<string>
using namespace std;

// checking string palindrome
bool isPalin(string str, int start, int end) {
    // base case
    if(start >= end) return true;

    // condition for not palindrome to break the recursion
    if(str[start] != str[end]) return false;    

    // calling for next set to check/ for the inner string
    return isPalin(str, start+1, end-1);
}

// checking number of vowels in string using recursion
// Intuition: current index vowel or not + other string count
int countVowels(string str, int idx) {
    if(idx == str.size()) return 0;

    char alphabet = str[idx];
    string vowels = "aeiouAEIOU";
    
    return vowels.find(alphabet) != string::npos ? 1 + countVowels(str, idx+1): countVowels(str, idx+1);
}

// reverse a string
string reverseString(string str, int start, int end) {
    if(start>= end) return str;
    
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    return reverseString(str, start+1, end-1);
}

// converting to upper case using recursive function
void toUpperCase(string &str, int idx) {
    if(idx == -1) return;

    str[idx] = str[idx] - 'a' + 'A';

    return toUpperCase(str, idx-1);
}
int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    cout << "Palindrome: " << isPalin(str, 0, str.size()-1) << endl;

    cout << "Vowels: " << countVowels(str, 0) << endl;

    cout << "Reversed: " << reverseString(str, 0, str.size()-1) << endl;

    toUpperCase(str, str.size()-1);
    cout << "Upper Case: " << str << endl;

    return 0;
}