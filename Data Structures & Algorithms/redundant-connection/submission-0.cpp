class Solution {
private:
    vector<int>roditelj;
    vector<int> rang;

    void UFinit(int n){
        n++;
        roditelj.resize(n,-1);
        rang.resize(n,0);
        for(int i = 0;i<n;i++)
            roditelj[i] = i;
    }
    int UFparent(int x){
        while(x != roditelj[x]){
            roditelj[x] = roditelj[roditelj[x]];
            x=roditelj[x];
        }
        return x;
    }

    void UFmerge(int x,int y){
        int px = UFparent(x);
        int py = UFparent(y);
        if(px == py)
            return;
        if(rang[px] > rang[py]){
            roditelj[py] = px;
        }else if(rang[px] < rang[py]){
            roditelj[px] = py;
        }else{
            roditelj[px] = py;
            rang[py]++;
        }
    }
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>sol(1);
        UFinit(n);
        for(auto edge:edges){
            int px = UFparent(edge[0]);
            int py = UFparent(edge[1]);
            if(px == py){
                sol = edge;
            }else{
                UFmerge(px,py);
            }
        }
        return sol;
    }
};
