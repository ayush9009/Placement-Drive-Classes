class Solution {
    int binarysearch(int arr[], int n, int k) {
        // code here
        int left=0,right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]==k){
                return mid;
            }else if(arr[mid]<k){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
}
