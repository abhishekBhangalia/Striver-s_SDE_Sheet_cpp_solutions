#include <bits/stdc++.h> 

// TC-O(2(r-l+1)), SC-O(r-l+1)
int merge(long long * arr, int l, int m, int r){
    int cnt = 0;
    vector<int> tmp;
    int i = l;
    int j = m+1;

    while(i<=m and j<=r){
        if(arr[i] < arr[j]){
            
            tmp.push_back(arr[i++]);
        }
        else{
            tmp.push_back(arr[j++]);
            cnt += m-i+1;
        }
    }

    while(i<=m) tmp.push_back(arr[i++]);
    while(j<=r) tmp.push_back(arr[j++]);
        
    for(int i=l; i<=r; i++){
        arr[i] = tmp[i-l];
    }
    return cnt;
}


// TC-O(2n log n), SC-O(n)
int mergeSort(long long * arr, int l, int r) {
    // Write Your Code Here
    int cnt = 0;
    if(l<r){
        int m = (l+r)/2;
        cnt += mergeSort(arr,l,m);
        cnt += mergeSort(arr,m+1,r);
        cnt += merge(arr,l,m,r);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int inversions = mergeSort(arr, 0, n-1);
    return inversions;
}


//TC-O(n^2), SC-O(1)
// long long getInversions(long long *arr, int n){
//     // Write your code here.
//     int ans = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[j] < arr[i])     ans++;
//         }
//     }
//     return ans;
// }
