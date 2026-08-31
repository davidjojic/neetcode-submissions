class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            unordered_set<int>mp;
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if(mp.find(num) != mp.end())
                    return false;
                mp.insert(num);
            }
        }
        for(int j = 0;j<9;j++){
            unordered_set<int>mp;
            for(int i = 0;i<9;i++){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                if(mp.find(num) != mp.end())
                    return false;
                mp.insert(num);
            }
        }
        int a[] ={0,0,0,1,1,1,2,2,2};
        int b[] ={0,1,2,0,1,2,0,1,2};
        for(int i = 0;i<9;i+=3){
            for(int j =0;j<9;j+=3){
                unordered_set<int>mp;
                for(int u = 0;u<9;u++){
                    int ni = i+a[u];
                    int nj = j+b[u];
                    if(board[ni][nj] == '.')
                        continue;
                    int num = board[ni][nj] - '0';
                    if(mp.find(num) != mp.end())
                        return false;
                    mp.insert(num);
                }
            }
        }
        return true;
    }
};
