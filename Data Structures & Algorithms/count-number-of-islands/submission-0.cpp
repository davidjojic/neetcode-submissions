class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n,vector<bool>(m,false));
        int a[] = {1,-1,0,0};
        int b[] = {0,0,1,-1};
        int sol = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && check[i][j] == false){
                    sol++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    check[i][j] = true;
                    while(!q.empty()){
                        auto [x,y] = q.front();q.pop();
                        for(int k = 0;k<4;k++){
                            int nx = x +a[k];
                            int ny = y + b[k];
                            if(nx >=0 && ny >=0 && nx < n && ny < m){
                                if(check[nx][ny] == false && grid[nx][ny] == '1'){
                                    q.push({nx,ny});
                                    check[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return sol;
    }
};
