#include <bits/stdc++.h>

//TC-O(n), SC-O(1)

void immediateSmaller(vector<int>& a)
{
	// Write your code here.
	int n = a.size();
	for(int i=0; i<n-1; i++){
		if(a[i+1]<a[i])		a[i]=a[i+1];
		else	a[i] = -1;
	}
	a[n-1] = -1;
}





