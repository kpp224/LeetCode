class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;
        
        for (int x : nums) {
            st.push_back(x);
        
            while (st.size() >= 2) {
                int n = st.size();
                if (st[n - 1] == st[n - 2]) {
                    long long sum = st[n - 1] + st[n - 2];
                    st.pop_back();
                    st.pop_back();
                    st.push_back(sum);
                } else {
                    break;
                }
            }
        }
        
        return st;
    }
};