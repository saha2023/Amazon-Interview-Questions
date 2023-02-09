class Solution {
public:
// T = O(n) S = O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int i=0;
        for(int y:nums){
            int x = target-y;
            if(mp.count(x)){
                return {mp[x],i};
            }
            mp[y] = i++;
        }
        return {};
    }
};