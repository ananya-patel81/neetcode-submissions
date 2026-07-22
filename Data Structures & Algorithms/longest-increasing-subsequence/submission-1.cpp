class Solution {
    int f(int ind, int prevInd, int n,vector<vector<int>>& dp,vector<int>& nums){
        if(ind==n) return 0;
        if(dp[prevInd][ind]!=-1) return dp[prevInd][ind];
        int len = f(ind+1,prevInd,n,dp,nums);
        if(prevInd==0 || nums[prevInd-1]<nums[ind]){
            len = max(len,1+f(ind+1,ind+1,n,dp,nums));
        }
        return dp[prevInd][ind]=len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,n,dp,nums);
        
    }
};
