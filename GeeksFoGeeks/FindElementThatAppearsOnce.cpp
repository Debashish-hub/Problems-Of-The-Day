// Find the element that appears once 

// Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, except for one number 
// which will occur only once. Find the number occurring only once.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int a[], int n){
	    //code
	    int mid,begin=0,end=n;

        while(begin<=end){
            mid=begin+(end-begin)/2;
            if(a[mid]==a[mid+1] && mid%2==0 || a[mid]==a[mid-1] && mid%2!=0)
                begin=mid+1;
            else
                end=mid-1;
        }
        return a[begin];
	    
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends