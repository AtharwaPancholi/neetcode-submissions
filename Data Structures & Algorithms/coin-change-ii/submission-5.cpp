class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return dfs(amount,coins,n-1,dp);
    }
    int dfs(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp){
        int n=coins.size();
        if(idx==0) return (amount%coins[0]==0);
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notTake=0+dfs(amount,coins,idx-1,dp);
        int take=0;
        if(coins[idx]<=amount){
            take=dfs(amount-coins[idx],coins,idx,dp);
        }
        return dp[idx][amount]=notTake+take;
    }
};
