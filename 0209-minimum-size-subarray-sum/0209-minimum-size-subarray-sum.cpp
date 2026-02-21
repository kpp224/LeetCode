class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int total_len = INT_MAX;
        int sum = 0;

        while(end < n){
            sum += nums[end];
            while(sum >= target){
                total_len = min(total_len,(end-start+1));
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return total_len != INT_MAX ? total_len : 0;

    }
};