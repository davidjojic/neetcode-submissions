class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int sol = 0;
        vector<pair<int,int>>v;
        for(int i =0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        double maxTime = 0;
         for (int i = v.size() - 1; i >= 0; i--) {
            double time = (double)(target - v[i].first) / v[i].second;
            if (time > maxTime) {
                sol++;
                maxTime = time;
            }
        }
        return sol;
    }
};
