class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();

        string word="";
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                word.push_back(s[i]);
            }
            else if(word.length()){
                st.push(word);
                word = "";
            }
        }
        if(word.length()){
            st.push(word);
            word = "";
        }
        while(not st.empty()){
            word += (st.top());
            st.pop();
            word.push_back(' ');
        }
        word.pop_back();
        return word;
    }
};
