#include <bits/stdc++.h> 

struct t_node{
    t_node* links[26]; //because words only contains lowercase letters
    bool end = false;
    bool has_link(char c){
        return links[c - 'a'] != NULL;
    }

    t_node* get_link(char c){
        return links[c - 'a'];
    }

    void set_link(char c, t_node* link){
        links[c - 'a'] = link;
    }

    bool is_end(){
        return end;
    }

    void set_end(){
        end = true;
    }
};

t_node *root;

void insert(string word) {
    int n = word.size();
    t_node* tmp = root;
    for(int i=0; i<n; i++){
        if(!tmp->has_link(word[i])){
            tmp->set_link(word[i], new t_node());
        }
        tmp = tmp->get_link(word[i]);
    }
    tmp->set_end();
}

//tc-O(n)
// bool search(string word) {
//     int n = word.size();
//     t_node *tmp = root;
//     for(int i=0; i<n; i++){
//         if(!tmp->has_link(word[i])){
//             return false;
//         }
//         tmp = tmp->get_link(word[i]);
//     }
//     return tmp->is_end();
// }

bool is_complete(string s){
    int n = s.size(); 
    t_node* tmp = root;
    for(int i=0; i<n; i++){
        tmp = tmp->get_link(s[i]);
        if(!tmp->is_end())  return false;
    }
    return true;
}

//tc-O(n)
// bool startsWith(string prefix) {
//     int n = prefix.size();
//     t_node *tmp = root;
//     for(int i=0; i<n; i++){
//         if(!tmp->has_link(prefix[i])){
//             return false;
//         }
//         tmp = tmp->get_link(prefix[i]);
//     }
//     return true;
// }

//tc-O(2*sum of len of all strings in a), sc-O(2*sum of len of all strings in a)
string completeString(int n, vector<string> &a){
    root = new t_node();
    string cmplt_str="";
    for(string s:a) insert(s);
    for(string s:a){
        if(is_complete(s)){
            if(s.size()>cmplt_str.size())
                cmplt_str = s;
            else if(s.size() == cmplt_str.size()){
                if(s<cmplt_str)    cmplt_str = s;
            }
        }
    }
    if(cmplt_str=="")   return "None";
    return cmplt_str;
}
