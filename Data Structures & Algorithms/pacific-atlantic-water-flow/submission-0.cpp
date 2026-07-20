class Solution {
    void dfs(int r, int c,vector<vector<int>>& heights,vector<vector<int>>& vis,int prevheight){
        vis[r][c]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && !vis[nr][nc] && heights[nr][nc]>=prevheight){
                dfs(nr,nc,heights,vis,heights[nr][nc]);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res;
        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        for(int c=0;c<m;c++){
            if(pac[0][c]==0) dfs(0,c,heights,pac,heights[0][c]);
            if(atl[n-1][c]==0) dfs(n-1,c,heights,atl,heights[n-1][c]);
        }

        for(int r=0;r<n;r++){
            if(pac[r][0]==0) dfs(r,0,heights,pac,heights[r][0]);
            if(atl[r][m-1]==0) dfs(r,m-1,heights,atl,heights[r][m-1]);
        }

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(pac[r][c] && atl[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};
