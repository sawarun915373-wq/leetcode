class Solution {
public:
    int romanToInt(string s) {
        auto val = [](char c) {
            switch (c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                default:  return 1000;
            }
        };

        int n = s.size(), total = 0;
        for (int i = 0; i < n; i++) {
            int cur = val(s[i]);
            if (i + 1 < n && cur < val(s[i + 1])) total -= cur;
            else total += cur;
        }
        return total;
    }
};