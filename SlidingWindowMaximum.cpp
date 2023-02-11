/**
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

//susing priority queue is not required unnecessarilly used

// here the most optimised using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>que;
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(que.size() and i - que.front() == k)
                que.pop_front();
            while(que.size() and nums[que.back()] < nums[i])
                que.pop_back();
            que.push_back(i);
            if(i >= k-1)
                ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};
