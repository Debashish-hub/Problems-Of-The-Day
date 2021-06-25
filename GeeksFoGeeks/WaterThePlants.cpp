// Water the plants 

// A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions for 
// attaching water sprinklers at every partition. A sprinkler with range x at partition i can water all 
// partitions from i-x to i+x.
// Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler 
// at partition i (power==-1 indicates no sprinkler attached), return the minimum number of sprinklers 
// that need to be turned on to water the complete gallery.
// If there is no possible way to water the full length using the given sprinklers, print -1.



// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int temp[n];
        memset(temp,-1,sizeof(temp));
        for(int i=0; i<n; i++){
            if(gallery[i] == 0){
                temp[i] = max(i, temp[i]);
            }else if(gallery[i] != -1){
                int end = i+gallery[i];
                int start = max(0, i-gallery[i]);
                for(int x = start; x <= min(n,end); x++){
                    temp[x] = max(end, temp[x]);
                }
            }
        }
        int ans = 0, i =0 ;
        while(i < n){
            if(i == -1 || temp[i] == -1)
                return -1;
            ans++;
            i = temp[i] + 1;
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
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}
  // } Driver Code Ends