/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto a1,auto a2){
            return a1.end < a2.end;
        });
        int prevEnd = intervals[0].end;
        //int count = 0;
        for(int i =1;i<n;i++){
            int start = intervals[i].start;
            int end = intervals[i].end;

            if(start<prevEnd){
                return false;
            }
            else{
                prevEnd = end;
            }
        }
        return true;
        
        
    }
};
