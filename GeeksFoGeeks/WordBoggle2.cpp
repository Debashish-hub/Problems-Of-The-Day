// Word Boggle - II 
// Medium Accuracy: 47.83% Submissions: 1127 Points: 4
// Given a dictionary of words and an M x N board where every cell has one character. 
// Find all possible different words from the dictionary that can be formed by a sequence of 
// adjacent characters on the board. 
// We can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
	struct trie
    {
        char data;
        int we;
        string s;
        trie *children[26];
    };
    trie *getNode(char c)
    {
        trie *node=new trie;
        node->data=c;
        node->we=0;
        node->s="";
        for(int i=0;i<26;i++)
        {
            node->children[i]=NULL;
        }
        return node;
    }
    trie *insertNode(trie *root,string &word)
    {
        trie *tmp=root;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'A';
            if(!tmp->children[index])
            {
                tmp->children[index]=getNode(word[i]);
            }
            tmp=tmp->children[index];
        }
        tmp->s=word;
        tmp->we++;
        return root;
    }
    void helper(vector<vector<char>>&board,vector<string>&v,int i,int j,trie *curr)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='#' || !curr->children[board[i][j]-'A'])
        {
            return;
        }
        int index=board[i][j]-'A';
        curr=curr->children[index];
        if(curr->we>0)
        {
            v.push_back(curr->s);
            curr->we=0;
        }
        char c=board[i][j];
        board[i][j]='#';
        helper(board,v,i-1,j,curr);
        helper(board,v,i-1,j+1,curr);
        helper(board,v,i,j+1,curr);
        helper(board,v,i+1,j+1,curr);
        helper(board,v,i+1,j,curr);
        helper(board,v,i+1,j-1,curr);
        helper(board,v,i,j-1,curr);
        helper(board,v,i-1,j-1,curr);
        board[i][j]=c;
    }
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary)
    {
        trie *root=getNode('\0');
    	for(int i=0;i<dictionary.size();i++)
    	{
    	    root=insertNode(root,dictionary[i]);
    	}
    	vector<string>v;
    	for(int i=0;i<board.size();i++)
    	{
    	    for(int j=0;j<board[0].size();j++)
    	    {
    	        helper(board,v,i,j,root);
    	    }
    	}
    	return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends