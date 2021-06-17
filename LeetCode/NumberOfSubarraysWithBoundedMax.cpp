// Number of Subarrays with Bounded Maximum


// We are given an array nums of positive integers, and two positive integers left and right (left <= right).
// Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in
//  that subarray is at least left and at most right.


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int cnt=0,i=0,j=0;
        for (auto n: nums){
            i=(n<left) ? i+1 : 0;
            j=(n<=right) ? j+1 : 0;
            cnt+=j-i;
        }
        return cnt;
    }
};