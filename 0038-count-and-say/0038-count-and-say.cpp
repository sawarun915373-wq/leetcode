class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";

        for (int step = 1; step < n; step++) {
            string next;
            int len = cur.size();

            for (int i = 0; i < len; ) {
                int j = i;
                while (j < len && cur[j] == cur[i]) j++;
                next += to_string(j - i);
                next += cur[i];
                i = j;
            }
            cur = next;
        }
        return cur;
    }
};