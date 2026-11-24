class Solution {
    unordered_map<string, vector<int>> memo;

    vector<int> solve(const string& s) {
        auto it = memo.find(s);
        if (it != memo.end()) return it->second;

        vector<int> res;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c != '+' && c != '-' && c != '*') continue;

            vector<int> left = solve(s.substr(0, i));
            vector<int> right = solve(s.substr(i + 1));

            for (int a : left) {
                for (int b : right) {
                    if (c == '+') res.push_back(a + b);
                    else if (c == '-') res.push_back(a - b);
                    else res.push_back(a * b);
                }
            }
        }

        if (res.empty()) res.push_back(stoi(s));
        return memo[s] = res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};