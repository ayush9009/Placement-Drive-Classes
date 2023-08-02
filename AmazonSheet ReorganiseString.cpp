class Solution {
public:
 // appracoh sabse pahle maximum frq hai jis charcater vo nikal lo,then use even places pai dal do in resltant
    // string,aur in the end iski count=0 i.e count[ch-'a']=0;
    // ab aur bhi bache jo ab tak resultant string mai placed ni huhe to unhe placed karo,sabse pahle ye check karte
    // raho count[ch-'a']>0 then check if idx>=n so make it idx=1 then since odd places and some may be evenplaces
    // remainging ,so idx=1,then res[idx]='a'+i vo particluar character,then count[ch-'a']--,in the end returnres
char getMaxCountChar(vector<int>& count)
{
    // with the help of this function we the find the most frequent character of string
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ch = 'a' + i;
        }
    }
    return ch;
}
 
string reorganizeString(string S) 
{
    int n = S.size();
    if (n == 0)
        return ""; //edge cases
 
    vector<int> count(26, 0);
    for (auto& ch : S)
        count[ch - 'a']++;
 
    char ch_max = getMaxCountChar(count); //find the most freq character
    int maxCount = count[ch_max - 'a'];
 
    // check if the result is possible or not
    // aaaabc
    // maxCount=4 ,4>(6+1)/2,4>3 so we return false
    // simply dekho
    // a b a c a a ,adjacent two characters are 'a' so we return empty string 
    if (maxCount > (n + 1) / 2)  //vvip base case
        return "";
 
    string res(n, ' ');
    int ind = 0;

//first we fill the most freq character on even places
    while (maxCount) {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;//beacause its done
    // suppose after the above loop idx=4 and n=8 ,so still even places remaining so we fill the raming characters on these even plcaes,when idx==n then we make idx=1,so that we can fill even indexes also
    // now filling the other Chars, first (a)

    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
}

    
};
