class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>sol;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        sol.push_back({pq.top().first});
        for(int i = k;i<nums.size();i++){
            pq.push({nums[i],i});
            while(pq.top().second <= i-k)
                pq.pop();
            sol.push_back({pq.top().first});
        }
        return sol;
    }
};
