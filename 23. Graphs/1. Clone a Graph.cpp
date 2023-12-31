/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:

    // void rec(Node* node, unordered_map<Node*, Node*>& copy){
    //     if(node and copy.count(node) == 0){
    //         copy[node] = new Node(node->val);
    //         for(int i=0; i < node->neighbors.size(); i++){
    //             rec(node->neighbors[i], copy);
    //             copy[node]->neighbors.push_back(copy[node->neighbors[i]]);
    //         }
    //     }
    // }


    // Node* cloneGraph(Node* node) {
    //     //using unordered_map because all addresses are unique
    //     unordered_map<Node*, Node*> copy;
    //     rec(node, copy);
    //     return copy[node];
    // }


    //Optimising further for given input constraints
    //1<=Node.val<=100
    //Node.val is unique for each node
    //no of nodes is in range [0-100]
     void rec(Node* node, Node** copy){
        if(node and copy[node->val] == NULL){
            copy[node->val] = new Node(node->val);
            for(int i=0; i < node->neighbors.size(); i++){
                rec(node->neighbors[i], copy);
                copy[node->val]->neighbors.push_back(copy[node->neighbors[i]->val]);
            }
        }
    }


    Node* cloneGraph(Node* node) {
        //using unordered_map because all addresses are unique
        if(node == NULL){
            return NULL;
        }
        Node* copy[101];
        for(int i=0; i<=100; i++){
            copy[i] = NULL;
        }
        rec(node, copy);
        return copy[node->val];
    }


};
