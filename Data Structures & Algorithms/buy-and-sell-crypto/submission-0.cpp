class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof=0;
        int mini=prices[0];
        for(int day : prices){
            mini=min(mini,day);
            int cost = day-mini;
            max_prof = max(max_prof,cost);
            
        }
        return max_prof;
    }
};
