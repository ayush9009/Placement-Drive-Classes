class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    return (s+s).substr(1,s.size()*2-2).find(s)!=-1;
	   // s=aba
	   // s+s=abaaba
	   // s.substr(1,4) means(baab mai check karo) baab.find(aba) no i.e 0 !=-1 so we return 0
	}
};
