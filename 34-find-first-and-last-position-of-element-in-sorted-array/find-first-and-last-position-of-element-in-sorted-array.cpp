class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        auto l = lower_bound(nums.begin(), nums.end(), t);
        auto r = upper_bound(nums.begin(), nums.end(), t);
        if (l == nums.end() || *l != t) return {-1,-1};
        return {(int)(l-nums.begin()), (int)(r-nums.begin()-1)};
    }
};
