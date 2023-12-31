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

    // //TC-O(k*n)+O(n), SC-O(1)
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(head==NULL or head->next == NULL)    return head;

    //     int size = 0;
    //     ListNode* tmp = head;
    //     while(tmp){
    //         size++;
    //         tmp = tmp->next;
    //     }
    //     k = k%size;

    //     while(k-- and head and head->next){
    //         ListNode* tmp = head->next;
    //         ListNode* prev = head;
    //         ListNode* prev2 = NULL;
    //         while(tmp){
    //             prev2 = prev;
    //             prev = tmp;
    //             tmp = tmp->next;
    //         }
    //         prev2->next = NULL;
    //         prev->next = head;
    //         head = prev;
    //     }
    //     return head;
    // }


    //TC-O(n)+O(n-(k%n)), SC-O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next == NULL)    return head;

        int size = 1;
        ListNode* tmp = head;
        
        while(tmp->next){
            size++;
            tmp = tmp->next;
        }
        tmp->next = head;
        k = k%size;
        tmp = head;
        int n = (size-k)-1;

        while(n--)  tmp = tmp->next;

        head = tmp->next;
        tmp->next = NULL;
        
        return head;
    }
};
