class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>susedi(n);
        vector<int> ulazni(n,0);
        for(auto vek : prerequisites){
            susedi[vek[1]].push_back(vek[0]);
            ulazni[vek[0]]++;
        }
        queue<int>q;
        unordered_map<int,int>mp;
        for(int i = 0;i<numCourses;i++){
            if(ulazni[i] == 0){
                q.push(i);
            }
        }
        int broj = 0;
        while(!q.empty()){
            int cvor = q.front();
            q.pop();
            mp[cvor] = broj;
            broj++;
            for(int i : susedi[cvor]){
                ulazni[i]--;
                if(ulazni[i] == 0)
                    q.push(i);
            }
        }
        return broj == numCourses;
    }
};
