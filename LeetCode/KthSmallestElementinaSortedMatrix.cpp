// Kth Smallest Element in a Sorted Matrix


// Given an n x n matrix where each of the rows and columns are sorted in ascending order, return 
// the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                q.push(matrix[i][j]);
                if(q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};