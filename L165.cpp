#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int len1 = version1.size();
        int len2 = version2.size();

        int n1 = 0;
        int n2 = 0;
        while (i < len1 || j < len2) {
            while (i < len1 && version1[i] != '.') {
                n1 = n1 * 10 + (version1[i] - '0');
                ++i;
            }

            while (j < len2 && version2[j] != '.') {
                n2 = n2 * 10 + (version2[j] - '0');
                ++j;
            }

            if (n1 > n2)
                return 1;
            if (n1 < n2)
                return -1;

            n1 = 0;
            n2 = 0;
            ++i;
            ++j;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1", "0") << endl;
    return 0;
}
