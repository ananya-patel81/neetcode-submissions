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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(),intervals.end(),[](auto a1, auto a2){
            return a1.start < a2.start;
        });

        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(const auto& interval : intervals){
            if(!minHeap.empty() && minHeap.top()<=interval.start){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
