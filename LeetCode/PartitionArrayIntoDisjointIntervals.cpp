// Partition Array into Disjoint Intervals
// Given an array nums, partition it into two (contiguous) subarrays left and right so that:

// Every element in left is less than or equal to every element in right.
// left and right are non-empty.
// left has the smallest possible size.
// Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int l=nums[0],r=nums[0];
        int index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<l){
                index=i;
                l=r;
            }
            r=max(nums[i],r);
        }
        return index+1;
    }
};