class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> s(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        int len = paragraph.size();
        for (int i = 0; i < len; ++i) {
            char c = paragraph[i];
            if (isalpha(c)) {
                string w = "";
                while (isalpha(paragraph[i])) {
                    w += tolower(paragraph[i]);
                    i++;
                }
                freq[w]++;
            }
        }

        string mostFreq = "";
        int curFreq = INT_MIN;
        for (const auto& entry : freq) {
            if (s.find(entry.first) == s.end() && curFreq < entry.second) {
                mostFreq = entry.first;
                curFreq = entry.second;
            }
        }
        return mostFreq;
    }
};
