// 01 Matrix

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h=matrix.size(), w=matrix[0].size();
        vector<vector<int>> dp(h,vector<int>(w,INT_MAX));
        for(int times=0;times<=1;times++) 
            for(int i=times?h-1:0;times?i>=0:i<h;times?i--:i++) 
                for(int j=times?w-1:0;times?j>=0:j<w;times?j--:j++)
                        if(matrix[i][j]==0)
                            dp[i][j]=0;
                        else {
                            if(i&&dp[i-1][j]!=INT_MAX&&dp[i][j]>dp[i-1][j]+1)
                                dp[i][j]=dp[i-1][j]+1;
                            if(j&&dp[i][j-1]!=INT_MAX&&dp[i][j]>dp[i][j-1]+1) 
                                dp[i][j]=dp[i][j-1]+1;
                            if(i<h-1&&dp[i+1][j]!=INT_MAX&&dp[i][j]>dp[i+1][j]+1) 
                                dp[i][j]=dp[i+1][j]+1;
                            if(j<w-1&&dp[i][j+1]!=INT_MAX&&dp[i][j]>dp[i][j+1]+1)
                                dp[i][j]=dp[i][j+1]+1;
                        }
        return dp;
    }
};