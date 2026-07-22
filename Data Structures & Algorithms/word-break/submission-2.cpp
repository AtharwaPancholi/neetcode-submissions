class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(s,st,0,dp);
    }
    bool solve(string& s, unordered_set<string>& st, int idx, vector<int>& dp){
        int n=s.size();
        if(idx==n) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx; i<n; i++){
            string word=s.substr(idx,i-idx+1);
            if(st.find(word)!=st.end()){
                if(solve(s,st,i+1,dp)){
                    return dp[idx]=true;
                }
            }
        }
        return dp[idx]=false;
    }
};
