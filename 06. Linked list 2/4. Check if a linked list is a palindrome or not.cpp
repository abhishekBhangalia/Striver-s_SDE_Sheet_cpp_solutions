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

    // //TC-O(n+n/2), SC-O(n)
    // bool isPalindrome(ListNode* head) {
    //     vector<int> a; 
    //     while(head){
    //         a.push_back(head->val);
    //         head = head->next;
    //     }
    //     int n=a.size();
    //     for(int i=0; i<n/2; i++){
    //         if(a[i]!=a[n-1-i]){
    //             return false;
    //         }
    //     }
    //     return true; 
    // }


    //TC-O(n+n/2), SC-O(1)
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* reversed_list = reverseList(mid->next);
        
        while(reversed_list){
            
            if(reversed_list->val != head->val)    return false;
            reversed_list = reversed_list->next;
            head = head->next;
        }
        return true; 
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
