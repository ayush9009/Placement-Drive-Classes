class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int d) {
        Node* newnode = new Node(d);
        Node* temp = head;
        if (head==NULL){
            return newnode;
            
        }
        else{
            if(head->data>=d){
                newnode->next= head;
                head=newnode;
            }
            else{
                Node* prev;
                Node* curr= head;
                while(curr && curr->data<d ){
                    prev = curr;
                    curr=curr->next;
                }
                prev->next=newnode;
                newnode->next=curr;
            }
            
            return head;
        }
        
        
        
        
    }
};
