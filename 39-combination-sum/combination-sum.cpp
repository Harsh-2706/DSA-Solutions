class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& c, int t, int i, vector<int>& cur) {
        if (t == 0) {
            res.push_back(cur);
            return;
        }
        if (t < 0 || i == c.size()) return;

        // pick current element
        cur.push_back(c[i]);
        dfs(c, t - c[i], i, cur);
        cur.pop_back();

        // skip current element
        dfs(c, t, i + 1, cur);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> cur;        // ✅ create real vector
        dfs(c, t, 0, cur);      // ✅ pass it
        return res;
    }
};
