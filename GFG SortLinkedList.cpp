class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* cur=head;
        vector<int>result;
        while(cur!=NULL){
            result.push_back(cur->data);
            cur=cur->next;
        }
        sort(result.begin(),result.end());
        Node* hed=NULL;
        Node* temp=NULL;
        for(auto it:result){
            Node* newNode=new Node(it);
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
