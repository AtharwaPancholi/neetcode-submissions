class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char, int> mpp;
        int l=0;
        int ans=0;
        for(int r=0; r<n; r++){
            if(mpp.find(s[r])!=mpp.end()){
                l=max(l, mpp[s[r]]+1);
            }
            mpp[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
