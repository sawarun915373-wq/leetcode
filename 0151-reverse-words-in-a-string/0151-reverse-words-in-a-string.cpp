class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), w = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (w > 0) s[w++] = ' ';
                while (i < n && s[i] != ' ') s[w++] = s[i++];
            }
        }
        s.resize(w);

        reverse(s.begin(), s.end());

        int start = 0;
        for (int i = 0; i <= w; i++) {
            if (i == w || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};