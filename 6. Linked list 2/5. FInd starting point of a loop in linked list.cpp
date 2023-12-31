/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:


    // ListNode *detectCycle(ListNode *head) {
    //     // ListNode tmp = head;
    //     // bool c = false;
    //     unordered_map<ListNode*,int> m;
    //     while(head){
    //         if(m[head]){
    //             return head;
    //         }
    //         else{
    //             m[head]++;
    //             head = head->next;
    //         }
    //     }

    //     // while(head){
    //     //     ListNode* tmp = head->next;
    //     //     while(tmp){
    //     //         if(tmp == head){
    //     //             return tmp;
    //     //         }
    //     //         tmp = tmp->next;
    //     //     }
    //     //     head = head->next;
    //     // }
    //     return nullptr;
    // }


    //TC-O(n), SC-O(1)
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL)  return NULL;
        ListNode* slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(head!=slow){
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }


    
};
