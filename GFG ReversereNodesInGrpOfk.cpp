class Solution
{
    public:
    int lengthOfLL(node *head) {
        int l = 0;
        node *p = head;
        
        while(p) {
            l++;
            p = p->next;
        }
        
        return l;
    }
    
    struct node *reverse (struct node *head, int k)
    {
        if(!head)
            return NULL;
            
        if(!head->next)
            return head;
            
        int len = lengthOfLL(head);
        node *temp = new node(0);
        node *curr, *nxt, *prev = temp;
        temp->next = head;
        
        while(k <= len) {
            curr = prev->next;
            nxt = curr->next;
            
            for(int i = 0; i < k - 1; i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                
                prev->next = nxt;
                nxt = curr->next;
            }
            
            prev = curr;
            len -= k;
        }
        
        if(len <= k) {
            node *t = curr, *p = NULL;
            curr = curr->next;
            
            while(nxt) {
                nxt = curr->next;
                curr->next = p;
                
                p = curr;
                curr = nxt;
            }
            
            t->next = p;
        }
        
        return temp->next;
    }
};
