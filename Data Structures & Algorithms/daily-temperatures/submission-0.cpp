class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        int n = temperatures.size();
        vector<int>v(n,0);
        for(int i = n-1;i>=0;i--){
            while(!s.empty() && s.top().first <= temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                v[i] = s.top().second-i;
            }
            s.push({temperatures[i],i});
        }
        return v;
    }
};
