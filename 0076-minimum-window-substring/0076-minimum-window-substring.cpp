class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;

        for(char c : t){
            need[c]++;
        }

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;
        int formed = need.size();
        int required = 0;

        unordered_map<char,int> window;

        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;

            if(need[c] && need[c] == window[c])
            required++;

            while(required == formed){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                int leftChar = s[left];
                window[leftChar]--;

                if(need[leftChar] && window[leftChar] < need[leftChar])
                required--;

                left++;
            }
        }

        if(minLen == INT_MAX) return "";

        return s.substr(start,minLen);
    }
};