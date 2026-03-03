class Solution {
public:
    bool isDigitorialPermutation(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        vector<string> digitorial = {"1", "2", "145", "40585"};
        
        for (string &num : digitorial) {
            string t = num;
            sort(t.begin(), t.end());
            if (s == t) return true;
        }
        
        return false;
    }
};