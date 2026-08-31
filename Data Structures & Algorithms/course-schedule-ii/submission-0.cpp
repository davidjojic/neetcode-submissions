class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>susedi(n);
        vector<int> ulazni(n,0);
        for(auto vek : prerequisites){
            susedi[vek[1]].push_back(vek[0]);
            ulazni[vek[0]]++;
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++){
            if(ulazni[i] == 0){
                q.push(i);
            }
        }
        vector<int>sol;
        int broj = 0;
        while(!q.empty()){
            int cvor = q.front();
            q.pop();
            broj++;
            sol.push_back(cvor);
            for(int i : susedi[cvor]){
                ulazni[i]--;
                if(ulazni[i] == 0)
                    q.push(i);
            }
        }
        vector<int>prazan;
        if(broj != numCourses)
            return prazan;
        return sol;        
    }
};
