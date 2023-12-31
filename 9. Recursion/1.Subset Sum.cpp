void rec(int i, int sum, vector<int>& a, vector<int>& subSum){
	if(i==-1){
		subSum.push_back(sum);
		return;
	}

	rec(i-1, sum, a, subSum);
	rec(i-1, sum + a[i], a, subSum); 
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	
	vector<int> ans;
	rec(num.size()-1, 0, num, ans);
	sort(ans.begin(), ans.end());
	
	return ans;	
}
