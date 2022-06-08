/*
 * Sliding window
 * Time complexity: O(N)
 * Spae complexity: O(1)
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sIndex = 0, size = nums.size();
        int sum = 0, count = size + 1;
        for (int fIndex = 0; fIndex < size; fIndex++) {
            sum += nums[fIndex];
            while (sum >= target) {
                int temp = fIndex - sIndex + 1;
                if (temp <= count) count = temp;
                sum -= nums[sIndex++];
            }
        }
        return count == (size + 1) ? 0 : count;
    }
};