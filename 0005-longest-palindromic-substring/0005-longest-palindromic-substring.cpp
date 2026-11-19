class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            int len = r - l - 1;               // loop overshoots by one on each side
            if (len > maxLen) {
                maxLen = len;
                start = l + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i);                      // odd length, center is one char
            expand(i, i + 1);                  // even length, center is between chars
        }
        return s.substr(start, maxLen);
    }
};