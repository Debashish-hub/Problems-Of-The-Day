// Three Equal Parts


// You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts 
// such that all of these parts represent the same binary value.

// If it is possible, return any [i, j] with i + 1 < j, such that:

// arr[0], arr[1], ..., arr[i] is the first part,
// arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
// arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
// All three parts have equal binary values.
// If it is not possible, return [-1, -1].

// Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 
// in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> dp;
        for(int i = 0 ; i < A.size(); i++) 
            if(A[i]) dp.push_back(i);
        if(dp.size() % 3) return {-1, -1}; 
	if(dp.empty()) return {0,2}; 
        int l1 = 0, l2 = dp.size() / 3, l3 = l2 * 2; 
        for(int i = 1; i < l2; i++ ) {
            int diff = dp[i] - dp[i-1];
            if(dp[l2+i] - dp[l2+i-1] != diff || dp[l3+i] - dp[l3+i-1] != diff)
                return {-1, -1};
	}
        int tail0 = A.size() - dp.back(); 
        if(dp[l3] - dp[l3-1] < tail0 ||   dp[l2] - dp[l2-1] < tail0) return {-1,-1};
        return {dp[l2-1] + tail0 - 1, dp[l3-1] + tail0};
    }
};