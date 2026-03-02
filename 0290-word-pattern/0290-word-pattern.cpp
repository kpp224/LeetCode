class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mapPS;
        unordered_map<string,char> mapSP;

        int a = 0;

        for(int i = 0; i < pattern.length(); i++){
            if(a >= s.length())
            return false;

            char c = pattern[i];
            string str = "";
            while(a < s.length() && s[a] != ' '){
                str += s[a];
                a++;
            }
            a++;

            if(mapPS.count(c)){
                if(mapPS[c] != str)
                return false;
            } else {
                mapPS[c] = str;
            }

            if(mapSP.count(str)){
                if(mapSP[str] != c)
                return false;
            } else {
                mapSP[str] = c;
            }

        }

        if(a < s.length())
        return false;

        return true;
    }
};