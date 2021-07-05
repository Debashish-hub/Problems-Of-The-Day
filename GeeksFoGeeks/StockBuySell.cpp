// Stock buy and sell 

// The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell 
// the stock so that in between those days your profit is maximum.
// Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output
// of 1, whereas wrong solutions will result in an output of 0.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> v;
        for(int i=1; i<n; i++){
            vector<int> res;
            if(A[i-1] < A[i]){
                res.push_back(i-1);
                i++;
                while(i<n){
                    if(A[i-1] <= A[i]){
                        i++;
                    }else{
                        break;
                    }
                }
                res.push_back(i-1);
                v.push_back(res);
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends