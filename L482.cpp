#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = S.size();
        string result = "";
        result.reserve(len);
        int dashes = 0;
        for (char c : S) {
            if (c == '-') {
                dashes++;
            }
        }
        int groupSize = (len - dashes) / K;
        int firstGroup = (len - dashes) % K;
        int i = 0;
        if (firstGroup != 0) {
            int c = 0;
            while (c < firstGroup) {
                if (S[i] != '-') {
                    c++;
                    result += toupper(S[i]);
                    i++;
                } else {
                    i++;
                }
            }
            if (groupSize) {
                result += '-';
            }
        }
        while (groupSize--) {
            int j = 0;
            while (j < K) {
                if (S[i] != '-') {
                    result += toupper(S[i]);
                    j++;
                    i++;
                } else {
                    i++;
                }
            }
            if (groupSize != 0) {
                result += '-';
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string res;
    res = s.licenseKeyFormatting("5F3Z-2e-9-w", 4);
    cout << res << endl;
    return 0;
}
