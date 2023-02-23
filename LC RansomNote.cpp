class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0;i<ransomNote.length();i++)
        {
            arr1[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.length();i++)
        {
            arr2[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.length();i++)
        {
            if(arr1[ransomNote[i]-'a']>arr2[ransomNote[i]-'a'])
                return false;
        }
        return true;
    }
};
