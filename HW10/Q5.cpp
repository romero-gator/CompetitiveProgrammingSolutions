class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        int i = 0, j = 0;
        while (j < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            
            dq.push_back(j);
            if (j-i == k-1) {
                ans.push_back(nums[dq.front()]);
                if (!dq.empty() && dq.front() == i) {
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};