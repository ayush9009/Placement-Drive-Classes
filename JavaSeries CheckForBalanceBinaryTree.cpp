class Tree
{
    
    //Function to check whether a binary tree is balanced or not.
    int helper(Node root){
        if(root==null)return 0;
        return 1+Math.max(helper(root.left),helper(root.right));
    }
    boolean isBalanced(Node root)
    {
	// Your code here
	  if(root==null)return true;
	  
	  int h1=helper(root.left);
	  int h2=helper(root.right);
	  
	  if(Math.abs(h2-h1)>1)return false;
	  
	  return isBalanced(root.left) && isBalanced(root.right);
    }
}
