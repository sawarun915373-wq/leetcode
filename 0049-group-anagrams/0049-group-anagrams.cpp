class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (auto& s : strs) {
            string key(26, 0);
            for (char c : s) key[c - 'a']++;
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& g : groups) res.push_back(move(g.second));
        return res;
    }
};