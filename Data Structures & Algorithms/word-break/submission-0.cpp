class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int maxLen=0;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        for(string word : wordDict){
            int sz = word.size();
            maxLen = max(maxLen, sz);
        }
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            
            for(int j=i-1;j>=0;j--){
                string word = s.substr(j,i-j);
                if(dp[j] && st.count(word)){
                    dp[i]=true;
                    break;
                }
            }

        }
        return dp[n];
    }
};
