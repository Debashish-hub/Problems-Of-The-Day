// Palindrome Pairs


// Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list, 
// so that the concatenation of the two words words[i] + words[j] is a palindrome.

class Solution {
public:
    bool palindrome(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]=i;
        }
        set<vector<int>>res;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            if(word==""){
                for(int j=0;j<words.size();j++){
                    if(i==j)continue;
                    if(palindrome(words[j])){
                        res.insert({i,j});
                        res.insert({j,i});
                    }
                }
                continue;
                
            }
            string temp=string(word.rbegin(),word.rend());
            if(mp.find(temp)!=mp.end()){if(i!=mp[temp])res.insert({i,mp[temp]});}
            for(int j=0;j<word.length()-1;j++){
                string left=word.substr(0,j+1);
                string right=word.substr(j+1);
                string rright=string(right.rbegin(),right.rend());
                string rleft=string(left.rbegin(),left.rend());
                if(palindrome(left) && (mp.find(rright)!=mp.end())){
                    if(i!=mp[rright])res.insert({mp[rright],i});
                }
                if(palindrome(right) && (mp.find(rleft)!=mp.end())){
                    if(i!=mp[rleft])res.insert({i,mp[rleft]});
                }
            }
        }
        return {res.begin(),res.end()};
    }
};