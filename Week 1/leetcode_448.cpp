/*
 * @Author: mai xu
 * @Date: 2022-05-09 17:22:29
 * @LastEditors: xumai07 maizehsu@outlook.com
 * @LastEditTime: 2022-05-09 21:43:38
 * @FilePath: \Spark CN\Week 1\leetcode_448.cpp
 * @Description: 448. Find All Numbers Disappeared in an array
 * @Link https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 */

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // 新数组储存 1-n
        vector<int> ascendArray;
        for (int i = 0; i < nums.size(); i++)
        {
            ascendArray.push_back(i + 1);
        };
        // nums去重
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        // nums 升序
        sort(nums.begin(), nums.end());
        // nums和储存1-n的数组求差集
        vector<int> diff;
        set_difference(ascendArray.begin(), ascendArray.end(), nums.begin(), nums.end(), inserter(diff, diff.begin()));
        return diff;
    }
};
