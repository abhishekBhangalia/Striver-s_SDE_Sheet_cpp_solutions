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

class Trie {
    t_node *root;


public:

    Trie() {
        root = new t_node();
    }
    
    //tc-O(n)
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
    bool search(string word) {
        int n = word.size();
        t_node *tmp = root;
        for(int i=0; i<n; i++){
            if(!tmp->has_link(word[i])){
                return false;
            }
            tmp = tmp->get_link(word[i]);
        }
        return tmp->is_end();
    }
    
    //tc-O(n)
    bool startsWith(string prefix) {
        int n = prefix.size();
        t_node *tmp = root;
        for(int i=0; i<n; i++){
            if(!tmp->has_link(prefix[i])){
                return false;
            }
            tmp = tmp->get_link(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
