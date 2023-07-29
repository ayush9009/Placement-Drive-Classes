
et* constructTree(char postfix[])
{
     // Basic algo:
    // first of all ,if given expression is not postfix then convert it into postfix
    // then traversing the expression,check if the element is operand then push it to stack
    // if element is operand then pop two elements from stack,and make them left and right child of operator
    // now the tree that form because of this operator push that it into stack,in the end you get the tree at top
    // of stack,return st.top
   stack<et*>stk;
   for(int i=0;postfix[i]!='\0';i++){
       if(isOperator(postfix[i])){
        et*right=stk.top();
        stk.pop();
        et*left=stk.top();
        stk.pop();
        et*temp=new et(postfix[i]);
        temp->right=right;
        temp->left=left;
        stk.push(temp);
       }
      else{
         stk.push(new et(postfix[i]));
      }
    
    }
  return stk.top();
    
}
