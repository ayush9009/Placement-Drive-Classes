class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* cur=head
        vector<int>result;
        while(cur!=NULL){
            result.push_back(cur->data);
            cur=cur->next;
        }
        vector<int>ans;
        for(int i=0;i<result.size();i++){
            int x=result[i];
            int flag=0;
            for(int j=i+1;j<result.size();j++){
                if(result[j]>x){
                    flag=1;
                    break;
                }
            }
            if(flag==0)ans.push_back(x);
        }
        Node* hed=NULL;
        Node* temp=NULL;
        for(int i=0;i<ans.size();i++){
            Node* newNode=new Node(ans[i]);
            if(hed==NULL){
                hed=newNode;
                temp=newNode;
            }else{
                temp->next=newNode;
                temp=temp->next;
            }
        }
        
        return hed;
    }
    
};
   
