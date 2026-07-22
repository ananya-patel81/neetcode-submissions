class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto& a1,auto& a2){
            return a1[1] < a2[1];
        });
        int prevEnd = intervals[0][1];
        int count = 0;
        for(int i =1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start<prevEnd){
                count++;
            }
            else{
                prevEnd = end;
            }
        }
        return count;
    }
};
