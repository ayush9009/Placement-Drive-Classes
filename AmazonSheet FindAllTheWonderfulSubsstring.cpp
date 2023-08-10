class Solution {
public:

//HARD AND IMPORTANT question ,(NEED REVISION with youtube video)
    long long wonderfulSubstrings(string word) {
        long long result=0;
        map<long long,long long>mp;
        long long prefixXorSum=0;//iski madth se har index kai liye pata lag kitne even kitne odd
        mp[0]=1;
        for(int i=0;i<word.size();i++){
            prefixXorSum=prefixXorSum ^ (1<<(word[i]-'a'));
            result+=mp[prefixXorSum];
            for(int j=0;j<12;j++){
                result+=mp[prefixXorSum ^ (1<<j)];
            }
            mp[prefixXorSum]++;
        }
         return result;
    }
   
};




// wonderful substring:
// 1. if all characters occurs even times
// 2. if n-1 characters occurs even times and 1 character occurs odd time


