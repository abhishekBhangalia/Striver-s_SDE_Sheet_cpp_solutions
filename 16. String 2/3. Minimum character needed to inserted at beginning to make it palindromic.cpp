#include<vector>
using namespace std;


// //TC-O(n^2), SC-O(1)
// int minCharsforPalindrome(string str) {
// 	// Write your code here.
// 	int n = str.length();
// 	int i=0, j=n-1;
// 	for(;j>0; j--){
// 		int s=i, e=j;
// 		while(s<e){
// 			if(str[s] == str[e]){
// 				s++;	e--;
// 			}
// 			else	break;
// 		}
// 		if(s>=e)	return n-j-1; 	
// 	}
// 	return n-1;
// }

// TC-O(2n), SC-O(n)
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.length();
	for(int i=n-1; i>=0; i--){
		str.push_back(str[i]);
	}

	int n2 = 2*n;
	vector<int> lps(n2);
		
	for(int i=n; i<n2; i++){
		int j=lps[i-1];
		while(j>0 and str[i] != str[j])		j--;
		if(str[i] == str[j])	j++;
		lps[i] = j;
	}
	return n-lps[n2-1];
}



// int minCharsforPalindrome(string str) {
// 	// Write your code here.
// 	int n = str.length();
// 	str.push_back('$');
// 	for(int i=n-1; i>=0; i--){
// 		str.push_back(str[i]);
// 	}

// 	int n2 = 2*n+1;
// 	vector<int> lps(n2);
		
// 	for(int i=1; i<n2; i++){
// 		int j=lps[i-1];
// 		while(j>0 and str[i] != str[j])		j=lps[j-1];
// 		if(str[i] == str[j])	j++;
// 		lps[i] = j;
// 	}
// 	return n-lps[n2-1];
// }



