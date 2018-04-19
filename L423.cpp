class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> letters;
        for (char c : s) {
            letters[c]++;
        }

        vector<pair<char, string>> v = {
            {'z', "zero"},
            {'g', "eight"},
            {'h', "three"},
            {'w', "two"},
            {'x', "six"},
            {'s', "seven"},
            {'v', "five"},
            {'r', "four"},
            {'o', "one"},
            {'i', "nine"}
        };

        vector<char> numbers = {'z', 'o', 'w', 'h', 'r', 'v', 'x', 's', 'g', 'i'};
        unordered_map<char, int> counts;

        string res = "";

        for (const auto& entry : v) {
            int cnt = letters[entry.first];
            counts[entry.first] += cnt;
            while (cnt--) {
                for (char c : entry.second) {
                    letters[c]--;
                }
            }
        }

        int len = numbers.size();
        for (int i = 0; i < len; ++i) {
            char letter = numbers[i];
            while (counts[letter]-- > 0) {
                res += to_string(i);
            }
        }
        return res;
    }
};
