class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &x : nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto &[i,j] : mp){
            pq.push({j,i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int>sol;
        sol.reserve(k);
        while(!pq.empty()){
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};
