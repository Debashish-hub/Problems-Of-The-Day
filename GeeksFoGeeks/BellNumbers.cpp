// Bell Numbers 

// Given a set of n elements, find number of ways of partitioning it.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int bellNumber(int n)
    {
       // Code Here
       int dp[n][n];
       dp[0][0]=1;
       int k=1e9+7;

       for(int i=1;i<n;i++){
           dp[i][0]=dp[i-1][i-1];
           for(int j=1;j<=i;j++){
               dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % k;
           }
       }
       return dp[n-1][n-1];
    }
};


// { Driver Code Starts.



int main()
{
    Solution obj;
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends