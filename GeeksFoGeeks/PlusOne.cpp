// Plus One 
// Easy Accuracy: 50.09% Submissions: 16194 Points: 2
// Given a non-negative number represented as a list of digits, add 1 to the number 
// (increment the number represented by the digits). 
// The digits are stored such that the most significant digit is first element of array.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        if(arr[N-1] != 9){
            arr[N-1] += 1;
            return arr;
        }
        while(N!=0 ){ 
            if(arr[N-1] == 9){
                arr[N-1] = 0 ;
                N--; 
             }else{
                arr[N-1] += 1;
                return arr;
            }
        }
        arr.insert(arr.begin(),1);
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends