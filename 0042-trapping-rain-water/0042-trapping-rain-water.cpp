class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = 0;

        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1],height[i-1]);
        }

        rightMax[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1],height[i+1]);
        }

        int water = 0;
        int minHeight;

        for(int i = 0; i < n; i++){
            minHeight = min(leftMax[i],rightMax[i]);
            if(minHeight - height[i] > 0){
                water += minHeight - height[i];
            }
        }

        return water;
    }
};