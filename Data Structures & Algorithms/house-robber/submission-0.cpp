class Solution {
    int f(int i, int n, vector<int>& dp, vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int not_take = f(i+1,n,dp,nums);
        int take = nums[i] + f(i+2,n,dp,nums);
        return dp[i]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int collect = 0;
        vector<int> dp(n,-1);
        return f(0,n,dp,nums);
        
    }
};
