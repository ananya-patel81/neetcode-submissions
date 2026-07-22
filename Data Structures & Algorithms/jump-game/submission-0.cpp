class Solution {
    bool f(int i,int n, vector<int>& nums){
        if(i>=n) return false;
        if(i==n-1) return true;
        for(int j=1;j<=nums[i];j++){
            if(f(i+j,n,nums)) return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return f(0,n,nums);
    }
};
