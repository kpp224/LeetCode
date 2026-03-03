class Solution {
public:
    string largestEven(string s) {
    int lastTwo = -1;
    
    // Find the last occurrence of '2'
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '2') {
            lastTwo = i;
            break;
        }
    }
    
    // If no '2' found, no even number possible
    if (lastTwo == -1) return "";
    
    // Keep everything up to the last '2'
    return s.substr(0, lastTwo + 1);
}
};