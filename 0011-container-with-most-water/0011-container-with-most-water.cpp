class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxi = 0;

        while(l < r){
            int curr_area = min(height[l],height[r]) * (r - l);
            maxi = max(maxi,curr_area);
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }

        return maxi;
    }
};