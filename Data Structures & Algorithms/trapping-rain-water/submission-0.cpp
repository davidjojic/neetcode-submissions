class Solution {
public:
    int trap(vector<int>& height) {
        
        int lh = height[0] , rh = 0;
        for(int i = 1;i < height.size() ;i++ )
            rh = max(height[i] , rh);
        int sol = 0;
        for(int i = 1;i < height.size() - 1;i++)
        {
            lh = max(lh, height[ i- 1]);
            if(rh == height[i])
            {
                rh = 0;
                for(int u = i + 1; u < height.size();u++)
                {
                    rh = max(height[u] , rh);
                }
            }
            if(min(lh,rh) - height[i] > 0)
             sol += min(lh,rh) - height[i];
        }
        return sol;
    }
};
