class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mymap;
        for (const string& s : strs) {
            string strCopy = s;
            sort(strCopy.begin(), strCopy.end());
            mymap[strCopy].push_back(s);
        }
        
        vector<vector<string>> result;
        
        for (const auto& kv : mymap) {
            result.push_back(kv.second);
        }
        
        return result;
    }
};
