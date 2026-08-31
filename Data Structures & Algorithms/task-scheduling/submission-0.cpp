class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char&i:tasks){
            mp[i]++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>> cooldown;
        for(auto [key,val] : mp){
            pq.push(val);
        }
        int time = 0;
        while(!pq.empty() || !cooldown.empty()){
            time++;
            if(!pq.empty()){
                auto task = pq.top();
                pq.pop();
                task--;
                if(task > 0){
                    cooldown.push({task,time+n});
                }
            }
            if(!cooldown.empty() && cooldown.front().second == time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};
