// Redundant Connection

// In this problem, a tree is an undirected graph that is connected and has no cycles.
// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
// The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
// The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge 
// between nodes ai and bi in the graph.
// Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
// If there are multiple answers, return the answer that occurs last in the input.

class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        if(edges.size()==0) return{};
        parent.resize(edges.size()+1);
        for(int i=1;i<edges.size()+1;i++){
            parent[i]=i;
        }
        for(vector<int> edge : edges){
            int f1=find(edge[0]);
            int f2=find(edge[1]);
            if(f1!=f2)
                parent[f1]=f2;
            else
                return edge;
        }
        return {};
    }
    int find(int x){
        return parent[x]==x ? x : find(parent[x]);
    }
};