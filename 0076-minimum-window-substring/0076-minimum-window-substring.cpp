class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return "";

        int need[128] = {0};
        for (char c : t) need[(int)c]++;

        int missing = n;
        int left = 0, bestStart = 0, bestLen = INT_MAX;

        for (int right = 0; right < m; right++) {
            if (need[(int)s[right]]-- > 0) missing--;

            while (missing == 0) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                if (++need[(int)s[left]] > 0) missing++;
                left++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};