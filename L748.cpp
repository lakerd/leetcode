class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> letters;
        for (auto c : licensePlate) {
            char lowerc = tolower(c);
            if (lowerc >= 'a' && lowerc <= 'z') {
                letters[lowerc]++;
            }
        }
        string minword = "";
        int minlen = INT_MAX;
        for (const auto& word : words) {
            unordered_map<char, int> tmp;
            for (const char c : word) {
                char lowerc = tolower(c);
                tmp[lowerc]++;
            }
            bool matches = true;
            for (const auto& letter : letters) {
                const auto it = tmp.find(letter.first);
                if (it == tmp.end() || it->second < letter.second) {
                    matches = false;
                    break;
                }
            }
            if (matches && word.size() < minlen) {
                minlen = word.size();
                minword = word;
            }
        }
        return minword;
    }
};
