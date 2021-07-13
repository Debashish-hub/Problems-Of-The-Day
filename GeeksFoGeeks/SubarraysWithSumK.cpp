// Subarrays with sum K 

// Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        unordered_map<int,int> mp;
        int pre_sum = 0;
        int ans = 0;
        for(int i=0; i<N; i++){
            pre_sum += Arr[i];
            if(pre_sum == k){
                ans++;
            }
            if(mp.find(pre_sum - k) != mp.end()){
                ans += mp[pre_sum - k];
            }
            mp[pre_sum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends