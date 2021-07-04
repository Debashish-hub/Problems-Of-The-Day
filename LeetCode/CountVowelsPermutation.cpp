// Count Vowels Permutation

// Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

class Solution {
public:
    int countVowelPermutation(int n) {
			long long int mod = pow(10, 9) + 7;
			vector <long long int> dp1(5, 1);
			vector <long long int> dp2(5, 1);
			for(int i = 1; i < n; i++){
				dp2[0] = dp1[1]; // Since a should be followed by e
				dp2[1] = (dp1[0] + dp1[2]) % mod; // e should be followed by a or i
				dp2[2] = (dp1[0] + dp1[1] + dp1[3] + dp1[4]) % mod; // i can be followed by anything except i
				dp2[3] = (dp1[2] + dp1[4]) % mod; // o should be followed by i or u
				dp2[4] = dp1[0]; // u should be followed by a
				dp1 = dp2; // copying the values for next iteration
			}
			long long int count = 0;
			for(int i = 0; i < 5; i++) // Do summation of the resultant array for all the sequences count.
				count = (count + dp1[i]) % mod;
			return count;
		}
};