class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        
        for(int num : nums) {
            mp[num]++;
        }

        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for(auto it : mp) {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

       
        for(int i = n; i >= 1 && ans.size() < k; i--) {

            for(int num : bucket[i]) {

                ans.push_back(num);

               
            }
        }

        return ans;
    }
};