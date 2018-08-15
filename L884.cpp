class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> s1;
        unordered_map<string, int> s2;

        istringstream iss(A);
        string word;
        while (iss >> word) {
            s1[word]++;
        }

        istringstream iss2(B);
        while (iss2 >> word) {
            s2[word]++;
        }

        vector<string> ans;

        for (const auto& entry : s1) {
            if (entry.second == 1 && s2.find(entry.first) == s2.end()) {
                ans.push_back(entry.first);
            }
        }
        for (const auto& entry : s2) {
            if (entry.second == 1 && s1.find(entry.first) == s1.end()) {
                ans.push_back(entry.first);
            }
        }
        return ans;
    }
};
