class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> lookup;
        for (char c : J) {
            lookup.insert(c);
        }
        int count = 0;
        for (char c : S) {
            if (lookup.find(c) != lookup.end()) {
                ++count;
            }
        }
        return count;
    }
};
