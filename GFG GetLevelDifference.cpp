class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       int sum1=0,sum2=0;
       if(!root)return 0;
       queue<Node*>q;
       q.push(root);
       bool flag=0;
       while(q.empty()==false){
          int n=q.size();
          for(int i=1;i<=n;i++){
               Node* cur=q.front();
               q.pop();
               if(flag==0)sum1+=cur->data;
               else sum2+=cur->data;
               if(cur->left)q.push(cur->left);
               if(cur->right)q.push(cur->right);
          }
             
             if(flag==false)flag=1;
             else flag=0;
       }
       return (sum1-sum2);
    }
};
