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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans,*last=nullptr,*prev=nullptr,*prev_group=nullptr,*cur=head,*next=nullptr;

        int n = k;
        last = cur;
        while(n--){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ans = prev;
        last->next = cur;
        prev_group = last;

        while(cur){
            n = k;
            prev_group = last;
            last = cur;
            prev = nullptr;
            while(n and cur){
                n--;
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            

            if(n>0){ // remaining elements were less than k
                cur = prev;
                prev = nullptr;
                while(cur){
                    next = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                }
                prev_group->next = prev;
                break;
            }
            else{
                last->next = cur;
                prev_group->next = prev;
            }
        }

        return ans;


        // ListNode *cursor = head;
        // for(int i=0; i<k; i++){
        //     if(cursor == NULL)return head;
        //     cursor= cursor->next;
        // }
        // if (head == NULL) return NULL;
        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // ListNode* next = NULL;
        // int count = 0;
        // while(curr!=NULL && count<k){
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        //     count++;
        // }
        // if(next!=NULL){
        //     head->next = reverseKGroup(next, k);
        // }
        // return prev;
    }
};
