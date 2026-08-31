class Solution {
public:
    void obilazak(int tren,vector<vector<int>>&lista_suseda,vector<bool>&obidjen){
        obidjen[tren] = true;
        for(int cvor : lista_suseda[tren]){
            if(obidjen[cvor] == false){
                obilazak(cvor,lista_suseda,obidjen);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>obidjen(n,false);
        vector<vector<int>>lista_suseda(n);
        for(auto edge: edges){
            lista_suseda[edge[0]].push_back(edge[1]);
            lista_suseda[edge[1]].push_back(edge[0]);
        }
        int sol =0 ;
        for(int i =0;i<n;i++){
            if(obidjen[i] == false){
                obilazak(i,lista_suseda,obidjen);
                sol++;
            }
        }
        return sol;
    }
};
