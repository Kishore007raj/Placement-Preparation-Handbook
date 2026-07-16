#include <bits/stdc++.h>
using namespace std;

// Reverse a string
string reverseString(string s)
{
    int l = 0, r = (int)s.size() - 1;
    while (l < r)
        swap(s[l++], s[r--]);
    return s;
}

// Check palindrome
bool isPalindrome(string s)
{
    int l = 0, r = (int)s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

// Count frequency of characters
vector<int> frequencyMap(const string &s)
{
    vector<int> freq(26, 0);
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
            freq[c - 'a']++;
    }
    return freq;
}

int main()
{
    string s = "racecar";
    cout << reverseString(s) << "\n";
    cout << isPalindrome(s) << "\n";
    return 0;
}
