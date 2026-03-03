class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        long long score[2] = {0, 0};
        int active = 0; // 0 = first player, 1 = second player
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] % 2 == 1)  // odd check
                active ^= 1;
                
            if (i % 6 == 5)       // every 6th game
                active ^= 1;
            
            score[active] += nums[i];
        }
        
        return score[0] - score[1];
    }
};