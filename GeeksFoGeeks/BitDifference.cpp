// Bit Difference 

// We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f (2, 7) = 2, 
// since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f (2, 7) = 2.

// You are given an array A of N integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all ordered pairs (i, j) such that 1 ≤ i, j ≤ N.
//  Return the answer modulo 109+7.

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        long long ans=0;
        int mod=1000000007;
        for(int i=0;i<32;i++)
        {
            long long count=0;
            for(int j=0;j<N;j++)
            {
                if(A[j] & 1<<i)
                count++;
            }
            ans= (ans+count*(N-count)*2)%mod;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends