// This function should return head to the DLL
class Solution
{
    public: 
    vector<int>arr;
    Node* helper2(int size){
    if (size == 0) {
        return NULL;
    }

    Node* head = new Node(arr[0]);
    Node* curr = head;
    int cnt=0;
    // cout<<size<<endl;
    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(arr[i]);
        // curr->next = newNode;
        curr->right = newNode;
        // newNode->prev = curr;
        newNode->left = curr;
        curr = newNode;
        cnt++;
    }
    // cout<<cnt<<endl;

    return head;
    }
    void helper(Node* root){
        if(root!=NULL){
            helper(root->left);
            arr.push_back(root->data);
            helper(root->right);
        }
    }
    // void createNode(Node *root,int val){
        
    // }
    Node * bToDLL(Node *root)
    {
        // your code here
        for(auto it:arr)cout<<it<<" ";
        helper(root);
        return helper2(arr.size());
        
    }
};
