// Geeky Buildings 

// There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. 
// Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be 
// taller than the first and shorter than the second.
// Can geek build the three-building recreational zone? 

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		int leftMin[n];
	    leftMin[0] = arr[0];
	    for(int i=1;i<n;i++) leftMin[i]= min(arr[i],leftMin[i-1]); 
	    stack<int>s;
	    for(int i=n-1;i>=0;i--)
	    {
	        if(s.empty()) s.push(arr[i]);
	        else
	        {
	            while(!s.empty() && leftMin[i]>=s.top()) s.pop();
	            
	            if(!s.empty()) 
	                if(leftMin[i]<arr[i] && arr[i] >s.top()) 
	                    return true;
	            
	            s.push(arr[i]);
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends