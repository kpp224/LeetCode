class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = n;

        vector<int> v;
        vector<int> v1;
        vector<int> res;

        for(int i = 0; i < size; i++){
            v.push_back(nums[i]);
        }

        for(int i = size; i < n*2; i++){
            v1.push_back(nums[i]);
        }

        for(int i = 0; i < n; i++){
            res.push_back(v[i]);
            res.push_back(v1[i]);
        }

        return res;
    }
};