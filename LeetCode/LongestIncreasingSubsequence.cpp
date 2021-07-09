// Longest Increasing Subsequence

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the 
// order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

class Solution {
public:
    int search(int arr[],int low,int high,int x)
    {
        while(low<high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]>=x)
                high=mid;
            else
                low=mid+1;
        }
        return high;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int LIS[n];
        int len = 1;
        LIS[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>LIS[len-1])
            {
                LIS[len] = nums[i];
                len++;
            }
            else
            {
                int index = search(LIS,0,len-1,nums[i]);
                LIS[index] = nums[i];
            }
        }
        return len;
    }

};