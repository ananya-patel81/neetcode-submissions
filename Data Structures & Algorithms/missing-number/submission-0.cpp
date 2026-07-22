class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xori=0;
        int xori2 = 0;
        for(int i =0;i<=nums.size();i++){
            xori ^= i;
        }
        for(int num : nums){
            xori2 ^= num;
        }
        return xori ^ xori2 ;
    }
};
