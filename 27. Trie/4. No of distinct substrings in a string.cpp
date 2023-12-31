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

int distinct_substr = 0;

void insert(string word) {

    int n = word.size();
    t_node* tmp = root;
    for(int i=0; i<n; i++){
        if(!tmp->has_link(word[i])){
            distinct_substr++;
            tmp->set_link(word[i], new t_node());
        }
        tmp = tmp->get_link(word[i]);
    }
    tmp->set_end();
}

int countDistinctSubstrings(string &s)
{
    root = new t_node();
    distinct_substr = 0;
    string tmp = "";
    string tmp2 = "";
    int n = s.size();
    for(int i=0; i<n; i++){
        tmp.push_back(s[i]);
        tmp2 = s.substr(n-1-i);
        insert(tmp);
        insert(tmp2);
    }
    return distinct_substr+1;//+1 for empty string
}

