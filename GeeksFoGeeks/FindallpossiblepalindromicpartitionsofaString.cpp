// Find all possible palindromic partitions of a String 

// Given a String S, Find all possible Palindromic partitions of the given String.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool is_pal(string &s)
    {
        int n=s.length();
        for(int i=0;i<n ;i++)
        {
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
    void helper(string &s,vector<string>&aux,vector<vector<string>>&ans,int index)
    {
        if(index==s.length())
        {
            ans.push_back(aux);
            return;
        }
        string tmp="";
        for(int i=index;i<s.length();i++) 
        {
            tmp.push_back(s[i]);
            if(is_pal(tmp))
            {
                aux.push_back(tmp);
                helper(s,aux,ans,i+1);
                aux.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) 
    {
        vector<vector<string>>ans;
        vector<string>aux;
        helper(s,aux,ans,0);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends