class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> domains;
        for (const string& domain : cpdomains) {
            int len = domain.size();
            int count = -1;
            for (int i = 0; i < len; ++i) {
                if (domain[i] == ' ') {
                    string cnt = "";
                    for (int j = 0; j < i; ++j) {
                        cnt += domain[j];
                    }
                    count = stoi(cnt);
                    string subdomain = "";
                    for (int j = i + 1; j < len; ++j) {
                        subdomain += domain[j];
                    }
                    domains[subdomain] += count;
                } else if (domain[i] == '.') {
                    string subdomain = "";
                    for (int j = i + 1; j < len; ++j) {
                        subdomain += domain[j];
                    }
                    domains[subdomain] += count;
                }
            }
        }

        for (const auto& entry : domains) {
            ans.push_back(to_string(entry.second) + " " + entry.first);
        }
        return ans;
    }
};
