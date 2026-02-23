class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int sum = 0;
        int minLen = INT_MAX;
        int end = 0;

        while(end < n){
            sum += nums[end];

            while(sum >= target){
                minLen = min(minLen,(end-start+1));
                sum -= nums[start];
                start++;
            }

            end++;
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};