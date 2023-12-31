
// brute force
bool can_place_cows(int dist,vector<int>& stalls, int k){
    int cows_placed = 1;
    int prev_place = stalls[0];

    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-prev_place >= dist){
            cows_placed++;
            prev_place = stalls[i];
            if(cows_placed == k){
                return true;
            }
        }
    }
    return false;

}

// int aggressiveCows(vector<int> &stalls, int k)
// {
//     //    Write your code here.
//     sort(stalls.begin(),stalls.end());
//     int dist=1;
//     for( ; dist<=stalls[stalls.size()-1]-stalls[0]; dist++){
//         if(!can_place_cows(dist,stalls,k)){
//             return dist-1;
//         }
//     }
//     return dist-1;
   
// }




// binary search
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int low = 1, high = stalls[stalls.size()-1]-stalls[0];

    while(low <= high){
        int mid = (low+high)/2;
        if(can_place_cows(mid,stalls,k)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
   
}
