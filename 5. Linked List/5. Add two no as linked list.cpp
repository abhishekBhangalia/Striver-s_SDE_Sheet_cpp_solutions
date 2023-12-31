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

    // //TC-O(n), SC-O(n), where n is max(llsize1, llsize2)

    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     ListNode* ans = new ListNode();
    //     ListNode* cur = ans;
    //     ListNode *tmp1 = l1;
    //     ListNode *tmp2 = l2;

    //     int carry = 0;
    //     while(l1 and l2){
    //         int sum = l1->val + l2->val + carry;
    //         cur->next = new ListNode(sum%10) ;
    //         cur = cur->next;
    //         carry = sum/10;
    //         l1 = l1->next;
    //         l2 = l2->next;
    //     }
    //     while(l1){
    //         int sum = l1->val + carry;
    //         cur->next = new ListNode(sum%10);
    //         cur = cur->next;
    //         carry = sum/10;
    //         l1 = l1->next;
    //     }
    //     while(l2){
    //         int sum = l2->val + carry;
    //         cur->next = new ListNode(sum%10);
    //         cur = cur->next;
    //         carry = sum/10;
    //         l2 = l2->next;
    //     }
            
    //     if(carry!=0){
    //         cur->next = new ListNode(carry);
    //     }
    //     delete tmp1;
    //     delete tmp2;
    //     return ans->next;
        
    // }



    // TC-O(n), SC-O(1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* tmp1 = l1;
        ListNode* prev;
        ListNode* res = l2;
        while(l1 and l2){
            int sum = l1->val + l2->val + carry;
            l2->val = sum%10;
            carry = sum/10;
            prev = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            prev->next = l1;
            l2 = l1;
        }
        while(l2){
            int sum = l2->val + carry;
            l2->val = sum%10;
            carry = sum/10;
            prev = l2;
            l2 = l2->next;
        }
            
        if(carry!=0){
            prev->next = new ListNode(carry);
        }
        delete tmp1; // deleting the ll1 decreases runtime ?
        return res;
    }
};
