class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int a = nums[i];
            int target = -a;

            int l = i+1;
            int r = n-1;

            while(l < r){
                if(nums[l] + nums[r] == target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l+1] == nums[l]){
                        l++;
                    }
                    while(l < r && nums[r-1] == nums[r]){
                        r--;
                    }
                    l++, r--;
                }else if(nums[l] + nums[r] > target){
                    r--;
                }else{
                    l++;
                }
            }

            while(i+1 < n && nums[i+1] == nums[i]){
                i++;
            }
        }

        return ans;
    }
};