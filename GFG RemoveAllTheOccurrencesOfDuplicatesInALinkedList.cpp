class Solution
{
    public:
    Node* removeAllDuplicates(struct Node* head)
    {
        //code here
        Node *temp=new Node(0);
        temp->next=head;
        Node* cur=head;
        Node* prev=temp;
        while(cur!=NULL){
            bool isDuplicate=false;
            while(cur->next && cur->data==cur->next->data){
                isDuplicate=true;
                cur=cur->next;
            }
            if(isDuplicate){
                prev->next=cur->next;
                
            }else{
                prev=cur;
            }
            cur=cur->next;
        }
        return temp->next;
       
    }
};
