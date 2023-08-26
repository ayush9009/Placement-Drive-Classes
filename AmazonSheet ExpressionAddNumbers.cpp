class Solution {
public:
//VVIP Question


//idea is backtracking ,because in the question we have to find all the possibilites
//we have to make sure about the leading zeros because they dont make any effect so
//we have to simply ignore them ,+ and - does not make any change accoding to BOMDAS
// rule but * make the change
// eg:s="732" target=13 7+3*2 if we dont use bodmas 10*2=20 but this is wrong
// 7+3*2 means 7+6=13 
// means curSum-prevNum+prevNum*curNum i.e 10-3+3*2=7+3*2=7+6=13
void dfs(int i,int sum,int prev,string num,vector<string>&ans,string curPath,int target){
    if(i==num.size()){
        if(sum==target){
            ans.push_back(curPath);
        }
        return;
    }
    for(int j=i;j<num.size();j++){
        if(j>i && num[i]=='0'){
            // avoid leading zeros
            break;
        }
        long number=stol(num.substr(i,j-i+1));
        string tempPath=num.substr(i,j-i+1);

        if(i==0){
            //if it is first index measn i.e "732" to i=0 means 7 hai to j+1bas
            dfs(j+1,number,number,num,ans,tempPath,target);
        }else{
            dfs(j+1,sum+number,number,num,ans,curPath + '+' + tempPath,target);
            dfs(j+1,sum-number,-number,num,ans,curPath + '-' + tempPath,target);
            dfs(j+1,sum-prev+prev*number,prev*number,num,ans,curPath + '*' + tempPath,target);
        }
    }
}
    vector<string> addOperators(string num, int target) {
        vector<string >ans;
        dfs(0,0,0,num,ans,"",target);
        return ans;
    }
};
