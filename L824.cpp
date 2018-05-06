class Solution {
public:
    string toGoatLatin(string S) {
        string res = "";
        int len = S.size();

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int wordIdx = 1;

        for (int i = 0; i < len; ++i) {
            if (S[i] != ' ') {
                char c = tolower(S[i]);
                string curWord = "";
                while (i < len && S[i] != ' ') {
                    curWord += S[i];
                    ++i;
                }

                if (vowels.count(c) == 0) {
                    string newword = "";
                    for (int j = 1; j < curWord.size(); ++j) {
                        newword += curWord[j];
                    }
                    newword += curWord[0];
                    curWord = newword;
                }
                curWord += "ma";

                for (int k = 0; k < wordIdx; ++k) {
                    curWord += "a";
                }
                wordIdx++;

                res += curWord;
                if (i < len - 1) {
                    res += " ";
                }
            }
        }
        return res;
    }
};
