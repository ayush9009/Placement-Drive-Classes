class Solution {
public:

// VVIP QUESTION :Rolliing Hash + Binary Search
// brute force:take a map and store all the subarrays of particular friend path in it
// now put check one be one every path that is commnon in every friend path,but take huge time complexity 

// so optimal appraoch:rabin karp,means we assigned integrl value to every subarray and then store it in map and then searching
// like abc--z(1-26)values assgin kardo(example kai liye smj lo)
// but see
// cacac pattern=ac
// ac=1+3=4,ca=4 both hash codes mathcing but these are not equal string ,so there is collision,(means equal hashcodes but string not matching)

// so for this,we give unique value to every patterhn using p and mod
// this is rolling hash

// but see there are so many paths and what is maximum possiblen length =min(length of all pahts)
// to see if minLen=10 ,to hume 1,2,3,--10 har length kaai liye check karna padega to again time complexity increase to uske liye binary search aya concept aya dimag mai,kaise aya ku aya below hai smj lo:

// bhai 
// 0,1,2,3,4  answer=3 i.e 234
// 1,2,3,4 minlen=0,maxlen=min(of all arrays) i.e maxlen=min(5,4,3)=3
// 2,3,4
// see if we found common path of k=maxlen
// means 0-(k-1) we have common paths,mtlb agr k length kai path common hai to k-1 ,k-2 k-3 kai bhi hongey jaise 234 common hai,to 34 bhi sab mai common hoga ,2 bhi sab mai common hoga,ha 
// lakin k length ka nahi hai ,to k+1,k+2  ka bhi ni hoga,to is trah binary search lag ri is question mai
    
    const long long p = 1299827;
    const long long mod = 1e11+7;
    long long n,m;
    
    bool check (vector<vector<int>>&paths, int len)
    {
        if(len==0) return true;
        map<long long, int> freq;
        for(int i=0;i<m;i++)
        {
            long long curr_hash = 0, pow = 1;
            set<long long> found_hashes;
            for(int j=0;j<len;j++)
            {
                curr_hash = (curr_hash*p)%mod;
                curr_hash += paths[i][j];
                if(j!=len-1)pow = (pow*p)%mod;
            }
            found_hashes.insert(curr_hash);
            for(int j=len;j<paths[i].size();j++)
            {
                curr_hash += mod;
                curr_hash -= (paths[i][j-len] * pow)%mod;
                curr_hash %= mod;
                curr_hash = curr_hash*p;
                curr_hash %= mod;
                curr_hash += paths[i][j];
                curr_hash %= mod;
                found_hashes.insert(curr_hash);
            }
            while(found_hashes.size())
            {
                long long h = *(found_hashes.begin());
                found_hashes.erase(found_hashes.begin());
                freq[h]++;
                if(freq[h]==m) return true;
            }
            
        }
        return false;
    }
    
    int longestCommonSubpath(int elements, vector<vector<int>>& paths) {
        n = elements;
        m = paths.size();
        int minlen = INT_MAX;
        for(int i=0;i<paths.size();i++)
        {
            minlen = min(minlen,(int)paths[i].size());
        }
        int start = 0, end = minlen, mid = 0;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(check(paths,mid)) //agr ye true means mid length ka to milgya lakin is sey jafa ka bhi mil sake to start=mid+1;
            {
                start = mid + 1;
            }
            else
            {
                // ab jab mid length ka hi ni to us sey jada ka bhi ni hoga isliye end=mid-1
                end = mid - 1;
            }
        }
        return end;
    }
};
