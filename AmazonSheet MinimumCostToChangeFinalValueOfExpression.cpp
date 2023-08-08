class Solution {
public:
// Really hard question 
// Intution:If you have an expression, lets say EXP = exp1 & exp2, assume that value of exp1 and exp2 is 1, hence when you solve this, you get the value of EXP as 1. Now you have to change something in this expression with minimum cost so that the final value of EXP is 0.
// We have have 2 options.
// Change something in exp1 with cost1 so that its value is 0 so that final value of EXP is 0.
// Change something in exp2 with cost2 so that its value is 0 so that final value of EXP is 0.
// Change & to ||(with cost 1) and change exp1 to 0 and exp2 to 0 i.e. 1 + cost1 + cost2.

// Now the first two options will always be better than 3rd option, Thats why I have written, min(cost1, cost2) in the code below:-
// if(op == '&' && val1 == '1' && val2 == '1') p = {'1', min(cost1, cost2)};



    int minOperationsToFlip(string exp) {
        stack<pair<char,int>>st;
        char val1,val2,op;
        int cost1,cost2;
        pair<char,int>p;// p store the value of expression along with the cost
        for(int i=0;i<exp.size();i++){  // exp= (a&b)
            if(exp[i]=='(' || exp[i]=='&' || exp[i]=='|'){
                st.push({exp[i],0});//these exp dont have any value 
            }else{
                if(exp[i]==')'){
                    p=st.top();
                    st.pop();
                    st.pop();
                    // cout<<st.top().first<<" "<<st.top().second;
                    // why two times pop because:
             // (1) if this is ur expression then first 1 u have to pop then ( this pop
                  
                    // cout<<endl;
                    //  cout<<st.top().first<<" "<<st.top().second;
                }else{
                    p={exp[i],1}; //when we encounter 0 or 1 ,store the value
                    // value(exp[i] which is eihter 0 or 1 ) and cost to change them is 1(change from 0 to 1 is 1 and change from 1 to 0 is 1)
                }
                while(!st.empty() && (st.top().first=='&' || st.top().first=='|')){
                    op=st.top().first;
                    st.pop();
                    val2=p.first;
                    cost2=p.second;
                    val1=st.top().first;
                    cost1=st.top().second;
                    st.pop();
                    // st.pop();

                    //  1&1 =1 to p.first='1'
                    //  1&0=0 ,0&1=0 to p.first='0'
                    if(op=='&' && val1=='1' && val2=='1')p={'1',min(cost1,cost2)};
                    if(op=='&' && val1=='1' && val2=='0')p={'0',1};
                    if(op=='&' && val1=='0' && val2=='1')p={'0',1};
                    // 1+cost1 kuki yaha 0 ko to 1 mai karna hi hoga (kuki & operator hai dono 1 honge jabhi 1 ayegaa)kisi bhi halat mai
                    if(op=='&' && val1=='0' && val2=='0')p={'0',min(1+cost1,1+cost2)};


                    //  1|1 =1 to p.first='1'
                    //  0|0=0 to p.first='0'
                    // 1+cost1 kuki 1 ko 0 mai karna hi hoga,agr ouput 0 chiaye  ,kuki 
                    // 0|1=1, 1|0=1 ,  0|0=1 to dono 0 bnao isliye 1+cost1,1+cost2
                    if(op=='|' && val1=='1' && val2=='1')p={'1',min(1+cost1,1+cost2)};
                    // 1|0=1 , to ya to 1 ko 0 karlo ya 0 ko 1 to minimum cost=1 hi lagegi
                    if(op=='|' && val1=='1' && val2=='0')p={'1',1};
                // 0|1=1 , to ya to 1 ko 0 karlo ya 0 ko 1 to minimum cost=1 hi lagegi
                    if(op=='|' && val1=='0' && val2=='1')p={'1',1};

                    //exp 0 hoga aur 
                    if(op=='|' && val1=='0' && val2=='0')p={'0',min(cost1,cost2)};
                }
                st.push(p);
            }
        }
        return st.top().second;  //top.first to exp and top.second cost
    }
};
