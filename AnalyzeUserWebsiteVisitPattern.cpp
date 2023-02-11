class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, map<int, string>> m;
        unordered_map<string, int> freq;
        int maxFreq = 0;
        for (int i = 0; i < username.size(); i++) m[username[i]][timestamp[i]] = website[i];
        for (auto kv: m) {
            unordered_set<string> S;
            map<int, string> twm = kv.second;
            for (auto i = twm.begin(); i != twm.end(); i++)
                for (auto j = next(i); j != twm.end(); j++)
                    for (auto k = next(j); k != twm.end(); k++)
                        S.insert(i->second + " " + j->second + " " + k->second);
            for (auto s:S)
                maxFreq = max(maxFreq, ++freq[s]);
        }
        
        string res;
        for (auto kv:freq)
            if (kv.second == maxFreq)
                res = res.empty() ? kv.first : min(kv.first, res);
        
        vector<string> resVec(3);
        istringstream ss(res);
        ss >> resVec[0] >> resVec[1] >> resVec[2];
        return resVec;
    }
};