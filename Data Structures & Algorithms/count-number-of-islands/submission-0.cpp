class Solution {
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j){
        vis[i][j]=1;
        int n = grid.size();
        int m = grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int d=0;d<4;d++){
            int nr = i+drow[d];
            int nc = j+dcol[d];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(grid,vis,nr,nc);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
        
    }
};
