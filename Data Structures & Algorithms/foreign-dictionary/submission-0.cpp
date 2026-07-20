class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& adj,unordered_set<char>& st){
         vector<int> indegree(V, 0);
        
        // Loop through all vertices to calculate in-degree
        for (int i = 0; i < V; i++) {
            // Traverse all adjacent vertices of the current vertex
            if(st.count(i+'a')){
                for (auto it : adj[i]) {
                    // Increase in-degree of the connected vertex
                    indegree[it]++;
                }

            }
            
        }
        
        // Create a queue to store vertices with in-degree zero
        queue<int> q;
        
        // Loop through all vertices
        for (int i = 0; i < V; i++) {
            // If in-degree is zero, add to queue
            if (st.count(i+'a') && indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Vector to store the topological order
        vector<int> topo;
        
        // Process until queue is empty
        while (!q.empty()) {
            // Get the front vertex from the queue
            int node = q.front();
            q.pop();
            
            // Add it to the topological order
            topo.push_back(node);
            
            // Reduce in-degree of its adjacent vertices
            for (auto it : adj[node]) {
                indegree[it]--;
                // If in-degree becomes zero, push it into queue
                if (st.count(it+'a') && indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Return the topological ordering
        return topo;
    }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_set<char> st;
        for(string word : words){
            for(char ch : word){
                st.insert(ch);
            }
        }
        int k = st.size();
        int n = words.size();
        vector<vector<int>> adj(26);
        for(int i=0;i<n-1;i++){
            string w1= words[i];
            string w2=words[i+1];
            int len = min(w1.size(),w2.size());
            bool fl = true;
            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    fl=false;
                    break;
                }

            }
            if(fl && w1.size()>w2.size()) return "";
        }

        vector<int> topo = topoSort(26,adj,st);
        if(topo.size()!=k) return "";
        string ans="";
        for(auto it : topo){
            ans+= char(it+'a');
        }
        return ans;
        
    }
};
