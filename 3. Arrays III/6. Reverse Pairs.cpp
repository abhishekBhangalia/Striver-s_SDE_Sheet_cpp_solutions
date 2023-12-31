static const auto speed=[]{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


//98 ms
// less readable code but beats 100% 
class Solution {

// TC-O(2n log n), SC-O(n)
int rec(vector<int>&  arr, int l, int r) {
    // Write Your Code Here
    if(l == r)  return 0;
    
    int m = l+(r-l)/2;
    int ans = rec(arr, l, m) + rec(arr, m+1, r);

    int i=l, j=m+1;
    int n = 0;
    while(i<=m){
        while(j<=r and arr[i] > (long)2 * arr[j]){
            n++;
            j++;
        }
        ans += n;
        i++;
    }
    
    int size = r-l+1, tmp[size];
    merge(arr.begin()+l, arr.begin()+m+1, arr.begin()+m+1, arr.begin()+r+1, tmp);
    copy(tmp, tmp+size, arr.begin()+l);
    return ans;
}


public:

    int reversePairs(vector<int>& nums) {
        return rec(nums, 0, nums.size()-1);
    }
};







// 143 ms
// more readable but beats only 99%
// class Solution {
//     // TC-O(3(r-l+1)), SC-O(r-l+1)
// int merge(vector<int>&  arr, int l, int m, int r){
//     int cnt = 0;
//     int size1 = m-l+1, size2 = r-m; 
//     int tmp1[size1], tmp2[size2];
//     int k = l;
//     for(int i=0; i<size1; i++){
//         tmp1[i] = arr[k++];
//     }
//     for(int i=0; i<size2; i++){
//         tmp2[i] = arr[k++];
//     }

//     int i = l;
//     int j = m+1;


//     // while(i<=m and j<=r){
//     //     if(arr[i] > (long)2 * arr[j]){
//     //         cnt += m-i+1;
//     //         j++;
//     //     }
//     //     else{
//     //         i++;
//     //     }
//     // }

//     int temp = 0;
//     while(i<=m) {
//         while(j<=r && arr[i] > (long)2 * arr[j]) {
//             temp++;
//             j++;
//         }
//         cnt += temp;
//         // cnt += j-m-1;
//         i++;
//     }

//     i=0;
//     j=0;
//     k=l;
//     while(i<size1 and j<size2){
//         if(tmp1[i] < tmp2[j]){
//             arr[k++] = (tmp1[i++]);   
//         }
//         else{
//             arr[k++] = (tmp2[j++]);
//         }
//     }

//     while(i<size1) arr[k++] = (tmp1[i++]);
//     while(j<size2) arr[k++] = (tmp2[j++]);
    
//     return cnt;
// }


// // TC-O(2n log n), SC-O(n)
// int mergeSort(vector<int>&  arr, int l, int r) {
//     // Write Your Code Here
//     int cnt = 0;
//     if(l<r){
//         int m = (l+r)/2;
//         cnt += mergeSort(arr,l,m);
//         cnt += mergeSort(arr,m+1,r);
//         cnt += merge(arr,l,m,r);
//     }
//     return cnt;
// }


// public:

//     int reversePairs(vector<int>& nums) {
//         int pairs = mergeSort(nums, 0, nums.size()-1);
//         return pairs;
//     }
// };



// 660ms
// beats 51% only due to use of vectors instead of simple arrays
// class Solution {

    
    
//     // TC-O(3(r-l+1)), SC-O(r-l+1)
// int merge(vector<int>&  arr, int l, int m, int r){
//     int cnt = 0;
//     vector<int> tmp;

//     int i = l;
//     int j = m+1;


//     // while(i<=m and j<=r){
//     //     if(arr[i] > (long)2 * arr[j]){
//     //         cnt += m-i+1;
//     //         j++;
//     //     }
//     //     else{
//     //         i++;
//     //     }
//     // }

//     int temp = 0;
//     while(i<=m) {
//         while(j<=r&&arr[i]>2LL*arr[j]) {
//             temp++;
//             j++;
//         }
//         cnt+=temp;
//         i++;
//     }

//     i=l;
//     j=m+1;

//     while(i<=m and j<=r){
//         if(arr[i] < arr[j]){
//             tmp.push_back(arr[i++]);   
//         }
//         else{
//             tmp.push_back(arr[j++]);
//         }
//     }

//     while(i<=m) tmp.push_back(arr[i++]);
//     while(j<=r) tmp.push_back(arr[j++]);
        
//     for(int i=l; i<=r; i++){
//         arr[i] = tmp[i-l];
//     }
//     return cnt;
// }


// // TC-O(2n log n), SC-O(n)
// int mergeSort(vector<int>&  arr, int l, int r) {
//     // Write Your Code Here
//     int cnt = 0;
//     if(l<r){
//         int m = (l+r)/2;
//         cnt += mergeSort(arr,l,m);
//         cnt += mergeSort(arr,m+1,r);
//         cnt += merge(arr,l,m,r);
//     }
//     return cnt;
// }


// public:

//     int reversePairs(vector<int>& nums) {
    
//         int pairs = mergeSort(nums, 0, nums.size()-1);
        
//         return pairs;
//     }
// };
