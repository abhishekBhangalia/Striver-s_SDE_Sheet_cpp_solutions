#include <bits/stdc++.h>

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

// Recursion

// Time Complexity
// O(n * n* k), where ‘n’ denotes the size of the linked list and ‘k’ is the average number of child nodes for each of the n nodes. 
// Merging two lists of size ‘k’ takes O(k) time. Merging this list with another list of size ‘k’ takes O(2k) time. Thus merging ‘n’ lists takes a total of O(k+2k+3k+4k … +n-1k) = O((n * (n-1) *k)/2) = O(n * n * k) time.
// Hence the time complexity is O(n*n*k). 

// Space Complexity
// O(n*k), where ‘n’ denotes the size of the linked list and ‘k’ is the average number of child nodes for each of the n nodes. 
// Since for every call on a horizontal node each child sublist is also called so the stack in recursion will always consume n*k space.
// Hence the space complexity is O(n*k).



// Iterative , SC- O(1)?
// Node* flattenLinkedList(Node* head) 
// {
// 	// Write your code here
// 	Node* cur = head;
// 	while(cur and cur->next){
// 		Node *prev=NULL, *next = cur->next, *tmp1=cur, *tmp2=next;
// 		Node* next_nxt = next->next;
// 		if(tmp1->data > tmp2->data){
// 			Node* nxt_child = tmp2->child;
// 			// tmp2->next = NULL;
// 			tmp2->child = tmp1;
// 			tmp1->next = NULL;
// 			tmp1 = tmp2;
// 			prev = tmp2;
// 			tmp2 = nxt_child;
// 			cur = tmp1;
// 		}
// 		while(tmp1 and tmp2){
// 			if(tmp1->data > tmp2->data){
// 				Node* nxt_child = tmp2->child;
// 				tmp2->child = tmp1;
// 				prev->child = tmp2;
// 				prev = tmp2;
// 				tmp2 = nxt_child;
// 			}
// 			else{
// 				prev = tmp1;
// 				tmp1 = tmp1->child;
// 			}
// 		}
		
// 		if(tmp2){
// 			prev->child = tmp2;
// 		}
		
// 		next->next = NULL;
// 		next = next_nxt;
// 		cur->next = next;
// 	}
// 	return cur;
// }



// //Recursive
// Node* mergeLinkedList(Node* a, Node* b){
// 	Node* tmp = new Node(); // dummy node
// 	Node* res = tmp;
// 	if(a)	a->next = NULL;
// 	if(b)	b->next = NULL;

// 	while(a and b){
// 		if(a->data < b->data){
// 			tmp->child = a;
// 			tmp = tmp->child;
// 			a = a->child;
// 		}
// 		else{
// 			tmp->child = b;
// 			tmp = tmp->child;
// 			b = b->child;
// 		}
// 	}
// 	if(a)	tmp->child = a;
// 	if(b)	tmp->child = b;
// 	return res->child;
// }



// Node* flattenLinkedList(Node* head) {
// 	if(head == NULL or head->next == NULL)	return head;

// 	head->next = flattenLinkedList(head->next);
// 	head = mergeLinkedList(head,head->next);
// 	return head;
// }



// Time Complexity
// O( log(n) * (n * k)), where 'n’ denotes the size of the linked list and ‘k’ is the average number of child nodes for each of the n nodes.
// Since, every node in the linkedlist is traversed once and log(n) is the time taken to min-heapify the queue so the total complexity will be O(n * log(n)) + O(((n * k) - n) * log(n)) = O( log(n) * (n * k)) 

// Space Complexity
// O(n), where ‘n’ denotes the size of the linked list 
// Since we are using a priority queue to store the top horizontal nodes and at any instant heap will not contain more than n nodes.

Node* flattenLinkedList(Node* head) {
	priority_queue<pair<int,Node*>, vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
	Node* res = new Node();
	Node* tmp = res;
	
	while(head){
		Node* nxt = head->next;
		head->next = NULL;
		pq.push({head->data,head});
		head = nxt;
	}

	while(!pq.empty()){
		tmp->child = pq.top().second;
		tmp = tmp->child;
		pq.pop();
		if(tmp->child)    pq.push({tmp->child->data,tmp->child});
	}
	return res->child;
}

