class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto& edge : prerequisites){
            indegree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
        }
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                // pq.push({0,})
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return (topo.size()==n);
        
    }
};
