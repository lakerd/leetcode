class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> rounds;
        rounds.reserve(ops.size());
        for (const auto& op : ops) {
            int len = rounds.size();
            if (op == "+") {
                int i1 = rounds[len - 1];
                int i2 = rounds[len - 2];
                rounds.push_back(i1 + i2);
            } else if (op == "D") {
                int last = rounds[len - 1];
                rounds.push_back(last * 2);
            } else if (op == "C") {
                rounds.pop_back();
            } else {
                int n = stoi(op);
                rounds.push_back(n);
            }
        }
        
        int result = 0;
        for (auto i : rounds) {
            result += i;
        }
        return result;
    }
};
