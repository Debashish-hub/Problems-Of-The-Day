// Maximize The Cut Segments 
// Given an integer N denoting the Length of a line segment. You need to cut the line segment 
// in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
// After performing all the cut operations, your total number of cut segments must be maximum.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int arr[n+1];
        arr[0] = 0;
        for(int i=1; i<=n; i++){
            arr[i] = -1;
            if(i-x >= 0){
                arr[i] = max(arr[i], arr[i-x]);
            }
            if(i-y >= 0){
                arr[i] = max(arr[i], arr[i-y]);
            }
            if(i-z >= 0){
                arr[i] = max(arr[i], arr[i-z]);
            }
            if(arr[i] != -1){
                arr[i]++;
            }
        }
        return max(arr[n], 0);
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends