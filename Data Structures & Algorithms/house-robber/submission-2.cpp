class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return dfs(nums,nums.size()-1,dp);
    }
    int dfs(vector<int>& nums, int idx, vector<int>& dp){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+dfs(nums,idx-2,dp);
        int notpick=dfs(nums,idx-1,dp);
        return dp[idx]=max(pick,notpick);
    }
};
