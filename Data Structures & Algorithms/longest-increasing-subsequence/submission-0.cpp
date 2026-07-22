class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> dp(n,-1);
        for(int i=0; i<n; i++){
            ans=max(ans,dfs(nums,i,dp));
        }
        return ans;
    }
    int dfs(vector<int>& nums, int idx, vector<int>& dp){
        int n=nums.size();
        if(dp[idx]!=-1) return dp[idx];
        int maxi=1;
        for(int j=0; j<idx; j++){
            if(nums[j]<nums[idx]){
                maxi=max(maxi, dfs(nums,j,dp)+1);
            }
        } 
        return dp[idx]=maxi;
    }
};
