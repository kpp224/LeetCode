class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);

        for(int i = 0; i < nums.size()-1; i++){
            bool flag = false;

            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans[0] = i;
                    ans[1] = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        return ans;
    }
};