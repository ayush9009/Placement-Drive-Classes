class Solution{
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        Node* cur=head->next;
        Node* prev=head;
        while(cur!=NULL){
            if(cur->data < prev->data){
                prev->next=cur->next;
                cur->next=head;
                
                head=cur;
                cur=prev;
            }
            else{
                prev=cur;
            }
            cur=cur->next;
        }
    
    return head;
    }
};
