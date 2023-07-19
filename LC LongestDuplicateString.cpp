#define p 10000007
//#define lli long long int

// Binary search + rolling function(rabin karp algo)
// basically rolling function,means optimised hashing ,two hashing one is additive,another is strong hash in additive many collision happen ,in strong hash no collison,so it is better

// abc 1+2+3 ye hai addtive hashing
// abc 26^0+26^1+26^2  ye strong hashing,
// in strong hashing resutlatn values(because of 26 vo power itni jada hoja ki reuslt overflow kar ja) can overflow so we using mod meaans mmod with prime(p) to avoid overflowing


vector<int> roll;

// apprach hash ki madth se dek rai ,kya string hai hash map(using roll values),suppose hai means match returns true,so we do binary search so that we get longer substrnig
// suppose if match return false,we searrch in mid-1 part,but if match then we search in mid+1 part

// BHT JADA GHATAK QUESTION
class Solution {
    bool match(string s,int len,int size,string& ans)  
    {
        unordered_map<int,vector<int>> m;   //Key->hashValue...Value->starting index of substring
        int hash=0;   //curr window hash
        for(int i=0;i<size;++i)
            hash = (hash*26 + (s[i]-'a'))%p; 


        
        m[hash].push_back(0); //intially empty hash to collude na ho,isliye 0 push kara diya
        //Rolling hash (sliding window)
        for(int j=size;j<len;++j)
        {
            hash = ((hash-roll[size-1]*(s[j-size]-'a'))%p + p)%p;  //is tarah se window ka size increment hora
            hash = (hash*26 + (s[j]-'a'))%p;
            // map mai two values
            // hash value    0,1,2
    // two values :hash values,and indexing ki kaha se start hora matching string
            if(m.find(hash)!=m.end())
            { //map mai search kar rai
                for(auto start: m[hash])   // jiasse pahle vala rakha 0 pai agla 5 pai
                {
                    string temp = s.substr(start,size);
                    string curr = s.substr(j-size+1,size);
                    if(temp.compare(curr)==0)
                    {
                        ans = temp;  //if two of them ,means jinki hash value colide hori,un values ki string match kr rai,if the string matches ,we return true,
                        // nahi to we simply push that into map
                        return true;
                    }
                }
            }           
            m[hash].push_back(j-size+1);
        }
        return false;
    }

public:
    string longestDupSubstring(string S) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int len = S.size();
        if(len==0)
            return "";
        
        //Store all rolling hash values
        roll.resize(len);  //Allocating fixed space to array
        roll[0] = 1;    //Since 26^0 = 1
        for(int i=1;i<len;++i)
            roll[i] = (26*roll[i-1])%p; //26^1 ,26^2,26^3 ..... aise store kar li
        
        int low=1,high=len,mid;
        string ans = "",temp;
        while(low<=high)
        {
            temp="";
            mid = low+(high-low)/2;
            bool flag = match(S,len,mid,temp);
            if(flag)
            {
                if(temp.size()>ans.size())
                    ans=temp;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};
