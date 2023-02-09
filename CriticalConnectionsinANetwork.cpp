// find the bridges uaing tarjan
class Solution {
vector<int>disc, low;
vector<vector<int>>res;
void tarjan(vector<int>graph[], int u, int parr){
    static int timeStamp = 0;
    disc[u] = low[u] = ++timeStamp;
    for(auto v: graph[u]){
        if(disc[v] == 0){
            tarjan(graph, v, u);
            low[u] = min(low[v], low[u]);
            if(disc[u] < low[v]){
                res.push_back({u, v});
            }
        }
        else if(v != parr){
            low[u] = min(low[u], low[v]);
        }
    }
}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        disc.resize(n,0);
        low.resize(n,0);
        vector<int>graph[n];
        for(auto edge: connections){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(disc[i]) continue;
            tarjan(graph, i, -1);
        }
        return res;
    }
};