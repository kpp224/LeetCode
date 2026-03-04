class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> val;

        for(int i = 0; i < nums.size(); i++){
            val[nums[i]].push_back(i);
        }

        for(auto it = val.begin(); it != val.end(); it++){
            for(int i = 1; i < it->second.size(); i++){
                if(abs(it->second[i] - it->second[i - 1]) <= k){
                    return true;
                }
            }
        }

        return false;
    }
};