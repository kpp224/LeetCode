class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[left] < nums[right]){
                swap(nums[left],nums[right]);
                left++;
            }
        }

        
    }
};