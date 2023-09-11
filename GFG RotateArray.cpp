class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        // while(d--){
        //     int temp=arr[0];
        //     for(int i=0;i<n-1;i++){
        //         arr[i+1]=temp;
        //         arr[i]=arr[i+1];
        //         temp=arr[i+1];
                
        //     }
        // }
        int temp[n];
        for(int i=0;i<n;i++)temp[i]=arr[i];
        int ind=0;
        for(int i=0;i<n;i++){
            arr[i]=temp[(ind+d)%n];
            ind++;
        }
    }
};
