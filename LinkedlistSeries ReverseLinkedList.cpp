/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL || head->next==NULL)
        //     return head;
        // ListNode *curr=head;
        // ListNode *prev=NULL;
        // ListNode *nxt=head->next;
        // while(curr!=NULL){
        //     curr->next=prev;
        //     prev=curr;
        //     curr=nxt;
        //     if(nxt!=NULL)
        //         nxt=nxt->next;
        // }
        // return prev;
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* nxt=head->next;
        while(cur!=NULL){
            cur->next=prev ;
            prev=cur;
            cur=nxt;
            if(nxt!=NULL){
                nxt=nxt->next;
            }
        }
        cout<<(prev->val);
        return prev;
    }
};
