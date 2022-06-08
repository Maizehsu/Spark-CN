// Bully Solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Double Pointer
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int sIndex = 0, fIndex = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        int size = nums.size(), i = 0;
        while (i + 1 <= size) {
            if (nums[sIndex] * nums[sIndex] > nums[fIndex] * nums[fIndex]) {
                res[size - 1 - i] = nums[sIndex] * nums[sIndex];
                sIndex++;
            }
            else {
                res[size - 1 - i] = nums[fIndex] * nums[fIndex];
                fIndex--;
            }
            i++;
        }
        return res;
    }
};