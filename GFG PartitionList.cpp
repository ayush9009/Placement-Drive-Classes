void traverse(Node** r, Node* p){
    if(p!=NULL){
        p->next=(*r);
        (*r)=p;
    }
}
struct Node* partition(struct Node* head, int x) {
    // code here
    vector<int>result,ans;
    struct Node* cur=head;
    while(cur!=NULL){
        result.push_back(cur->data);
        cur=cur->next;
    }
    // sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        if(result[i]<x)
        ans.push_back(result[i]);
    }
    for(int i=0;i<result.size();i++){
        if(result[i]==x)
        ans.push_back(result[i]);
    }
    for(int i=0;i<result.size();i++){
        if(result[i]>x)
        ans.push_back(result[i]);
    }
    struct Node* r=NULL;
    for(int i= ans.size()-1;i>=0;i--){
        struct Node* p=new struct Node(ans[i]);
        traverse(&r,p);
    }
    return r;
    
}
