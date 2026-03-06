class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        return 0;

        vector<int> ele;

        for(int i = 0; i < nums.size(); i++){
            ele.push_back(nums[i]);
        }

        sort(ele.begin(),ele.end());

        int ans = 0;
        int temp = 1;

        for(int i = 1; i < ele.size(); i++){
            if(ele[i] == ele[i - 1]){
                continue;
            }else if(ele[i] - ele[i - 1] == 1){
                temp++;
            } else {
                ans = max(ans,temp);
                temp = 1;
            }
        }

        ans = max(ans,temp);

        return ans;
    }
};