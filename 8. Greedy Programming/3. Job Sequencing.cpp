#include <bits/stdc++.h>

bool comparator(vector<int>& job1, vector<int>& job2){
    return (job1[2] > job2[2]);
}

/*
Time Complexity
O(N * maxDeadline), where ‘N’ denotes the number of elements of the array “jobs,” and ‘maxDeadline’ is the maximum available deadline among all the jobs.

As for every index of the array “jobs”, we may have to search for all the indices of the array “slots”. Hence, the time complexity in the worst case will be O(N * maxDeadline).

Space Complexity
O(maxDeadline), where ‘maxDeadline’ is the maximum available deadline among all the jobs.

The slots array/list has a size of maxDeadline.
*/


vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    
    //sort in descending order of profits
    sort(jobs.begin(),jobs.end(),comparator);

    int max_deadline = 0;
    for(int i=0; i<n; i++){
        max_deadline = max(jobs[i][1], max_deadline);
    }
    // int m[max_deadline+1]={0};

    int m[max_deadline+1]={0};
    
    int job = 0, profit = 0;
    for(int i=0; i<n; i++){
        for(int j=jobs[i][1]; j>0; j--){
            if(m[j]==0){
                m[j] = jobs[i][2];
                profit += jobs[i][2];
                job++;
                break;
            }
        }
        // if(job == max_deadline) break;
    }
    
    return {job,profit};
}

