class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), cnt = words.size(), w = words[0].size();
        if (n < cnt * w) return res;

        unordered_map<string, int> need;
        for (auto& x : words) need[x]++;

        for (int off = 0; off < w; off++) {
            unordered_map<string, int> seen;
            int left = off, matched = 0;

            for (int right = off; right + w <= n; right += w) {
                string cur = s.substr(right, w);

                if (!need.count(cur)) {
                    seen.clear();
                    matched = 0;
                    left = right + w;
                    continue;
                }

                seen[cur]++;
                matched++;

                while (seen[cur] > need[cur]) {
                    seen[s.substr(left, w)]--;
                    matched--;
                    left += w;
                }

                if (matched == cnt) {
                    res.push_back(left);
                    seen[s.substr(left, w)]--;
                    matched--;
                    left += w;
                }
            }
        }
        return res;
    }
};