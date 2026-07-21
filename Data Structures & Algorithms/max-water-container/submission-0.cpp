class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j){
            int h=min(heights[i], heights[j]);
            int w=j-i; 
            ans=max(ans, h*w);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
