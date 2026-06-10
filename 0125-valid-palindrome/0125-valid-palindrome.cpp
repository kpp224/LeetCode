class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";

        for(char c : s){
            if(isalnum(c)){
                newString += tolower(c);
            }
        }

        int i = 0;
        int j = newString.size() - 1;

        while(i < j){
            if(newString[i] != newString[j]){
                return false;
            }

            i++;
            j--;
        }

        return true;

    }
};






