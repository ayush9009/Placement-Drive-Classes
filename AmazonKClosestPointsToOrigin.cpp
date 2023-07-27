class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>>ans;
         multimap<double,vector<int>>mp;

        for(int i=0;i<points.size();i++){
            double res=pow(points[i][0],2)+pow(points[i][1],2);
            res=sqrt(res);
            mp.insert({res,points[i]});
           
        }
        auto it=mp.begin();
        for(int i=0;i<k;i++)*it++;
        for(auto t=mp.begin();t!=it;t++){
            ans.push_back(t->second);
        }
        return ans;
        // vector<vector<int>>ans;
        // multimap<double,vector<int>>mp;
        // for(int i=0;i<points.size();i++){
        //     double temp=pow(points[i][0],2)+pow(points[i][1],2);
        //     temp=sqrt(temp);
        //     mp.insert({temp,points[i]});
        // }
        // auto it=mp.begin();
        // for(int i=0;i<k;i++){
        //     *it++;
        // }
        // for(auto t=mp.begin();t!=it;t++){
        //     ans.push_back(t->second);
        // }
        // return ans;
    }
};
