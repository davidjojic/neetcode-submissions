class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int sol = 0;
        for(int i =0;i<heights.size();i++){
            int lst = i;
            while(!st.empty() && st.top().first > heights[i]){
                sol=max(sol,st.top().first*(i-st.top().second));
                lst=st.top().second;
                st.pop();
            }
            st.push({heights[i],lst});
        }
        int lst = heights.size()-1;
        while(!st.empty()){
            sol=max(sol,st.top().first*(lst-st.top().second+1));
            st.pop();
        }
        return sol;
    }
};
