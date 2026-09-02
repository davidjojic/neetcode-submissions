class Solution {
private:
    int idx(char c) {
        if(c >= 'a' && c <= 'z')
            return c - 'a';

        return 26 + (c - 'A');
    }

public:
    string minWindow(string s, string t) {
        string sol = "";

        uint64_t mask = (1ULL << 52) - 1;
        uint64_t tren_mask = mask;

        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;

            tren_mask &= ~(1ULL << idx(c));
        }

        int l = 0;

        for(int i = 0; i < s.size(); i++) {

            if(mp.find(s[i]) != mp.end()) {

                mp[s[i]]--;

                if(mp[s[i]] == 0) {
                    tren_mask |= (1ULL << idx(s[i]));
                }
            }

            if(tren_mask == mask) {

                while(l <= i) {

                    if(mp.find(s[l]) == mp.end()) {
                        l++;
                    }
                    else if(mp[s[l]] < 0) {
                        mp[s[l]]++;
                        l++;
                    }
                    else {
                        break;
                    }
                }

                if(sol.empty() || i - l + 1 < sol.size()) {
                    sol = s.substr(l, i - l + 1);
                }
            }
        }

        return sol;
    }
};