// Word Boggle 
// Medium Accuracy: 48.98% Submissions: 13818 Points: 4
// Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words 
// from the dictionary that can be formed by a sequence of adjacent characters on the board. We can move to any 
// of 8 adjacent characters, but a word should not have multiple instances of the same cell.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
	bool vis[100][100];
    bool exist;
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    void dfs(vector<vector<char> >& board, string word, int i, int x, int y, int n, int r, int c){
        
        if(i<n && x>=0 && x<r && y>=0 && y<c && board[x][y] == word[i]){
            if(i == n-1){
                exist = true;
                return;
            }
            vis[x][y] = true;
            for(int k=0; k<8; k++){
                int x1 = x + dx[k];
                int y1 = y + dy[k];
                
                if(x1>=0 && x1<r && y1>=0 && y1<c && vis[x1][y1] == false)
                    dfs(board, word, i+1, x1, y1, n, r, c);
            }
            vis[x][y] = false;
        }
    }
    
    bool WordSearch(vector<vector<char> >& board, string word) {
        // Your code goes here
        int n = board.size();
        int m = board[0].size();
        exist = false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    
                    for(int x=0;x<n;x++)
                        for(int y=0;y<m;y++)
                            vis[x][y] = false;
                            
                    dfs(board, word, 0, i, j, word.size(), n, m);
                    if(exist)
                        return true;
                }
            }
        }
        
        return false;
    }
    
    vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
        // Your code goes here
        vector<string> ans;
        for(int i=0;i<dictionary.size(); i++){
            if(WordSearch(board, dictionary[i]))
                ans.push_back(dictionary[i]);
        }
        return ans;
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