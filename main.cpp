#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(nums, 0, path, ans);
        return ans;
    }

private:
    void dfs(const vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, ans);
            path.pop_back();
        }
    }
};

void printSubsets(const vector<vector<int>>& subsets) {
    cout << "[";
    for (size_t i = 0; i < subsets.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < subsets[i].size(); ++j) {
            cout << subsets[i][j];
            if (j < subsets[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < subsets.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    cout << "Input: nums = [1,2,3]" << endl;
    vector<vector<int>> result1 = solution.subsets(nums1);
    cout << "Output: ";
    printSubsets(result1);

    vector<int> nums2 = {0};
    cout << "Input: nums = [0]" << endl;
    vector<vector<int>> result2 = solution.subsets(nums2);
    cout << "Output: ";
    printSubsets(result2);

    return 0;
}
