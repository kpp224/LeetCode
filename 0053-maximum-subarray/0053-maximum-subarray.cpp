class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = nums[0];
        int maxSumSoFar = nums[0];

        for(int i = 1; i < nums.size(); i++){
            currMax = max(nums[i],(nums[i] + currMax));
            maxSumSoFar = max(currMax, maxSumSoFar);
        }

        return maxSumSoFar;
    }
};