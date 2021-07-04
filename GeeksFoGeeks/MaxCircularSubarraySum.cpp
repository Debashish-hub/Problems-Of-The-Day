// Max Circular Subarray Sum 

// Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int a[], int n){
        
        // your code here
        int max = a[0], max_1 = a[0];
    	int first_ele_pos = 0;
    
    	for (int i = 1; i < 2 * (n - 1); i++) {
    		int index = (i > n - 1) ? i % n : i;
    		if (first_ele_pos == index) {
    			index = first_ele_pos + 1;
    			index = (index > n - 1) ? index % n : index;
    			i = index;
    			max_1 = a[index];
    			first_ele_pos = index;
    			continue;
    		}
    		if (max_1 > 0)
    			max_1 += a[index];
    		else {
    			max_1 = a[index];
    			first_ele_pos = index;
    		}
    		if (max_1 > max)
    			max = max_1;
    	}
    	return max;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends