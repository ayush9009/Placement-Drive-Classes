class Solution {
public:
// VVIP QUESTION NEED SOME OBSERVATION(FOR GETTING MAIN LOGIC i.e min(count/i,n))
    int findKthNumber(int m, int n, int k) {
    //    in this question we simply see the numbers or range,we easily see the maxi and mini range
       int low=1,high=m*n;   //m*n se jada max value ni hosakti low=1 se kam ni hosakti kisi kai liye bi
       
       while(low<high){
           int mid=low+(high-low)/2;
           int cnt=0;
           for(int i=1;i<=m;i++){ //with the help we find the count of all numbers that are less than mid in multiplication table
        //    suppose:
        //    123 mid=5 cnt+=mid(5/1,3)=(5,3)=3 and u clearly in first row we have 3(1,2,3) elemts that are less than or equal to mid
        //    246 cnt+=mid(5/2,3)=(2,3)=2 and u clearly in seocnd row we have 2 (2,4)elemts that are less than or equal to mid
        //    389 cnt+=mid(5/3,3)=(1,3)=1 and u clearly in third row we have 1 (3)elemts that are less than or equal to mid
               cnt+=min(mid/i,n);        
           }
           if(cnt<k){
               low=mid+1;  //jab cnt kam to kth smallest kaise milega to range badhani padegi 
           }else{
               high=mid;
           }
       }
       return low;
    }
};
