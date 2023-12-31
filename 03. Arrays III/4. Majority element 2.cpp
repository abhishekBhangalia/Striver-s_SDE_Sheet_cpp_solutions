class Solution {
public:

    // TC-O(2*n), SC- O(n)
    // vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> count;
    //     for(int x: nums){
    //         count[x]++;
    //     }
    //     int n=nums.size();
    //     vector<int> ans;
    //     for(auto i:count){
    //         if(i.second > n/3){
    //             ans.push_back(i.first);
    //         }
    //     }
    //     return ans;
    // }


    // //Hashing, TC-O(n), SC-O(n)
    // vector<int> majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> count;
    //     vector<int> ans;
    //     int n=nums.size();
        

    //     for(int x: nums){
    //         count[x]++;
    //         if(count[x] == n/3 + 1){
    //             ans.push_back(x);
    //         }
    //         if(ans.size() == 2){
    //             return ans;
    //         }
    //     }
    //     return ans;
    // }


    // TC-O(2*n), SC-O(1)
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> maj_el(2,-1e9-1);
        int count0=0, count1=0;
        
        for(int x: nums){
            if(count0 == 0 and x != maj_el[1]){
                maj_el[0] = x;
                count0 = 1;
                
            }
            else if(count1 == 0 and x != maj_el[0]){
                maj_el[1] = x;
                count1 = 1;
                
            }
            else if(x == maj_el[0]){
                count0++;
            }
            else if(x == maj_el[1]){
                count1++;
            }
            else{
                count1--;
                count0--;
            }
            
        }
        count0 = 0;
        count1 = 0;

        for(int x:nums){
            if(x == maj_el[0]){
                count0++;
            }
            else if(x == maj_el[1]){
                count1++;
            }
        }

        vector<int> ans;
        if(count0 > nums.size()/3){
            ans.push_back(maj_el[0]);
        }
        if(count1 > nums.size()/3){
            ans.push_back(maj_el[1]);
        }
        return ans;
    }

};
