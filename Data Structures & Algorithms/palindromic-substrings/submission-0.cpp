class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            ans+=solve(i,i,s);
            ans+=solve(i,i+1,s);
        }
        return ans;
    }
    int solve(int l, int r, string s){
        int n=s.size();
        int cnt=0;
        while(l>=0 && r<n && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
};
