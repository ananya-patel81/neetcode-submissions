class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> min_h;
    priority_queue<int> max_h;
    int size;
    MedianFinder() {
        size=0;
        
    }
    
    void addNum(int num) {
        size++;
        max_h.push(num);
        
        if(!min_h.empty() && max_h.top()>min_h.top()){
            min_h.push(max_h.top());
            max_h.pop();
        }
        if(max_h.size()>min_h.size()+1){
            min_h.push(max_h.top());
            max_h.pop();
        }
        else if(min_h.size() > max_h.size()+1){
            max_h.push(min_h.top());
            min_h.pop();
        }
    }
    
    double findMedian() {
        if(min_h.size() == max_h.size()){
            return (min_h.top()+max_h.top())/2.0;
        }
        else if(max_h.size()>min_h.size()){
            return max_h.top();
        }
        return min_h.top();
        
    }
};
