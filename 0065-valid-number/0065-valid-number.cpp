class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false, seenDot = false, seenExp = false;
        bool digitAfterExp = true;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenExp) digitAfterExp = true;
            } else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else if (c == '.') {
                if (seenDot || seenExp) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                digitAfterExp = false;
            } else {
                return false;
            }
        }
        return seenDigit && digitAfterExp;
    }
};