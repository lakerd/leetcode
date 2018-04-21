#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> lookup(26, INT_MAX);
        int len = S.size();
        for (int i = 0; i < len; ++i) {
            lookup[S[i] - 'a'] = i;
        }

        std::sort(T.begin(), T.end(), [&lookup](char c1, char c2) {
            return lookup[c1 - 'a'] < lookup[c2 - 'a'];
        });
        return T;
    }
};

int main()
{
    string s = "hucw";
    string t = "utzoampdgkalexslxoqfkdjoczajxtuhqyxvlfatmptqdsochtdzgypsfkgqwbgqbcamdqnqztaqhqanirikahtmalzqjjxtqfnh";
    Solution sol;
    string res = sol.customSortString(s, t);

    cout << res << endl;

    return 0;
}
