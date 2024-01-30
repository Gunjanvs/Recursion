// permu2.cpp
void permu(int i, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> seen;  // To handle duplicates
        for (int j = i; j < nums.size(); j++) {
            if (seen.count(nums[j])) continue;  // Skip duplicates
            seen.insert(nums[j]);

            swap(nums[i], nums[j]);
            permu(i + 1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permu(0, nums, ans);
        return ans;
    }