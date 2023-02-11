//Aprocah I
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto s:strs){
            string tmp = s;
            sort(begin(s), end(s)); //m log(m)
            mp[s].push_back(tmp);
        }
        //total complexity = n * m * log(m)
        vector<vector<string>>ans;
        for(auto &[key, val]:mp){
            vector<string>sAns;
            for(auto s:val){
                sAns.push_back(s);
            }
            ans.push_back(sAns);
        }
        return ans;
    }
};


//Aproach II
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(auto s:strs){
            vector<int>tmp(26,0);
            for(char c:s){ // o(m)
                tmp[c-'a']++;
            }
            mp[tmp].push_back(s);  //log(n)
        }
        //total = n*m + n*log(n)
        vector<vector<string>>ans;
        for(auto &[key, val]:mp){
            vector<string>sAns;
            for(auto s:val){
                sAns.push_back(s);
            }
            ans.push_back(sAns);
        }
        return ans;
    }
};