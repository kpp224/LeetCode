class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0],nums[1]);

        int curr;
        int prev = max(nums[0],nums[1]);
        int prev1 = nums[0];

        for(int i = 2; i < n; i++){
            curr = max(nums[i] + prev1, prev);
            prev1 = prev;
            prev = curr;
        }

        return curr;
    }
};