class Solution {
    stack<char> st;
public:
    bool isValid(string s) {
        for(char c:s){
            if(c==')'){
                if(st.empty())  return false;
                if(st.top() != '(')   return false;
                st.pop();
            }
            else if(c=='}'){
                if(st.empty())  return false;
                if(st.top() != '{')   return false;
                st.pop();
            }
            else if(c==']'){
                if(st.empty())  return false;
                if(st.top() != '[')   return false;
                st.pop();
            }
            else    st.push(c);
        }
        if(st.size())   return false;
        return true;
    }
};
