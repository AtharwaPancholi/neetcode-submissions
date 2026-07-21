class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int minProfit=INT_MAX;
        for(int i=0; i<n; i++){
            if(prices[i]<minProfit){
                minProfit=prices[i];
            }
            maxProfit=max(maxProfit, prices[i]-minProfit);
        }
        return maxProfit;
    }
};
