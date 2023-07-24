class Solution{
public:	
		
	string removeDups(string s) 
	{
	    // Your code goes here
	   string str="";
	   unordered_map<char,int>mp;
	   for(auto it:s){
	       if(mp[it]>0)continue;
	       else{
	           str+=it;
	       }
	       mp[it]++;
	   }
	   return str;
	}
};
