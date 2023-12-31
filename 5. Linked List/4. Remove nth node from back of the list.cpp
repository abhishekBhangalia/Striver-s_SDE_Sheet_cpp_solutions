/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // //TC-O(n/2 + n/2), SC-O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int size = 0;
    //     ListNode* tmp = head;
    //     if(tmp->next == nullptr)    size =1;

    //     while(tmp and tmp->next){
    //         tmp = tmp->next->next;
    //         size += 2;
    //     }
    //     size++;
    //     if(tmp == nullptr)  size--;

    //     if(size == n)   return head->next;
        

    //     int double_steps = (size-n-1)/2;
    //     int single_steps = (size-n-1)%2;
    //     // single_steps--;

    //     tmp = head;
    //     while(double_steps>0){
    //         double_steps--;
    //         tmp = tmp->next->next;
    //     }
    //     while(single_steps>0){
    //         single_steps--;
    //         tmp = tmp->next;
    //     }
    //     if (tmp->next)
    //         tmp->next = tmp->next->next;
    //     else    return nullptr;
    //     return head;
    // }


    // //TC-O(n), SC-O(1)
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode *slow=head,*fast=head;
    //     int size=1;
    //     int tmp = n;

    //     while(n-- and fast->next){
    //         fast = fast->next;
    //         size++;
    //     }
    //     while(fast->next){
    //         size++;
    //         fast = fast->next;
    //         slow = slow->next;
    //     }
    //     if(size == tmp)    return head->next;
    //     slow->next = slow->next->next;

    //     return head;
    // }


    //TC-O(n), SC-O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode *slow=start,*fast=start;

        while(n--)  fast = fast->next;
            
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return start->next;
    }



    
};
