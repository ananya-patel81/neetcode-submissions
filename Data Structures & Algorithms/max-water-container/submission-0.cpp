class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int n = height.size();
        int l = 0;
        int r =n-1;
        while(l<=r){
            int h = min(height[l],height[r]);
            int w = r-l;
            max_area = max(max_area,h*w);
            if(height[l]<=height[r]){
                l++;
            }
            else r--;
        }
        return max_area;
    }
};
