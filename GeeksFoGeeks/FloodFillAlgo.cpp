// Flood fill Algorithm 

// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, 
// "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of 
// the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels 
// (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void floodFillHelper(vector<vector<int>>& image, int x, int y, int prevColor, int newColor){
        int rows = image.size();
        int cols = image[0].size();
        
        if(x < 0 || x >= rows || y < 0 || y >= cols)
            return;
            
        if(image[x][y] != prevColor)
            return;
            
        if(image[x][y] == newColor)
            return;
            
        image[x][y] = newColor;
        
        for(int i = 0; i < 4; i++)
            floodFillHelper(image, x + dir[i][0], y + dir[i][1], prevColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
        
        int prevColor = image[x][y];
        
        floodFillHelper(image, x, y, prevColor, newColor);
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends