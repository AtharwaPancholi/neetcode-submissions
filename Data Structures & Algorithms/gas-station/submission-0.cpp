class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int totalcost=0;
        for(int i=0; i<gas.size(); i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalcost>totalgas) return -1;
        int start=0;
        int gain=0;
        for(int i=0; i<gas.size(); i++){
            gain+=gas[i]-cost[i];
            if(gain<0){
                start=i+1;
                gain=0;
            }
        }
        return start;
    }
};
