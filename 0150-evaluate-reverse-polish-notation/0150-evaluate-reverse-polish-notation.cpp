class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*"){
                st.push(stoi(tokens[i]));
            }else{
                int firTop = st.top();
                st.pop();
                int secTop = st.top();
                st.pop();

                int ans;

                if(tokens[i] == "+")
                    ans = secTop + firTop;
                else if(tokens[i] == "-")
                    ans = secTop - firTop;
                else if(tokens[i] == "*")
                    ans = secTop * firTop;
                else
                    ans = secTop / firTop;

                st.push(ans);
            }
        }

        return st.top();
    }
};