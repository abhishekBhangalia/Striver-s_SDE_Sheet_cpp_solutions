class Solution {
public:

    // //O(n1 x n2)
    // void merge(vector<int>& a, int n1, vector<int>& b, int n2) {
    //     int i=0,j=0;
    //     while(i<n1 and j<n2){
    //         if(a[i]>b[j]){
    //             swap(a[i],b[j]);
    //             int tmp = j;
    //             while(tmp<n2-1){
    //                 if(b[tmp]>b[tmp+1]){
    //                     swap(b[tmp],b[tmp+1]);
    //                     tmp++;
    //                 }
    //                 else{
    //                     break;
    //                 }
    //             }
    //         }
    //         i++;
    //     }

    //     for(int i=n1; i<a.size(); i++){
    //         a[i]=b[i-n1];
    //     }
        
    // }


    //O(n1+n2)
    void merge(vector<int>& a, int n1, vector<int>& b, int n2) {
        int i=n1-1,j=n2-1,k=a.size()-1;

        while(i>=0 and j>=0){
            if(a[i]>b[j]){
                a[k] = a[i];
                i--;
                k--;
            }
            else{
                a[k] = b[j];
                j--;
                k--;
            }
        }

        while(j>=0){
            a[k--] = b[j--];
        }
        
        
    }
};
