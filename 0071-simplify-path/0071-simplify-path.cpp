class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";

        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(temp == "" || temp == "."){
                    // ignore
                }else if(temp == ".."){
                    if(!st.empty()) st.pop();
                }else{
                    st.push(temp);
                }

                temp = "";
            }else {
                temp += path[i];
            }
        }

        if(temp == ".."){
            if(!st.empty()) st.pop();
        }else if(temp != "" && temp != "."){
            st.push(temp);
        }

        vector<string> res;

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());

        string ans = "";

        for(string dir : res){
            ans += "/" + dir;
        }

        return ans.empty() ? "/" : ans;
    }
};