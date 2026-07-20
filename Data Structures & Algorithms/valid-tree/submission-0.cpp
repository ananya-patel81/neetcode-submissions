class Solution {
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis,int parent){
        vis[i]=1;
        for(int neigh : adj[i]){
            if(!vis[neigh]){
                if(dfs(neigh,adj,vis,i)) return true;
            }
            else{
                if(neigh != parent) return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //cycle detection and if that's not there then number of components must not exceed 1;
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
                if(count>1) return false;
                if(dfs(i,adj,vis,-1)) return false;
            }
        }
        return true;

    }
};
