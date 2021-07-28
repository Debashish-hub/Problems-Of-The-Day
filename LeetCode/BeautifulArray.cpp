// Beautiful Array

// For some fixed n, an array nums is beautiful if it is a permutation of the integers 1, 2, ..., n, such that:
// For every i < j, there is no k with i < k < j such that nums[k] * 2 = nums[i] + nums[j].
// Given n, return any beautiful array nums.  (It is guaranteed that one exists.)

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1)
            return {1};
        vector<int> even = beautifulArray(n/2);
        vector<int> odd = beautifulArray(n-(n/2));
        vector<int>ans;
        for(auto e:even)
            ans.push_back(2*e);
        for(auto e:odd)
            ans.push_back((2*e)-1);
        return ans;
    }
};