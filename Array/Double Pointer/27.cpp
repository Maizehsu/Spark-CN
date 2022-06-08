/** 
  * Violent solution 
  * Time complecity: O(N^2)
  * Space complecity: O(1)
  */
  
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i; j < size - 1; j++) {
                    nums[j] = nums[j + 1];    
                }    
                size--;
                i--;
            }                
        }
        return size;
    }
};

/** 
  * Double Pointers 
  * Time complecity: O(N)
  * Space complecity: O(1)
  */
  
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};