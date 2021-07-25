// Non-negative Integers without Consecutive Ones

// Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not 
// contain consecutive ones.

class Solution {
    int calc(int len)
    {
        int l0 = 1, l1 = 0;
        for (int i = 0; i < len; ++i)
            l0 += l1, l1 = l0 - l1;
        return l1 + l0;
    }
public:
    int findIntegers(int num) {
        int sum = 0;
        bool is_last_one = false;
        for (int i = 31; i >= 0; i --)
            if ((1 << i & num) > 0)
            {
                sum += calc(i);
                if ((1 << i+1 & num) > 0)
                    return sum;
            }
        return sum + 1;
    }
};