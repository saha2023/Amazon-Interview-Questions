class Solution {
private:
    int dis(int x, int y){
        int res = ((x*x) + (y*y));
        return res;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>>pq;
        for(vector<int>it:points){
            int gap = dis(it[0],it[1]);
            pq.push({gap,it[0],it[1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<vector<int>>ans;
        
        while(pq.size()>0){
            vector<int>sAns;
            sAns.push_back(pq.top()[1]);
            sAns.push_back(pq.top()[2]);
            ans.push_back(sAns);
            pq.pop();
        }
        
        return ans;
    }
};