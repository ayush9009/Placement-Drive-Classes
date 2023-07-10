class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head==NULL)return NULL;
        struct node *cur=head, *nxt=NULL, *prev=NULL;
        int count=0;
       
        while(cur!=NULL && count<k){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            count++;
        }
        if(nxt!=NULL){  //jaise 12 reverse kar liye ab 34 reverse karo agr k=2 h
             head->next=reverse(nxt,k);
        }
        return prev; 
    }
};
