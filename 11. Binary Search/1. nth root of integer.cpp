int NthRoot(int n, int m) {
  // Write your code here.
  if (n==0)
        return 0;
    if (n==1)
        return 1;
    int l=2,h=m-1;
    int sqrt=-1;
    while(l<=h){
        int mid =(h+l)/2;
        if(pow(mid,n)==m){
          sqrt = mid;
          l=mid+1;
        }
        if(pow(mid,n) < m){
            
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return sqrt;
}
