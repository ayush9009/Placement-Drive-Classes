bool find4Numbers(int nums[], int n, int target)  
{
         sort(nums,nums+n);
        vector<vector<int>>ans;
       
        // int n=nums.size();
         if(n<4)return 0;
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            // below if condtions are important
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target)continue;
            for(int j=i+1;j<n-2;j++){
                // below if condtions are important
                if(j>i+1 && nums[j]==nums[j-1])continue;
                 if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)break;
                 if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target)continue;
                 int left=j+1,right=n-1;
                 while(left<right){
                     int sum=nums[i]+nums[j]+nums[left]+nums[right];
                     if(sum<target)left++;
                     else if(sum>target)right--;
                     else{
                         ans.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        //  below loops are used to avoid to reapeating pairs

                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);{right--;}
                     }
                 }
            }
        }
        return (ans.size()>0)?1:0;
        
}
