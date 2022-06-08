/*
 * @Author: mai xu
 * @Date: 2022-05-09 17:22:29
 * @LastEditors: xumai07 maizehsu@outlook.com
 * @LastEditTime: 2022-05-12 13:16:10
 * @FilePath: \Spark CN\Week 1\leetcode_448.cpp
 * @Description: 45. Jump Game II
 * @Link https://leetcode.com/problems/jump-game-ii/
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int start = 0, end = 0;
        int step = 0;
        // Corner case: size = 1
        if (nums.size() == 1)
            return 0;

        while (start <= end)
        {
            int end_new = end;
            for (int i = start; i <= end; i++)
            {
                end_new = max(end_new, i + nums[i]);
                if (end_new >= nums.size() - 1)
                    return step + 1;
            }
            step += 1;
            // Stores the farthest place in the last step
            start = end + 1;
            end = end_new;
        }
        return -1;
    }
};