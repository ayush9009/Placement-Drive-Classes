class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
          int i=0;
        int n=si/2;
        stack<int>s1;
        while(i<n)
        {
            int a=s.top();
            s.pop();
            s1.push(a);
            i++;
        }
        s.pop();
        
        while(!s1.empty())
        {
        int a=s1.top();s1.pop();
        s.push(a);
        }
        
    }
};
