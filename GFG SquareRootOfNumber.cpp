class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        if(x==0 || x==1)return x;
        
        long long result=1,i=1;
        while(result<=x){
            i++;
            result=i*i;
        }
        return i-1;
    }
}
