class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Count frequency of frequencies
        unordered_map<int, int> freqCount;
        for (auto &p : freq) {
            freqCount[p.second]++;
        }
        
        // Step 3: Find first element with unique frequency
        for (int num : nums) {
            if (freqCount[freq[num]] == 1) {
                return num;
            }
        }
        
        return -1;
    }
};