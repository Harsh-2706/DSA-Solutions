class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long rev = 0, orig = x;

        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == orig;
    }
};
