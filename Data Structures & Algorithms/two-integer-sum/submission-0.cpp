class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //you can create a hash map with the integer in the array
        // mapping to the difference of it with the target. 
        // if the difference exists in the array, return both. 
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> umpp;
        for(int i=0;i<n;i++){
            umpp[nums[i]]= i;

        }
        for(int i=0; i<n; i++){
            int complement= target - nums[i];
            if(umpp.find(complement)!= umpp.end() && umpp.find(complement)->second != i ){
                auto it = umpp.find(complement);
                ans.push_back(it->second);
                ans.push_back(i);
                sort(ans.begin(),ans.end());
                return ans;
            }
        }

        return ans;

        
    }
};
