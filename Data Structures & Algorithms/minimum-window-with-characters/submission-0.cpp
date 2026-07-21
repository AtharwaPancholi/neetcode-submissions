class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int required=t.size();
        vector<int> freq(128, 0);
        if(s.size()<t.size()) return "";
        for(char ch: t){
            freq[ch]++;
        }
        int l=0;
        int start=0;
        int minLen=INT_MAX;
        for(int r=0; r<m; r++){
            if(freq[s[r]]>0){
                required--;
            }
            freq[s[r]]--;
            while(required==0){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    start=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    required++;
                }
                l++;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen);
    }
};
