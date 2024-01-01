#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

// //TLE, TC- <O(2n^2), SC-O(n)
// int findCelebrity(int n) {
//  	// Write your code here.
// 	int celeb = -1;
// 	for(int i=0; i<n; i++){
// 		bool known_to_all = true;
// 		for(int j=0; j<n; j++){
// 			if(i!=j and not knows(j,i)){
// 				known_to_all = false;
// 				break;
// 			}
// 		}
// 		if(known_to_all){
// 			celeb = i;
// 			bool knows_any = false;
// 			for(int j=0; j<n; j++){
// 				if(celeb!=j and knows(celeb,j)){
// 					knows_any = true;
// 					break;
// 				}
// 			}
// 			if(not knows_any)	return celeb;
// 		}
// 	}
	
// 	return -1;
	
// }


// //TLE TC-O(n^2 + n), SC-O(2n)
// int findCelebrity(int n) {
//  	// Write your code here.
// 	vector<int> no_people_known_by(n), known_by_how_much(n); 
// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<n; j++){
// 			if(i!=j and knows(i,j)){
// 				no_people_known_by[i]++;
// 				known_by_how_much[j]++;
// 			}
// 		}
// 	}
// 	for(int i=0; i<n; i++){
// 		if(no_people_known_by[i]==0 and known_by_how_much[i]==n-1)	return i;
// 	}
	
// 	return -1;
	
// }



// // Stack, TC-O(3n), SC-O(n)
// int findCelebrity(int n) {
//  	// Write your code here.
// 	stack<int> st;
// 	for(int i=0; i<n; i++){
// 		st.push(i);
// 	}
// 	while(st.size()>1){
// 		int i = st.top();
// 		st.pop();
// 		int j = st.top();
// 		st.pop();
// 		if(knows(i,j))	st.push(j);
// 		else	st.push(i);
// 	}

	// int celeb = st.top();
	// bool knows_any=false;
	// for(int i=0; i<n; i++){
	// 	if(knows(celeb,i)){
	// 		knows_any = true;
	// 		break;
	// 	}
	// }
	// if(knows_any)	return -1;

	// bool known_to_all = true;
	// for(int i=0; i<n; i++)
	// 	if(i!=celeb and not knows(i,celeb))		return -1;
			
// 	return celeb;
	
// }


//Two Pointer, TC-O(n), SC-O(1)
int findCelebrity(int n) {
	int f=0,r=n-1;
	while(f<r){
		if(knows(f,r))	f++;
		else	r--;
	}

	int celeb = f;
	bool knows_any=false;
	for(int i=0; i<n; i++){
		if(knows(celeb,i)){
			knows_any = true;
			break;
		}
	}
	if(knows_any)	return -1;

	bool known_to_all = true;
	for(int i=0; i<n; i++)
		if(i!=celeb and not knows(i,celeb))		return -1;
	
	return celeb;
}




