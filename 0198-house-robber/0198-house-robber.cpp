class Solution {
public:
    int Robber(int index, vector<int> &dp, vector<int> &nums){
        if(index == 0)
        return nums[0];

        if(index == 1)
        return max(nums[0],nums[1]);

        if(dp[index] != -1)
        return dp[index];

        return dp[index] = max(nums[index] + Robber(index-2,dp,nums), Robber(index-1,dp,nums));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        return Robber(n-1,dp,nums);
    }
};