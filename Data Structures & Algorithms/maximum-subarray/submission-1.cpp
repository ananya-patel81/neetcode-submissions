class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pref = 0;
        int max_sum=INT_MIN;
        if(nums.size()==1) return nums[0];
        for(int num : nums){
            
            pref+= num;
            
            max_sum = max(max_sum,pref);
            if(pref<0) pref=0;
            
        }
        return max_sum;

    }
};
