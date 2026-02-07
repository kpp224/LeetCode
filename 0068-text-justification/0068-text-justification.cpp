class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;

        while(i < words.size()){
            int j = i;
            int letters = 0;

            while(j < words.size() && letters + words[j].size() + (j-i) <= maxWidth){
                letters += words[j].size();
                j++;
            }

            int space = maxWidth - letters;
            int gap = j - i - 1;
            string line = "";

            if(j == words.size() || gap == 0){
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k < j - 1){
                        line += " ";
                    }
                }

                while(line.size() < maxWidth) line += " ";
            }
            else{
                int eachSpace = space / gap;
                int extraSpace = space % gap;

                for(int k = i; k < j; k++){
                    line += words[k];

                    if(k < j - 1){
                        int s = eachSpace;
                        if(extraSpace > 0){
                            s++;
                            extraSpace--;
                        }
                        line += string(s, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};







