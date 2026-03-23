class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return 0;
                } else if(st.top() == '['){
                    if(s[i] == ']'){
                        st.pop();
                    }else{
                        return 0;
                    }
                } else if(st.top() == '{'){
                    if(s[i] == '}'){
                        st.pop();
                    }else{
                        return 0;
                    }
                } else if(st.top() == '('){
                    if(s[i] == ')'){
                        st.pop();
                    }else{
                        return 0;
                    }
                }
            }
        }

        return st.size() == 0;
    }
};