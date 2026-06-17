class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }

        vector<pair<int,int>> freq;

        for(auto &x : m){
            freq.push_back({x.second,x.first});
        }

        sort(freq.rbegin(),freq.rend());

        for(int i = 0; i < k; i++){
            ans.push_back(freq[i].second);
        }
        
        return ans;
    }
};