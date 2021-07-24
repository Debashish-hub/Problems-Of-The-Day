// Word Ladder II
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words 
// beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences 
// from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list 
// of the words [beginWord, s1, s2, ..., sk].

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> visit;  
        queue<vector<string>> q;
        unordered_set<string> wordlist(wordList.begin(),wordList.end());
        q.push({beginWord});
        bool flag= false; 
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){            
                vector<string> cur = q.front();
                q.pop();
                vector<string> newadd =  addWord(cur.back(),wordlist); 
                for(int j=0;j<newadd.size();j++){   
                    vector<string> newline(cur.begin(),cur.end());
                    newline.push_back(newadd[j]);
                    if(newadd[j]==endWord){       
                     flag=true;
                    res.push_back(newline);
                    }
                    visit.insert(newadd[j]);
                    q.push(newline);
                }
            }
            if(flag) break;  
            for(auto it=visit.begin();it!=visit.end();it++) wordlist.erase(*it); 
            visit.clear();
        }
        return res;
    }
    
    vector<string> addWord( string word,unordered_set<string>& wordlist ){
        vector<string> res;
        for(int i=0;i<word.size();i++){
            char s =word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(wordlist.count(word)) res.push_back(word);
            }
            word[i]=s;
        }
        return res;
    }
};