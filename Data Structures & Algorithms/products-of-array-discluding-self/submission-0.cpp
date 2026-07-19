class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> righth(n,1);
        vector<int> lefth(n,1);
        for(int i=1;i<n;i++){
            righth[i]= righth[i-1]*nums[i-1]; // [1,1,2,8]
            lefth[n-i-1]=lefth[n-i]*nums[n-i]; // [,1]
            
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=righth[i]*lefth[i];
        }

        return ans;

    }
};
