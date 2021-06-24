// Out of Boundary Paths


// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
// You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out of 
// the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball 
// out of the grid boundary. Since the answer can be very large, return it modulo 10*9 + 7.

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        vector<vector<long long>> mydp(m,vector<long long>(n,0));
        vector<vector<long long>> temp(m,vector<long long>(n,0));
        int mod = (int)(1e9+7);

        for (int k=1;k<=maxMove;k++)
        {
            for (int i=0;i<m;i++)
            {
                for (int j=0;j<n;j++)
                {
                    temp[i][j]=(i==0)+(j==0)+(i==m-1)+(j==n-1); 
					if (i>0)
                        temp[i][j]+=mydp[i-1][j];
                    if (i<m-1)
                        temp[i][j]+=mydp[i+1][j];
                    if (j>0)
                        temp[i][j]+=mydp[i][j-1];
                    if (j<n-1)
                        temp[i][j]+=mydp[i][j+1];
                    
                    temp[i][j]=temp[i][j]%mod;
                }
            }
            mydp=temp; 
        }
        return mydp[sr][sc];
    }
};