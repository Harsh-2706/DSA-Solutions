class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;
        int w = words[0].size(), n = words.size();
        unordered_map<string,int> mp;
        for (auto &x : words) mp[x]++;

        for (int i = 0; i < w; i++) {
            unordered_map<string,int> seen;
            int l = i, cnt = 0;
            for (int r = i; r + w <= s.size(); r += w) {
                string t = s.substr(r, w);
                if (mp.count(t)) {
                    seen[t]++; cnt++;
                    while (seen[t] > mp[t]) {
                        seen[s.substr(l, w)]--;
                        l += w; cnt--;
                    }
                    if (cnt == n) res.push_back(l);
                } else {
                    seen.clear(); cnt = 0; l = r + w;
                }
            }
        }
        return res;
    }
};
