class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        if (leftBorder == -1) return {-1, -1};
        else return {leftBorder, rightBorder};
    }
    
private:
     // Returns -1 if not found, get the high border
     int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        
        // Invariant: target in [left, right + 1]
        while (left <= right) {
            int middle = left + ((right - left) / 2); // Prevent integer overflow
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                left = middle + 1;
                rightBorder = left;
            }
        }
        
        return rightBorder - 1;
    }
    
    // Returns -1 if not found, get the low border
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        
        // Invariant: target in [left, right + 1]
        while (left <= right) {
            int middle = left + ((right - left) / 2); // Prevent integer overflow
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
                leftBorder = right;
            }
        }
        
        return leftBorder + 1;
    }
};