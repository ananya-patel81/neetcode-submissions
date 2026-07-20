class Solution {
    void backtrack(int i,vector<int>& cur,int target, vector<int>& nums, vector<vector<int>>& res){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        cur.push_back(nums[i]);
        backtrack(i,cur,target-nums[i],nums,res);
        cur.pop_back();
        backtrack(i+1,cur,target,nums,res);
    }

public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur={};
        sort(nums.begin(),nums.end());
        backtrack(0,cur,target,nums,res);
        return res;
        
    }
};
