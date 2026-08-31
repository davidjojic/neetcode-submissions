class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int sol = 0;
        int n = s.size();
        int lst = 0;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i]) != mp.end())
                lst = max(lst,mp[s[i]]+1);
            mp[s[i]]=i;
            sol=max(sol,i-lst+1);
        }
        return sol;
    }
};
