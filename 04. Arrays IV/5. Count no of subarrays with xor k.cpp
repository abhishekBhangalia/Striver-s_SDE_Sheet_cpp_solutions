#include <bits/stdc++.h>


// Brute Force, (Partially Accepted), TC-O(n^2)
// int subarraysWithSumK(vector < int > a, int b) {
//     int n=0;
//     int x=0;

//     for(int i=0; i<a.size(); i++){
//         x=0;
//         for(int j=i; j<a.size(); j++){
//             x ^= a[j];
//             if(x==b){
//                 n++;
//             }
//         }
//     }

//     return n;
// }


// Hashing, TC-O(n), SC-O(n)
int subarraysWithSumK(vector < int > a, int b) {
    int n=0;
    int x=0;

    unordered_map<int,int> prev_xor;

    for(int i=0; i<a.size(); i++){
        x ^= a[i];

        if(x==b){
            n++;
        }
        if(prev_xor.find(x^b) != prev_xor.end()){
            n += prev_xor[x^b];
        }
        prev_xor[x]++;
    }
    return n;
}
