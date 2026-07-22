class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1;
        int suff=1;
        int n = nums.size();
        int max_pro=INT_MIN;
        for(int i=0;i<n;i++){
            pref *= nums[i];
            suff *= nums[n-1-i];

            int temp = max(pref,suff);
            max_pro= max(max_pro,temp);

            if(pref==0) pref=1;
            if(suff==0) suff=1;
            
        }
        return max_pro;
    }
};
