class Solution{
	
	
	public:
	vector<long long> findMissing(long long a[], long long b[],  
                 int n, int m) 
	{ 
	    // Your code goes here
	    map<long,long>mp;
	    for(int i=0;i<m;i++){
	        mp[b[i]]++;
	    }
	   // set<int>st;
	    vector<long long>result;
	    for(int i=0;i<n;i++){
	        if(mp.find(a[i])==mp.end())result.push_back(a[i]);
	    }
	    return result;
	} 
};
