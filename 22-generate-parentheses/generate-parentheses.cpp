class Solution {
public:
    vector<string> res;
    void dfs(string s, int open, int close) {
        if (open == 0 && close == 0) { res.push_back(s); return; }
        if (open > 0) dfs(s + "(", open - 1, close);
        if (close > open) dfs(s + ")", open, close - 1);
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
};
