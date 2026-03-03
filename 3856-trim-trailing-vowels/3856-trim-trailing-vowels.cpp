class Solution {
public:
    string trimTrailingVowels(string s) {
        while (!s.empty()) {
            char c = s.back();
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                s.pop_back();
            else
                break;
        }
        return s;
    }
};