class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 1, l = 1;
        int atmost = 1;
        int count = 1;

        while(r < nums.size()){
            if(nums[r] == nums[r-1]){
                if(atmost < 2){
                    count++;
                    nums[l] = nums[r];
                    l++, r++;
                    atmost++;
                }else{
                    r++;
                }
            }else{
                atmost = 1;
                nums[l] = nums[r];
                l++, r++;
                count++;
            }
        }

        return count;
    }
};