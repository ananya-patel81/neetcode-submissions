class Solution {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> newInt;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        newInt.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int start_og = intervals[i][0];
            int end_og = intervals[i][1];
            if(newInt.back()[1] >= start_og){
                newInt.back()[1]=max(newInt.back()[1],end_og);
            }
            else{
                newInt.push_back({start_og,end_og});
            }
        }
        return newInt;

        
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        return merge(intervals);
        
        
    }
};
