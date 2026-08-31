class Solution {
public:
    void rek(string s, int open, int close, int n, vector<string>& sol) {
        if (s.size() == 2 * n) {
            sol.push_back(s);
            return;
        }

        if (open < n) {
            rek(s + "(", open + 1, close, n, sol);
        }

        if (close < open) {
            rek(s + ")", open, close + 1, n, sol);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        rek("", 0, 0, n, sol);
        return sol;
    }
};
