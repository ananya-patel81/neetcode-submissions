class Solution {
    bool isValid(int r,int c,int ind,vector<vector<char>>& board,vector<vector<int>>& vis,string& word){
        vis[r][c]=1;
        // if(r>=board.size() || c>=board[0].size() || r<0 || c<0 || ind>word.size()) return false;
        if(ind==word.size()) return true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int d=0;d<4;d++){
            int nr = r+drow[d];
            int nc = c + dcol[d];
            if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && board[nr][nc]==word[ind] && vis[nr][nc]==0){
                if(isValid(nr,nc,ind+1,board,vis,word)) return true;
            }
        }
        vis[r][c]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    if(isValid(i,j,1,board,vis,word)){
                        return true;
                    }
                }
            }
        }
        return false;

        
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(string word : words){
            if(exist(board,word)){
                ans.push_back(word);
            }
        }
        return ans;
        
    }
};
