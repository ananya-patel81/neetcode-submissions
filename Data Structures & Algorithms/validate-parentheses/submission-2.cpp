class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        int m = s.length();
        stack<char> st;
        for(int i=0;i<m;i++){
            char ch = s[i];
            if((ch=='(') || (ch=='{') || (ch=='[')){
                st.push(ch);
            }
            else if(!st.empty()){
                char ch_top = st.top();
                if(ch_top=='(' && ch==')'){
                    st.pop();
                }
                else if(ch_top=='{' && ch=='}'){
                    st.pop();
                }
                else if(ch_top == '[' && ch==']'){
                    st.pop();
                }
                else return false;
            }
            else return false;
        }

        return (st.empty());

        
    }
};
