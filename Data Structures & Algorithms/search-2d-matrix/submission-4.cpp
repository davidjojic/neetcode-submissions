class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l =0 , r = n;
        int startr;
        
        while(l<r){
            int middle = l+ (r-l)/2;
            if(matrix[middle][m-1] >= target){
                r = middle;
            }else{
                l = middle+1;
            }
        }
        if(l == n)
            return false;
        startr = l;
        auto ptr = lower_bound(matrix[startr].begin(),matrix[startr].end(),target);
        if(ptr == matrix[startr].end() || *ptr != target)
            return false;
        return true;
    }
};
