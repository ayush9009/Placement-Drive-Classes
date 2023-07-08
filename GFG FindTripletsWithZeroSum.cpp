class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        int flag=0;
        for(int i=0;i<n-1;i++){
            int l=i+1;
            int r=n-1;
            int x=arr[i];
            while(l<r){
                if(arr[l]+arr[r]+x ==0){
                    l++;
                    r--;
                    flag=1;
                    break;
                }
                else if(arr[l]+arr[r]+x<0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return flag;
    }
 
};
