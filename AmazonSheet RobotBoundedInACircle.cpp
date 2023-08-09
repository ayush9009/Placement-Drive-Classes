class Solution {
public:
// NIcee question,but first dry run the test cases 
    bool isRobotBounded(string inst) {
        char cur_direction='N';//beacuse initally it faces north
        int x=0,y=0;//beacuase initally it is at origin
        for(int i=0;i<inst.size();i++){
            if(inst[i]=='G'){
                // north,south mai jane se y change baki mai x, please dry run cases 
                y+=cur_direction=='N'?1:0;
                y+=cur_direction=='S'?-1:0;
                x+=cur_direction=='E'?1:0;
                x+=cur_direction=='W'?-1:0;
            }else{
                //means if direction is either L or R
                char incoming=inst[i];
                if(cur_direction=='N'){
                    cur_direction=(incoming=='L')?'W':'E';
                }else if(cur_direction=='S'){
                    cur_direction=(incoming=='L')?'E':'W';
                }else if(cur_direction=='E'){
                    cur_direction=(incoming=='L')?'N':'S';
                }else{
                    cur_direction=(incoming=='L')?'S':'N';
                }
            }
        }
        // cur_direction!='N' ye case to jab dry run karogey tabhi pata chlega
        // ki agr origin pai ata hai last mai, to true
        // aur agr in the end cur_Direction==N to false 
        return (x==0&&y==0 || (cur_direction!='N'))?1:0;
    }
};
