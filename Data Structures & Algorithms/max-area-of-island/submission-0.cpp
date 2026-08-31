class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int a[] = {1,-1,0,0};
        int b[] = {0,0,1,-1};

        int n = grid.size();
        int m = grid[0].size();

        int sol = 0;
        vector<vector<bool>>check(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && check[i][j] == false){
                    queue<pair<int,int>>q;
                    int vel = 1;
                    check[i][j] = true;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y] = q.front();q.pop();

                        for(int k =0;k<4;k++){
                            int nx = x + a[k];
                            int ny = y + b[k];

                            if(nx>=0 && ny>=0 && nx< n && ny < m && check[nx][ny] == false && grid[nx][ny] == 1){
                                vel++;
                                check[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                    sol=max(sol,vel);
                }
            }
        }
        return sol;
    }
};
