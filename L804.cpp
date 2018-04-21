class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes {".-","-...","-.-.","-..",".","..-.",
                              "--.","....","..",".---","-.-",".-..",
                              "--","-.","---",".--.","--.-",".-.",
                              "...","-","..-","...-",".--","-..-",
                              "-.--","--.."};

        unordered_set<string> transformations;
        for (const string& word : words) {
            string transformation = "";
            for (char letter : word) {
                transformation += codes[letter - 'a'];
            }
            transformations.insert(transformation);
        }

        return transformations.size();
    }
};
