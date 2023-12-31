/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    // //TC-O(2*n)or O(2*n*log n), SC-O(n)
    // Node* copyRandomList(Node* head) {
    //     Node* res = new Node(0);
    //     Node* cur = res;
    //     Node* tmp = head;
    //     unordered_map<Node*,Node*> map;
    //     while(tmp){
    //         cur->next = new Node(tmp->val);
    //         cur = cur->next;
    //         map[tmp] = cur;
    //         tmp = tmp->next;
    //     }

    //     tmp = head;
    //     cur = res->next;
    //     while(tmp){
    //         if(tmp->random){
    //             cur->random = map[tmp->random];
    //         }
    //         tmp = tmp->next;
    //         cur = cur->next;
    //     }
    //     return res->next;
    // }


    //TC-O(3*n), SC-O(1)
    Node* copyRandomList(Node* head) {
        if(head==NULL)  return NULL;
        Node* tmp = head;

        while(tmp){
            Node* nxt = tmp->next;
            tmp->next = new Node(tmp->val);
            tmp->next->next = nxt;
            tmp = nxt;
        }

        tmp = head;
        while(tmp){
            if(tmp->random)
                tmp->next->random = tmp->random->next;
            tmp = tmp->next->next;
        }

        tmp = head;
        Node* res = head->next;
        Node* tmp2 ;
        while(tmp){
            tmp2 = tmp->next;
            Node* nxt = tmp2->next;
            tmp->next = nxt;

            if(nxt)    tmp2->next = tmp2->next->next;
            tmp = nxt;
        }
        return res;

    }

};
