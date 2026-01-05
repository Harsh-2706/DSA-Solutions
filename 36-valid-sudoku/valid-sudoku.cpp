class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        set<string> s;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (b[i][j] != '.') {
                    string r = "r"+to_string(i)+b[i][j];
                    string c = "c"+to_string(j)+b[i][j];
                    string g = "g"+to_string(i/3)+to_string(j/3)+b[i][j];
                    if (!s.insert(r).second || !s.insert(c).second || !s.insert(g).second)
                        return false;
                }
        return true;
    }
};
