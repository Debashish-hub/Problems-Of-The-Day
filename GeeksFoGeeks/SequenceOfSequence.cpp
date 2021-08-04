// Sequence of Sequence 

// Given two integers m & n, find the number of possible sequences of length n 
// such that each of the next element is greater than or equal to twice of the previous element but less than or equal to m.

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n){
        // code here
        if(m < n)
            return 0;
        if(n == 0)
            return 1;
        return numberSequence(m-1, n) + numberSequence(m/2, n-1);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends