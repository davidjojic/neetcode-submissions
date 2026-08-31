class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>udaljenosOdVode(n,vector<int>(m,numeric_limits<int>::max()));
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    udaljenosOdVode[i][j] = 0;
                }
            }
        }
        int a[] = {1,-1,0,0};
        int b[] = {0,0,1,-1};
        while(!q.empty()){
            int k = q.size();
            while(k--){
                auto[x,y] = q.front();
                q.pop();
                for(int u = 0;u<4;u++){
                    int nx= x+ a[u];
                    int ny = y+ b[u];
                    if(nx>= 0 && ny >= 0 && nx < n  && ny <m && grid[nx][ny] != -1 && udaljenosOdVode[nx][ny] > udaljenosOdVode[x][y] + 1){
                        udaljenosOdVode[nx][ny] = udaljenosOdVode[x][y] + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2147483647){
                    grid[i][j] = udaljenosOdVode[i][j];
                }
            }
        }
    }
};
