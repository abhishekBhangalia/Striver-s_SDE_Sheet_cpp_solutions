
int maxProfit(vector<int> &value, vector<int> &weight, int n, int maxWeight) 
{
	if(n==1){
		return weight[0]<=maxWeight ? value[0] : 0;
	}

	vector<int> prevMaxValue(maxWeight+1,0),curMaxValue(maxWeight+1,0);
	// for(int i=0; i<n; i++){
	// 	maxValue[i][0] = 0;
	// }
	prevMaxValue[0] = 0;

	for(int rem_cap = 1; rem_cap<=maxWeight; rem_cap++){
		prevMaxValue[rem_cap] = weight[0]<=rem_cap ? value[0] : 0;
	}
	for(int item=1; item<n-1; item++){
		for(int rem_cap=1; rem_cap<=maxWeight; rem_cap++){
			int steal = weight[item]<=rem_cap ? value[item]+prevMaxValue[rem_cap-weight[item]] : 0;
			int not_steal = prevMaxValue[rem_cap];
			curMaxValue[rem_cap] = max(steal,not_steal);
		}
		prevMaxValue = curMaxValue;
	}
	int steal = weight[n-1]<=maxWeight ? value[n-1]+prevMaxValue[maxWeight-weight[n-1]] : 0;
	int not_steal = prevMaxValue[maxWeight];
	return max(steal,not_steal);
}
