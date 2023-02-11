// same of no of proviances
class Solution {
public:
    vector<int>parr;
    int findParr(int u){
        return parr[u] == u ? u : (parr[u] = findParr(parr[u]));
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = n;
        for(int i=0;i<n;i++) parr.push_back(i);
        
        for(int i=0;i<n;i++){
            int p1 = findParr(i);
            for(int j=0;j<i;j++){
                if(!isConnected[i][j]) continue;
                int p2 = findParr(j);
                if(p1 != p2){
                    parr[p2] = p1;
                    cnt--;
                }
            }
        }
        return cnt;
    }
};