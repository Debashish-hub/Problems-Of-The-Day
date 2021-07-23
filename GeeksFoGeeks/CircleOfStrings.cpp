// Circle of strings 
// Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
// A string X can be chained together with another string Y if the last character of X is same as first
// character of Y. If every string of the array can be chained, it will form a circle.

// For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained 
// as "for", "rig", "geek" and "kaf"

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

#define CHARS 26
class Graph{
	int V; 
	list<int> *adj;
	int *in;
public:

	Graph(int V);
	~Graph() { delete [] adj; delete [] in; }

	void addEdge(int v, int w) { adj[v].push_back(w); (in[w])++; }

	bool isEulerianCycle();

	bool isSC();
	void DFSUtil(int v, bool visited[]);

	Graph getTranspose();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	in = new int[V];
	for (int i = 0; i < V; i++)
	in[i] = 0;
}

bool Graph::isEulerianCycle(){
	if (isSC() == false)
		return false;

	
	for (int i = 0; i < V; i++)
		if (adj[i].size() != in[i])
			return false;

	return true;
}

void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose(){
	Graph g(V);
	for (int v = 0; v < V; v++){
	
		list<int>::iterator i;
		for(i = adj[v].begin(); i != adj[v].end(); ++i){
			g.adj[*i].push_back(v);
			(g.in[v])++;
		}
	}
	return g;
}

bool Graph::isSC(){

	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	int n;
	for (n = 0; n < V; n++)
		if (adj[n].size() > 0)
		break;

	DFSUtil(n, visited);

	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	Graph gr = getTranspose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	gr.DFSUtil(n, visited);

	for (int i = 0; i < V; i++)
		if (adj[i].size() > 0 && visited[i] == false)
			return false;

	return true;
}


bool canBeChained(vector<string> arr, int n){
	Graph g(CHARS);
	
	for (int i = 0; i < n; i++){
		string s = arr[i];
		g.addEdge(s[0]-'a', s[s.length()-1]-'a');
	}
	return g.isEulerianCycle();
}

class Solution{
    public:
    int isCircle(int N, vector<string> A){
        int n = A.size();
        if(canBeChained(A,n))
            return 1;
        else
            return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends