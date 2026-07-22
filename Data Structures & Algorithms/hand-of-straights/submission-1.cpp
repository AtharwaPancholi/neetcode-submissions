class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;

        map<int, int> count;
        for(int x: hand){
            count[x]++;
        }
        for(auto& [card, freq]: count){
            while(freq>0){
                for(int next=card; next<card+groupSize; next++){
                    if(count[next]==0){
                        return false;
                    }
                    count[next]--;
                }
                freq=count[card];
            }
        }
        return true;
    }
};
