// Max Consecutive Ones III


// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array 
// if you can flip at most k 0's.

 
class Solution {
public:
    int longestOnes(vector<int>& nums, int K) {
        int zeroCount = 0, l = 0;
        int maxLen = 0;
        for( int r = 0 ; r < nums.size() ; ++r ) {
            if( nums[ r ] == 0 ) ++zeroCount;
            while( zeroCount > K ) {
                if( nums[ l ] == 0 ) --zeroCount;
                ++l;
            }
            maxLen = max( maxLen, r - l + 1 );
        }
        return maxLen;
    }
};