class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long sum=0;
        long maxi=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(maxi<sum){
                maxi=sum;
            }
            // maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
        
    }
    
}
