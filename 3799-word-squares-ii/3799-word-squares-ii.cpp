class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        sort(words.begin(), words.end());  // for lexicographic order
        
        unordered_map<string, vector<string>> prefixMap;
        
        // Build prefix map
        for (auto &word : words) {
            for (int i = 0; i <= 4; i++) {
                prefixMap[word.substr(0, i)].push_back(word);
            }
        }
        
        for (auto &top : words) {
            for (auto &left : prefixMap[string(1, top[0])]) {
                if (left == top) continue;
                
                for (auto &right : prefixMap[string(1, top[3])]) {
                    if (right == top || right == left) continue;
                    
                    for (auto &bottom : prefixMap[string(1, left[3])]) {
                        if (bottom == top || bottom == left || bottom == right) continue;
                        
                        if (bottom[3] == right[3]) {
                            ans.push_back({top, left, right, bottom});
                        }
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());  // ensure final lexicographic order
        return ans;
    }
};