#include <bits/stdc++.h>


struct t_node{
    t_node* links[26]; //because words only contains lowercase letters
    int freq = 0;
    int end_freq = 0;
    
    bool has_link(char c){
        return links[c - 'a'] != NULL;
    }

    t_node* get_link(char c){
        return links[c - 'a'];
    }

    void set_link(char c, t_node* link){
        links[c - 'a'] = link;
    }

    
    void incr_freq(){
        freq++;
    }

    void decr_freq(){
        freq--;
    }

    void incr_end_freq(){
        end_freq++;
    }

    void decr_end_freq(){
        end_freq--;
    }

    int get_freq(){
        return freq;
    }

    int get_end_freq(){
        return end_freq;
    }
};


class Trie{
    t_node* root;

    public:

    Trie(){
        root = new t_node();
    }

    void insert(string &word){
        int n = word.size();
        t_node* tmp = root;
        for(int i=0; i<n; i++){
            if(!tmp->has_link(word[i])){
                tmp->set_link(word[i], new t_node());
            }
            tmp = tmp->get_link(word[i]);
            tmp->incr_freq();
        }
        tmp->incr_end_freq();
    }

    int countWordsEqualTo(string &word){
        int n = word.size();
        t_node *tmp = root;
        for(int i=0; i<n; i++){
            if(!tmp->has_link(word[i])){
                return 0;
            }
            tmp = tmp->get_link(word[i]);
        }
        return tmp->get_end_freq();
    }

    int countWordsStartingWith(string &word){
        int n = word.size();
        t_node *tmp = root;
        for(int i=0; i<n; i++){
            if(!tmp->has_link(word[i])){
                return 0;
            }
            tmp = tmp->get_link(word[i]);
        }
        return tmp->get_freq();
    }


    // can delete the links also, but it is not required
    void erase(string &word){
        int n = word.size();
        // t_node *prev = root;
        t_node* tmp = root;
        for(int i=0; i<n; i++){
            // prev = tmp;
            tmp = tmp->get_link(word[i]);
            tmp->decr_freq();
            // if(tmp->get_freq() == 0){
            //     prev->set_link(word[i],NULL);
            // }
        }
        tmp->decr_end_freq();
    }
};

