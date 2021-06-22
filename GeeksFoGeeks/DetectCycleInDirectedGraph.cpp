// Detect cycle in a directed graph 

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
// check whether it contains any cycle or not.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool cyclic(int i, int V, vector<int> adj[],bool visited[], bool inTheCall[])
    {
      
        visited[i]=true;
        inTheCall[i]=true;
        for(int j =0;j<adj[i].size();j++)
        { 
            if(!visited[adj[i][j]] &&  cyclic(adj[i][j],V,adj,visited,inTheCall))
            {
                return true;
            }
            else{
                if(inTheCall[adj[i][j]])
                return true;
            }
        }
        
        inTheCall[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        bool visited[V];
        bool inTheCall[V];
        for(int  i=0;i<V;i++)
        {
            visited[i]=false;
            inTheCall[i]= false;
        }
        
        for(int i =0;i<V;i++)
        {  if(!visited[i]){
          if(cyclic(i,V,adj,visited,inTheCall))
          return true;
        }
        }
        return false;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends