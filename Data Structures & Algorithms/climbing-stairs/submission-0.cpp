class Solution {
    int climb(int curr, int target,vector<int>& dp){
        if(curr == target) return 1;
        if(curr>target) return 0;
        if(dp[curr]!=-1) return dp[curr];
        int step1 = climb(curr+1,target,dp);
        int step2 = climb(curr+2,target,dp);
        return dp[curr]=step1+step2;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        //dp[0]=0;
        return climb(0,n,dp);
        
    }
};
