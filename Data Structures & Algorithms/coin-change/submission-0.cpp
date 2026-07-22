class Solution {
    int f(int ind,int target,vector<int>& coins){
        if(ind<0 && target>0) return 1e8;
        if(target==0) return 0;
        if(ind==0){
            if(target>=coins[0] && target%coins[0]==0){
                return target/coins[0] ; 
            }
            
            else return 1e8;
        }
        if(ind<0) return 1e8;
        int not_take = f(ind-1,target,coins);
        int take = 1e8;
        if(target >= coins[ind]){
            take = 1+f(ind,target-coins[ind],coins);
        }
        return min(not_take,take);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        //dp
        return (f(n-1,amount,coins)==1e8) ? -1 : f(n-1,amount,coins);
        
        
    }
};
