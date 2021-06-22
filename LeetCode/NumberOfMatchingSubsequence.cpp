// Number of Matching Subsequences


// Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) 
// deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".

class Solution {
    int isSubSeq(string& a, string b) {
        
        int i = 0, j = 0;
        int m = a.length(), n = b.length();
        
        while (i < m && j < n) {
            if (a[i] == b[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        
        return (j == n);
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        
        int c = 0;
        unordered_map<string, int>mp;
        for (int i = 0; i < words.size(); i++)
            mp[words[i]]++;
            
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (isSubSeq(S, it->first))
                c += it->second;
        }
        
        return c;
    }
};