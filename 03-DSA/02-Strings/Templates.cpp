// ============================================================
// 02 - STRINGS : ALL PATTERN TEMPLATES (C++)
// Copy-paste ready. Each block is self-contained.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// 1. TWO POINTERS (PALINDROME / REVERSAL)
// ------------------------------------------------------------
bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}

bool isPalindromeAlnum(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

bool validSub(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; right--;
    }
    return true;
}
bool validPalindromeII(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right])
            return validSub(s, left + 1, right) || validSub(s, left, right - 1);
        left++; right--;
    }
    return true;
}

// ------------------------------------------------------------
// 2. SLIDING WINDOW (SUBSTRING PROBLEMS)
// ------------------------------------------------------------
int lengthOfLongestSubstring(string s) {
    vector<int> lastSeen(256, -1);
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (lastSeen[s[right]] >= left) left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

string minWindow(string s, string t) {
    vector<int> need(128, 0);
    for (char c : t) need[c]++;
    int required = t.size();
    int left = 0, bestLen = INT_MAX, bestStart = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (need[s[right]]-- > 0) required--;
        while (required == 0) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
            if (++need[s[left]] > 0) required++;
            left++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> need(26, 0), window(26, 0);
    for (char c : s1) need[c - 'a']++;
    int k = s1.size();
    for (int i = 0; i < (int)s2.size(); i++) {
        window[s2[i] - 'a']++;
        if (i >= k) window[s2[i - k] - 'a']--;
        if (i >= k - 1 && window == need) return true;
    }
    return false;
}

// ------------------------------------------------------------
// 3. HASHING - FREQUENCY COUNTING FOR STRINGS
// ------------------------------------------------------------
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;
    for (int c : count) if (c != 0) return false;
    return true;
}

int firstUniqChar(string s) {
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    for (int i = 0; i < (int)s.size(); i++)
        if (freq[s[i] - 'a'] == 1) return i;
    return -1;
}

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> mapST, mapTS;
    for (int i = 0; i < (int)s.size(); i++) {
        char a = s[i], b = t[i];
        if (mapST.count(a) && mapST[a] != b) return false;
        if (mapTS.count(b) && mapTS[b] != a) return false;
        mapST[a] = b;
        mapTS[b] = a;
    }
    return true;
}

// ------------------------------------------------------------
// 4. EXPAND AROUND CENTER (PALINDROMIC SUBSTRINGS)
// ------------------------------------------------------------
pair<int,int> expandFromCenter(const string& s, int left, int right) {
    while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
        left--; right++;
    }
    return {left + 1, right - 1};
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1;
    for (int i = 0; i < (int)s.size(); i++) {
        auto [l1, r1] = expandFromCenter(s, i, i);
        auto [l2, r2] = expandFromCenter(s, i, i + 1);
        if (r1 - l1 + 1 > maxLen) { start = l1; maxLen = r1 - l1 + 1; }
        if (r2 - l2 + 1 > maxLen) { start = l2; maxLen = r2 - l2 + 1; }
    }
    return s.substr(start, maxLen);
}

int countSubstrings(string s) {
    int n = s.size(), count = 0;
    for (int center = 0; center < 2 * n - 1; center++) {
        int left = center / 2, right = left + center % 2;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++; left--; right++;
        }
    }
    return count;
}

// ------------------------------------------------------------
// 5. MANACHER'S ALGORITHM (O(n) LONGEST PALINDROMIC SUBSTRING)
// ------------------------------------------------------------
string longestPalindromeManacher(string s) {
    string t = "^";
    for (char c : s) { t += '#'; t += c; }
    t += "#$";
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 1; i < n - 1; i++) {
        if (i < right) p[i] = min(right - i, p[2 * center - i]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (i + p[i] > right) { center = i; right = i + p[i]; }
    }
    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) { maxLen = p[i]; centerIndex = i; }
    }
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

// ------------------------------------------------------------
// 6. KMP ALGORITHM (PATTERN MATCHING)
// ------------------------------------------------------------
vector<int> computeLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> result;
    if (pattern.empty()) return result;
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    int n = text.size(), m = pattern.size();
    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j > 0) j = lps[j - 1];
            else i++;
        }
    }
    return result;
}

// ------------------------------------------------------------
// 7. RABIN-KARP (ROLLING HASH PATTERN MATCHING)
// ------------------------------------------------------------
vector<int> rabinKarp(const string& text, const string& pattern) {
    const int base = 256, mod = 1e9 + 7;
    int n = text.size(), m = pattern.size();
    vector<int> result;
    if (m > n) return result;

    long long patternHash = 0, windowHash = 0, h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        windowHash = (windowHash * base + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == windowHash) {
            if (text.substr(i, m) == pattern)
                result.push_back(i);
        }
        if (i < n - m) {
            windowHash = (base * (windowHash - text[i] * h) + text[i + m]) % mod;
            if (windowHash < 0) windowHash += mod;
        }
    }
    return result;
}

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> freq;
    vector<string> result;
    for (int i = 0; i + 10 <= (int)s.size(); i++) {
        string sub = s.substr(i, 10);
        if (++freq[sub] == 2) result.push_back(sub);
    }
    return result;
}

// ------------------------------------------------------------
// 8. Z-FUNCTION (STRING MATCHING)
// ------------------------------------------------------------
vector<int> zFunction(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

vector<int> findOccurrences(const string& text, const string& pattern) {
    string combined = pattern + "#" + text;
    vector<int> z = zFunction(combined);
    vector<int> result;
    int m = pattern.size();
    for (int i = m + 1; i < (int)combined.size(); i++) {
        if (z[i] == m) result.push_back(i - m - 1);
    }
    return result;
}

// ------------------------------------------------------------
// 9. TRIE (PREFIX TREE)
// ------------------------------------------------------------
class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

// ------------------------------------------------------------
// 10. BACKTRACKING ON STRINGS
// ------------------------------------------------------------
void permute(string& s, int idx, vector<string>& result) {
    if (idx == (int)s.size()) { result.push_back(s); return; }
    for (int i = idx; i < (int)s.size(); i++) {
        swap(s[idx], s[i]);
        permute(s, idx + 1, result);
        swap(s[idx], s[i]);
    }
}

void generateHelper(int open, int close, int n, string& current, vector<string>& result) {
    if ((int)current.size() == 2 * n) { result.push_back(current); return; }
    if (open < n) {
        current.push_back('(');
        generateHelper(open + 1, close, n, current, result);
        current.pop_back();
    }
    if (close < open) {
        current.push_back(')');
        generateHelper(open, close + 1, n, current, result);
        current.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    generateHelper(0, 0, n, current, result);
    return result;
}

bool isPalindromeRange(const string& s, int i, int j) {
    while (i < j) if (s[i++] != s[j--]) return false;
    return true;
}
void partitionHelper(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
    if (start == (int)s.size()) { result.push_back(path); return; }
    for (int end = start; end < (int)s.size(); end++) {
        if (isPalindromeRange(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, path, result);
            path.pop_back();
        }
    }
}

// ============================================================
// END OF TEMPLATES
// ============================================================