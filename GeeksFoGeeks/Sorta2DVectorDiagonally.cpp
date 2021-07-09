// Sort a 2D vector diagonally 

// Given an NxM 2D matrix, rearrange such that 
// Each diagonal in the lower left triangle of the rectangular grid is sorted in ascending order. 
// Each diagonal in the upper right triangle of the rectangular grid is sorted in descending order. 
// The major diagonal in the grid starting from the top-left corner is not rearranged. 

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    void helper1(vector<vector<int>> &mat, priority_queue<int> &pq, int i, int j, int n, int m, int t) {
        if(i<0 || i>=n || j<0 || j>=m) {
            return;
        }
        pq.push(mat[i][j]*t);
        helper1(mat, pq, i+1, j+1, n, m, t);
    }
    void helper2(vector<vector<int>> &mat, priority_queue<int> &pq, int i, int j, int n, int m, int t) {
        if(i<0 || i>=n || j<0 || j>=m) {
            return;
        }
        mat[i][j] = pq.top()*t;
        pq.pop();
        helper2(mat, pq, i+1, j+1, n, m, t);
    }
    void diagonalSort(vector<vector<int>>& mat, int n, int m) {
        for(int i=n-1;i>0;i--) {
            int j = 0;
            priority_queue<int> pq;
            helper1(mat, pq, i, j, n, m, -1);    
            helper2(mat, pq, i, j, n, m, -1);
        } 
        for(int j=1;j<m;j++) {
            int i = 0;
            priority_queue<int> pq;
            helper1(mat, pq, i, j, n, m, 1);    
            helper2(mat, pq, i, j, n, m, 1);
        } 
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int inputline2[n*m];
        for (int i = 0; i < n*m; ++i)
            cin>> inputline2[i];
        vector<vector<int> > matrix( n , vector<int> (m, 0));

        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = inputline2[i * m + j]; 
            }
        }
        
        Solution ob;
        ob.diagonalSort(matrix, n, m);

        // print the modified matrix
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout << endl; 
        }    
    }
    return 0;
}

  // } Driver Code Ends