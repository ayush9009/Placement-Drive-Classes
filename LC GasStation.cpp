class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totg,totc;
        totg=totc=0;
        int cur_gas=0,start_point=0;
        for(int i=0;i<n;i++){
            totg+=gas[i];
            totc+=cost[i];

            cur_gas+=gas[i]-cost[i];
            if(cur_gas<0){ //measn from index to start_pint all are bad now we start from i+1
                start_point=i+1;
                cur_gas=0;
            }
        }
        if(totg<totc)return -1;
        else return start_point;
    }
};
