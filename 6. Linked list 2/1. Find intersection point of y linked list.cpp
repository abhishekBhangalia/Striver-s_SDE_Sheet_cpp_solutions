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

    // //Hashing, TC-O(n1+n2), SC-O(n1), n1>n2
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_set<ListNode*> hash;
    //     while(headA){
    //         hash.insert(headA);
    //         headA = headA->next;
    //     }

    //     while(headB){
    //         if(hash.find(headB) != hash.end()){
    //             return headB;
    //         }
    //         headB = headB->next;
    //     }
    //     return NULL;
    // }

    // //Hashing, TC-O(2n1), SC-O(1), n1>n2
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* tmpA = headA, *tmpB = headB;
    //     int sizeA = 0,sizeB = 0;
        
    //     while(tmpA || tmpB){
             
    //         if(tmpA){
    //             tmpA = tmpA->next;
    //             sizeA++;
    //         }
    //         if(tmpB){
    //             tmpB = tmpB->next;
    //             sizeB++;
    //         }

    //     }
    //     int diff = abs(sizeA-sizeB);
    //     if(sizeA>sizeB){
    //         tmpA = headA;
    //         tmpB = headB;
    //     }
    //     else{
    //         tmpA = headB;
    //         tmpB = headA;
    //     }
    //     while(diff--){
    //         tmpA = tmpA->next;
    //     }
    //     while(tmpA){
    //         if(tmpA == tmpB){
    //             return tmpA;
    //         }
    //         tmpA = tmpA->next;
    //         tmpB = tmpB->next;
    //     }
    //     return NULL;
    // }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* tmpA = headA, *tmpB = headB;
        
    //     while(tmpA && tmpB){
    //         tmpA = tmpA->next;
    //         tmpB = tmpB->next;
    //     }
    //     if(tmpA){
    //         tmpB = headA;
    //     }
    //     else{
    //         tmpA = headB;
    //     }
    //     while(tmpA && tmpB){
    //         tmpA = tmpA->next;
    //         tmpB = tmpB->next;
    //     }
    //     if(tmpA){
    //         tmpB = headA;
    //     }
    //     else{
    //         tmpA = headB;
    //     }
    //     while(tmpA && tmpB){
    //         if(tmpA == tmpB){
    //             return tmpA;
    //         }
    //         tmpA = tmpA->next;
    //         tmpB = tmpB->next;
    //     }
    //     return NULL;
    // }


    // TC-O(2n1), SC-O(1), n1>n2
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB == NULL)  return NULL;

        ListNode *a=headA, *b=headB;
        
        while(a!=b){
            a = a==NULL ? headB : a->next;
            b = b==NULL ? headA : b->next;
        }
        return a;
    }
};
