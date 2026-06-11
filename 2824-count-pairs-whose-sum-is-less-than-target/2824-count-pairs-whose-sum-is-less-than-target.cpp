class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = nums.size() - 1;
        
        int count = 0;

        while(i < j){
            int sum = nums[i] + nums[j];

            if(sum < target){
                count += (j - i);
                i++;
            }else{
                j--;
            }
        }

        return count;
    }
};