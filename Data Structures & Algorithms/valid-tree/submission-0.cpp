class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>lista_suseda(n);
        vector<int>otac(n,-1);
        vector<bool>obisao(n,false);
        for(auto edge : edges){
            lista_suseda[edge[0]].push_back(edge[1]);
            lista_suseda[edge[1]].push_back(edge[0]);
        }

        int broj = 0;
        queue<int>q;
        obisao[0] = true;
        q.push(0);
        otac[0] = 0;
        while(!q.empty()){
            int cvor = q.front();q.pop();
            broj++;
            for(int sused : lista_suseda[cvor]){
                if(sused != otac[cvor] && obisao[sused]){
                    return false;
                }else if(sused != otac[cvor]){
                    otac[sused] = cvor;
                    obisao[sused] = true;
                    q.push(sused);
                }

            }
        }
        if(broj != n)
            return false;
        return true;
    }
};
