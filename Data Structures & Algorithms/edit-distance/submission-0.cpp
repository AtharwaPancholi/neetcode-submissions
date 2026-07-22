class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return dfs(m-1,n-1,word1,word2,dp);
    }
    int dfs(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=0+dfs(i-1,j-1,word1,word2,dp);
        } else{
            return dp[i][j]=1+min({dfs(i-1,j,word1,word2,dp), dfs(i,j-1,word1,word2,dp),
            dfs(i-1,j-1,word1,word2,dp)});
        }
    }
};
