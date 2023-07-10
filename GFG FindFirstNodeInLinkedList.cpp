class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        if(head==NULL || head->next==NULL)return -1;
        Node* slow=head;
        Node* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow!=head){
                    slow=slow->next;
                    head=head->next;
                }
                return head->data;
            }
        }
        return -1;
    }
};
