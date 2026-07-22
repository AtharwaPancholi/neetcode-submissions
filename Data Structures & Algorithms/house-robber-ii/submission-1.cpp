class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> temp1(nums.begin(), nums.end()-1);
        vector<int> temp2(nums.begin()+1, nums.end());
        return max(helper(temp1), helper(temp2));
    }
    int dfs(vector<int>& nums, int idx, vector<int>& dp){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int notpick=dfs(nums,idx-1,dp);
        int pick=nums[idx]+dfs(nums,idx-2,dp);
        return dp[idx]=max(pick,notpick);
    }
    int helper(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        return dfs(nums,n-1,dp);
    }
};
