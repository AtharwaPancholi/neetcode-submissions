class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int n: nums){
            mpp[n]++;
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, 
        greater<pair<int,int>>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
