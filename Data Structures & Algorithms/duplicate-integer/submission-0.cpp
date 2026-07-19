class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umpp;
        int n=nums.size();
        for(int i=0; i<n;i++){
            umpp[nums[i]]++;
        }
        for(auto& it : umpp) {
            if(it.second >1){
                return true;
            }
        }
        
        return false;
        
    }
};