// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above 
// (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// In addition to the mapping above, an encoded message may contain the '*' character, which can represent any digit from '1' to '9' 
// ('0' is excluded). For example, the encoded message "1*" may represent any of the encoded messages "11", "12", "13", "14", "15", 
// "16", "17", "18", or "19". Decoding "1*" is equivalent to decoding any of the encoded messages it can represent.

// Given a string s containing digits and the '*' character, return the number of ways to decode it.

// Since the answer may be very large, return it modulo 109 + 7.

typedef long long ll;

class Solution {
public:
    ll m = 1e9+7;
    string s;
    
    ll dp[100001];
    
    int numDecodings(string &S) {
        s = S;
        for(int i = 0 ; i <= s.size(); i++){
            dp[i] = -1;
        }
        ll ans = help(0);
        return ans;
    }
    
    ll help(int pos){
        if(pos >= s.size()){
            return 1;
        }
        
        if(dp[pos] != -1) return dp[pos];
        
        if(s[pos] == '0'){
            return dp[pos] = 0;
        }
        
        ll ans = help(pos+1);
        if(s[pos] == '*'){
            ans *= 9;
            
            if(pos+1 < s.size() && s[pos+1] >= '0' && s[pos+1] <= '9'){
                ans += help(pos+2);
            }
            if(pos+1 < s.size() && s[pos+1] == '*'){
                ans += 9*help(pos+2);
            }
            
            if(pos+1 < s.size() && s[pos+1] >= '0' && s[pos+1] <= '6'){
                ans += help(pos+2);
            }
            
            if(pos+1 < s.size() && s[pos+1] == '*'){
                ans = ans + (6*help(pos+2));
            }
        }
        else if(s[pos] == '1' && pos+1 < s.size()){
            if(s[pos+1] >= '0' && s[pos+1] <= '9'){
                ans += help(pos+2);
            }
            else if(s[pos+1] == '*'){
                ans += 9*help(pos+2);
            }
        }
        else if(s[pos] == '2' && pos+1 < s.size()){
            if(s[pos+1] >= '0' && s[pos+1] <= '6'){
                ans += help(pos+2);
            }
            else if(s[pos+1] == '*'){
                ans += 6*help(pos+2);
            }
        }
        
        ans = ans % m;
        
        return dp[pos] = ans;
    }
};