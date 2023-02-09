// reccursive
class Solution {
    int recc(vector<int>& jobDifficulty, int idx, int d){
        if(d==1){
            return *max_element(jobDifficulty.begin()+idx, jobDifficulty.end());
        }
        int curr_max = 0;
        int res = 1e9;
        for(int i=idx;i<=size(jobDifficulty)-d;i++){
            curr_max = max(curr_max, jobDifficulty[i]);
            int faith = recc(jobDifficulty, i+1, d-1);
            res = min(res, curr_max + faith);
        }
        return res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(size(jobDifficulty)<d) return -1;
        return recc(jobDifficulty, 0, d);
    }
};


//memoised
class Solution {
private:
    vector<vector<int>>dp;
    int recc(vector<int>&jobDifficulty,int n, int idx, int d){
        if(d==1){
            return *max_element(jobDifficulty.begin()+idx, jobDifficulty.end());
        }
        
        int ans = INT_MAX;
        int maxEle = INT_MIN;
        if(dp[idx][d] != -1) return dp[idx][d];
        for(int cut=idx;cut<=n-d;cut++){
            maxEle = max(maxEle, jobDifficulty[cut]);
            int faith = recc(jobDifficulty, n, cut+1, d-1);
            ans = min(ans, maxEle+faith);
        }
        return dp[idx][d]=ans;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.resize(301,vector<int>(11,-1));
        int n = size(jobDifficulty);
        if(n<d) return -1;
        return recc(jobDifficulty,n,0,d);
    }
};


//Tabulisation
