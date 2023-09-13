class Solution {
public:
   //here first loop ensures that higher rating children get more candies than its
//    left neighbour
//second loop ensures that higher rating children get more candies than its right 
// neighbour
//baki bache cases like equal to vala vo inme automatically consider ho jange
// lakin ye cheez aapko tab pata chlegi jab aap dry run karke dekogey
// for eg:
// intially                ans:1 1 1  1  1  1 1
//                             1 2 87 87 87 2 1
// after first loop ans become:1 2 3  1   1 1 1
// after second loop ans      :1 2 3  1   3 2 1
// i think after this example everyone understand logic 
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        // if(n<=1)return n;
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])ans[i]=ans[i-1]+1;
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i-1]>ratings[i])ans[i-1]=max(ans[i-1],ans[i]+1);
            //deko agr aphle right se shuru karogey phir left se to bhi ye max
            // karna hi padega ,nahi smj ara to dry run karke jaror deko
        }
        int res=0;
        for(auto it:ans){
            cout<<it<<" ";
            res+=it;
        }
       return res;
    }
};
