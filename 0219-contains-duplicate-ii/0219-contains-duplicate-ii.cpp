class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> val;

        for(int i = 0; i < nums.size(); i++){
            val[nums[i]].push_back(i);
        }

        for(auto &it : val){
            vector<int> &v = it.second;

            for(int i = 1; i < v.size(); i++){
                if(abs(v[i] - v[i-1] <= k)) return true;
            }
        }

        return false;
    }
};