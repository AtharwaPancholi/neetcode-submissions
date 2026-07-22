class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=dfs(coins,amount,n-1);
        if(ans>=1e9) return -1;
        return ans;
    }
    int dfs(vector<int>& coins, int amount, int idx){
        int n=coins.size();
        if(idx==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }
        int notTake=0+dfs(coins,amount,idx-1);
        int take=INT_MAX;
        if(coins[idx]<=amount){
            take=1+dfs(coins,amount-coins[idx],idx);
        }
        return min(take, notTake);
    }
};
