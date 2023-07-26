#include<bits/stdc++.h>
long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.
     priority_queue <int, vector<int>, greater<int> > pq;
     long long ans=0;
     for(auto it:arr)pq.push(it);
     while(pq.size()>1){
          int temp=pq.top();  //cost of one stick
          pq.pop(); 
          temp+=pq.top();  //cost of another stick
          pq.pop();
          ans+=temp; //cost add hogyi result m
          pq.push(temp);  //ab jo do jodi use tisri ki sath bhi to jodna to pq m dal diya,ab 
          // do stciks h humare pass,inki cost nikli aur add hogi yani 3 sticks combine hogi and now sirf 
          // ek stick bchi queue m so loop terminates we return our answer;
     }
     return ans;
}
