// Merge k Sorted Arrays 

// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
typedef pair<int, pair<int, int> > p;


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<p,vector<p>,greater<p>> q;
         vector<int> result;
         
         for(int i=0;i<K;i++){
             q.push({arr[i][0],{i,0}});
         }
         
         while(!q.empty()){
             p current = q.top();
             q.pop();
             
             int value = current.first;
             int arrayNo = current.second.first;
             int index = current.second.second;
             
             result.push_back(value);
            
             
             if(index+1<K){
                 q.push({arr[arrayNo][index+1],{arrayNo,index+1}});
             }
         }
         
         return result;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends