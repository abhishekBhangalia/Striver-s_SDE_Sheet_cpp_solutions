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
    // //TC-O(n), SC-O(n)
    // bool hasCycle(ListNode *head) {
    //     unordered_set<ListNode*> set;
    //     while(head){
    //         if(set.find(head)  != set.end())    return true;
    //         set.insert(head);
    //         head = head->next;
    //     }
    //     return false;
    // }


    //TC-O(n), SC-O(1)
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)    return true;
        }
        return false;
    }


};



