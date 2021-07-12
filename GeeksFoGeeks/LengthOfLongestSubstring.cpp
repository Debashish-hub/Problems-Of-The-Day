// Length of the longest substring 

// Given a string S, find the length of the longest substring without repeating characters.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<int> mp(26, 0);
        int i = 0, j = 0, maxlen = 0;
        
        while(j < s.size()){
            mp[s[j] - 'a']++;
            while(mp[s[j] - 'a'] > 1)
            mp[s[i++] - 'a']--;
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends