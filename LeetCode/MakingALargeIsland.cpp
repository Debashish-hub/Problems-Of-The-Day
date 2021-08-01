// Making A Large Island

// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.
//Took some help for this

map<pair<int,int>,int> visited;
map<int,int> size_;
int n,m;
int dfs(vector<vector<int>>& mat,int i,int j,int comp)
{
    // if at invalid position or at '0'
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j]!=1) return 0;
    
    // mark current component
    mat[i][j]=comp;
    
    // expand to neighbours
    return 1+dfs(mat,i-1,j,comp)+dfs(mat,i+1,j,comp)+dfs(mat,i,j-1,comp)+dfs(mat,i,j+1,comp);
}

// function to check if current mat[i][j] is non zero and is with the matrix
int valid(vector<vector<int>>& mat,int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || mat[i][j]==0) return 0;
    return 1;
}

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int comp=2;
        n=grid.size(),m=grid[0].size();
        // clear things
        visited.clear(); size_.clear();
        
        // max_ is our final answer
        int max_=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[{i,j}] && grid[i][j]==1)
                {
                    // this component of 1's mark all of them as 'comp'
                    int x=dfs(grid,i,j,comp);
                    
                    // store size of current component
                    size_[comp]=x;
                    
                    // comp++ for next marking
                    comp++;
                    
                    // we can update max_ beacuse here no '0' has changed to '1', and we can do that as given atmost one '0' can be changed
                    max_=max(max_,size_[comp-1]);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    // set this '0' as 1 and try to merge neighbouring components , put them in set so we dont consider a component twice
                    //e.g
                    // 11100
                    // 11022
                    // 00302
                    //for grid[1][2]=0 neighbour components are 1,2 and 3
                    set<int> s;
                    if(valid(grid,i-1,j)) s.insert(grid[i-1][j]);
                    if(valid(grid,i+1,j)) s.insert(grid[i+1][j]);
                    if(valid(grid,i,j+1)) s.insert(grid[i][j+1]);
                    if(valid(grid,i,j-1)) s.insert(grid[i][j-1]);
                
                int ans=0;
                // merge components
                for(auto a:s)  ans+=size_[a];
                    
                //update max_;
                max_=max(max_,ans+1);
                }
            }
        }
        return max_;
    }
};