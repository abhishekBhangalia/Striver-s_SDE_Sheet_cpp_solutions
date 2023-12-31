#include <bits/stdc++.h> 

void rec(int i, string& s, string sentence,  unordered_map<string,int>& dic, vector<string>& ans){
    int n = s.size();
    if(i==n){
        ans.push_back(sentence);
        return;
    }
    string word = "";
    for(int j=i; j<n; j++){
        word.push_back(s[j]);
        if(dic[word]){
            rec(j+1, s, sentence + word + ' ', dic, ans);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    int n = dictionary.size();
    unordered_map<string, int> map;
    for(int i=0; i<n; i++){
        map[dictionary[i]] = 1;
    }
    string sentence;
    vector<string> ans;
    rec(0, s, "", map, ans);
    return ans;
}
