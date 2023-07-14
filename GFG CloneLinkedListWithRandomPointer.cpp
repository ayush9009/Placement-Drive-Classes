lass Solution {
public:
    //VVIP  QUESTION (Need Revision Also before going to coding round)
    Node *copyList(Node *head){
        Node* temp=head;
        //First step
        while(temp!=NULL){
            Node *newNode=new Node(temp->data);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        //Second step
       Node* itr=head;
       while(itr!=NULL){
           if(itr->arb!=NULL){
               itr->next->arb=itr->arb->next;
           }
           itr=itr->next->next;
       }
       //Third step
       Node* dummy=new Node(0);
       temp=dummy;
       itr=head;
       Node* fast;
       while(itr!=NULL){
           fast=itr->next->next;
           temp->next=itr->next;
           itr->next=fast;
           temp=temp->next;
           itr=fast;
       }
       return dummy->next;  //deep copy of 1 i.e 1'
    }
};
