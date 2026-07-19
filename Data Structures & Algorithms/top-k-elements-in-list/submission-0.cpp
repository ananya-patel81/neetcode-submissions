class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for (int n : nums){
            mpp[n]++;

        }

        vector<pair<int,int>> vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(), [](const auto& a, const auto& b){
            return a.second > b.second ;
        });

        vector<int> ans;
        

        for (int i=1; i<=k; i++){
            ans.push_back(vec[i-1].first);


        }

        return ans;


        // hash map of numbers with their frequencies
        // return top k. 
        
    }
};
