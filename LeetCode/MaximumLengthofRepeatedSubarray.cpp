// Maximum Length of Repeated Subarray

// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        int res = 0;
        for(int i = 1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};