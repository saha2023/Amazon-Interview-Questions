//TLE
class Solution {
    vector<int> nextDay(vector<int>& presDay){
        vector<int>nextDay(8,0);
        for(int i=1;i<=6;i++){
            nextDay[i] = presDay[i-1] == presDay[i+1];
        }
        return nextDay;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int>ithAay = cells;
        for(int i=1;i<=n;i++){
            ithAay = nextDay(ithAay);
        }
        return ithAay;
    }
};

//optimisation I
class Solution {
    vector<int> nextDay(vector<int>& presDay){
        vector<int>nextDay(8,0);
        for(int i=1;i<=6;i++){
            nextDay[i] = presDay[i-1] == presDay[i+1];
        }
        return nextDay;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int>ithAay = cells;
        vector<vector<int>>mem;
        for(int i=1;i<=n;i++){
            ithAay = nextDay(ithAay);
            if(mem.size() and mem.front() == ithAay){
                return mem[(n-i)%mem.size()];
            }
            else mem.push_back(ithAay);
        }
        return ithAay;
    }
};