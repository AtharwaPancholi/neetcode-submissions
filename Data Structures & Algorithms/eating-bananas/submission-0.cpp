class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int largest=0;
        for(int i=0; i<n; i++){
            largest=max(largest,piles[i]);
        }
        int low=1; 
        int high=largest;
        int ans=largest;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hours=0;
            for(int i=0; i<n; i++){
                hours += (piles[i]+mid-1)/mid;
            }
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
