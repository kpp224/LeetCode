class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;

        for(char c : t)
        need[c]++;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;
        int formed = 0;
        int required = need.size();
        
        unordered_map<char,int> window;

        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;

            if(need.count(c) && need[c] == window[c])
            formed++;

            while(formed == required){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if(need.count(leftChar) && window[leftChar] < need[leftChar]){
                    formed--;
                }

                left++;
            }
        }

        if(minLen == INT_MAX){
            return "";
        }

        return s.substr(start,minLen);

    }
};