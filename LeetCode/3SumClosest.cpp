// 3Sum Closest


// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is 
// closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        pair<int,int> ans = {INT_MAX,INT_MAX};
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int l = i + 1,r = nums.size() - 1;
            while(l<r){
                int currsum = nums[i] + nums[l] + nums[r];
                if(abs(currsum-target)<ans.first){
                    ans.first = abs(currsum-target);
                    ans.second = currsum;
                }
                if(currsum<=target)
                    l++;
                else
                    r--;
            }
        }
        return ans.second;
    }
}; 