class Solution {
    void dfs(int i,vector<vector<int>>& adj, vector<int>& vis){
        vis[i]=1;
        for(int neigh : adj[i]){
            if(!vis[neigh]) dfs(neigh,adj,vis);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;

    }
};
