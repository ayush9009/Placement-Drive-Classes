class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {

        sort(arr,arr+n);
        int flag=0;
        for(int i=0;i<n-1;i++){
            int l=i+1;
            int r=n-1;
            int x=arr[i];
            while(l<r){
                if(arr[l]+arr[r]+x ==X){
                    l++;
                    r--;
                    flag=1;
                    break;
                }
                else if(arr[l]+arr[r]+x<X){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return flag;
    }

};
