// Left most and right most index 

// Given a sorted array with possibly duplicate elements. The task is to find indexes of first and last occurrences of an 
// element X in the given array.

// Note: If the element is not present in the array return {-1,-1} as pair.

 
 // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    long leftMost(vector<long long> v,long long x){
        long start = 0;
        long end = v.size()-1;
        long res = -1;
        while(start <= end){
            long mid = start + (end - start)/2;
            if(v[mid] == x){
                res = mid;
                end = mid-1;
            }else if(x > v[mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return res;
    }
        
    long rightMost(vector<long long> v,long long x){
        long start = 0;
        long end = v.size()-1;
        long res = -1;
        while(start <= end){
            long mid = start + (end - start)/2;
            if(v[mid] == x){
                res = mid;
                start = mid+1;
            }else if(x > v[mid]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return res;
    }
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long left=leftMost(v,x);
        long right=rightMost(v,x);
        pair<long,long> p;
        p.first=left;
        p.second=right;
        return p;
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends