#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given two strings s and t, return true if they are anagrams of each other.

Approach:
Count the frequency of characters in both strings and compare them.

Thought Process:
Anagrams contain the same characters with the same counts.

Algorithm:
1. If lengths differ, return false.
2. Use a frequency array of size 26.
3. Increment counts for characters in s and decrement for t.
4. If all counts are zero, the strings are anagrams.

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    vector<int> freq(26, 0);
    for (int i = 0; i < (int)s.size(); ++i)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int x : freq)
        if (x != 0)
            return false;
    return true;
}

int main()
{
    cout << isAnagram("anagram", "nagaram") << "\n";
    cout << isAnagram("rat", "car") << "\n";
    return 0;
}
