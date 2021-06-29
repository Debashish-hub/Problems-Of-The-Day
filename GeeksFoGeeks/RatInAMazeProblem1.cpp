// Rat in a Maze Problem - I 

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at 
// (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
// Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 
// 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper(vector<vector<int>> m,int i,int j,int n,vector<string>&res,string path){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]!=1)
            return;
        if(i==n-1 && j==n-1){
            res.push_back(path);
            return ;
        }
        m[i][j]=-1;
        helper(m,i+1,j,n,res,path+'D');
        helper(m,i-1,j,n,res,path+'U');
        helper(m,i,j+1,n,res,path+'R');
        helper(m,i,j-1,n,res,path+'L');
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        string s="";
        helper(m,0,0,n,res,s);
        sort(res.begin(),res.end());
        return res;     
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends