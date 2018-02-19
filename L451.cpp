class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> lookup;
        for (char c : s) {
            lookup[c]++;
        }
        auto cmp = [](pair<char, int> p1, pair<char, int> p2) { return p1.second < p2.second; };
        priority_queue<pair<char, int>, std::vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for (const auto& entry : lookup) {
            pq.push(entry);
        }
        string result = "";
        while (!pq.empty()) {
            auto& entry = pq.top();
            int n = entry.second;
            while (n-- > 0) {
                result += entry.first;
            }
            pq.pop();
        }
        return result;
    }
};
