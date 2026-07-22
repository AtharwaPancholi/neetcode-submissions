class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int num: nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>> dp(n, vector<int> (sum/2+1, -1));
        return dfs(nums,0,sum/2, dp);
    }
    bool dfs(vector<int>& nums, int i, int target, vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n){
            return target==0;
        }
        if(target<0){
            return false;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        dp[i][target]=dfs(nums, i+1, target, dp) || dfs(nums,i+1,target-nums[i], dp);
        return dp[i][target];
    }
};
