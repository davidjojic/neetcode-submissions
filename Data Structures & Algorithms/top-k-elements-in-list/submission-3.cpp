class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dp;
        set<int> s;
        for(auto num : nums)
        {
            if(s.find(num) == s.end())
            {
                s.insert(num);
                dp[num] = 1;
            }else
                dp[num]++;
        }
        vector<pair<int,int>> v;
        for(auto nesto: dp)
            v.push_back(make_pair(nesto.second,nesto.first));
        vector<int>sol;
        sort(v.begin(),v.end());
        for(int i = 0;i<k;i++)
        {
            sol.push_back(v[v.size()-1-i].second);
        }
        return sol;
    }
};
