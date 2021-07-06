// The Painter's Partition Problem 

// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is 
// given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 
// 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint 
// that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int getMax(int arr[], int n)
    {
    	int max = INT_MIN;
    	for (int i = 0; i < n; i++)
    		if (arr[i] > max)
    			max = arr[i];
    	return max;
    }
    
    long long getSum(int arr[], int n)
    {
    	long long total = 0;
    	for (int i = 0; i < n; i++)
    		total += arr[i];
    	return total;
    }
    
    int numberOfPainters(int arr[], int n, long long maxLen)
    {
    	long long total = 0, numPainters = 1;
    
    	for (int i = 0; i < n; i++) {
    		total += arr[i];
    
    		if (total > maxLen) {
    
    			total = arr[i];
    			numPainters++;
    		}
    	}
    
    	return numPainters;
    }
    
    long long minTime(int arr[], int n, int k)
    {
    	long long lo = getMax(arr, n);
    	long long hi = getSum(arr, n);
    
    	while (lo < hi) {
    		long long mid = lo + (hi - lo) / 2;
    		long long requiredPainters = numberOfPainters(arr, n, mid);
    
    		if (requiredPainters <= k)
    			hi = mid;
    		else
    			lo = mid + 1;
    	}
    
    	// required
    	return lo;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends