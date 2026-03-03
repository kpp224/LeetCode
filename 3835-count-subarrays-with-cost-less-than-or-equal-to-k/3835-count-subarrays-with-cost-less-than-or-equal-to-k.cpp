class Solution {
public:

    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        deque<int> maxdq, mindq;   // store indices
        long long ans = 0;
        
        int l = 0;
        
        for (int r = 0; r < n; r++) {
            
            // Maintain max deque (decreasing)
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r])
                maxdq.pop_back();
            maxdq.push_back(r);
            
            // Maintain min deque (increasing)
            while (!mindq.empty() && nums[mindq.back()] >= nums[r])
                mindq.pop_back();
            mindq.push_back(r);
            
            // Shrink window if cost > k
            while (!maxdq.empty() && !mindq.empty() &&
                (long long)(nums[maxdq.front()] - nums[mindq.front()]) 
                * (r - l + 1) > k) {
                
                if (maxdq.front() == l) maxdq.pop_front();
                if (mindq.front() == l) mindq.pop_front();
                l++;
            }
            
            // All subarrays ending at r and starting from l to r are valid
            ans += (r - l + 1);
        }
        
        return ans;
    }
};