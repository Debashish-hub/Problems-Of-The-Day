// Reshape the Matrix

// In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c 
// keeping its original data.
// You are given an m x n matrix mat and two integers r and c representing the row number and column number of the wanted 
// reshaped matrix.
// The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
// If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, 
// output the original matrix.

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if((r * c) != (mat.size() * mat[0].size()))
            return mat;
        
        vector<vector<int>> fans;
        
        int col = 0;
        vector<int> ans;
        for(int i = 0; i < mat.size(); i++)
        {
            
            for(int j = 0; j < mat[i].size(); j++)
            {
                if(c == col)
                {
                    col = 0;
                    fans.push_back(ans);
                    ans.clear();
                }
                ans.push_back(mat[i][j]);
                col++;
            }
        }
        
        fans.push_back(ans);
        
        return fans;
    }
};