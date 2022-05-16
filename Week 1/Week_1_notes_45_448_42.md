## Leetcode 448. Find All Numbers Disappeared in an Array

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return *an array of all the integers in the range* `[1, n]` *that do not appear in* `nums`.

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

**Example 2:**

```
Input: nums = [1,1]
Output: [2]
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 105`
- `1 <= nums[i] <= n`

**Follow up:** Could you do it without extra space and in `O(n)` runtime? You may assume the returned list does not count as extra space.

#### My Solution

~~~c++
    vector<int> findDisappearedNumbers(vector<int>& nums) {
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
~~~

Time complexity: O(N);

Space complexity: O(N);

思路：Intuitively会想到新建一个长度为N的数组储存1-n的数据，之后和nums做排序（去重）+差集即可得出结果。

#### Best Solution

~~~c++
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
		
        // 1st for loop: nums = [4,3,2,7,8,2,3,1]
        for(int i = 0; i < nums.size(); i++)  // each iteration:
        {                                     // i = 0              i = 1                ... i = 7
            int temp = nums[i];               // temp = 4           temp = 3             ... temp = -1
            temp = (temp > 0) ? temp : -temp; // temp = 4           temp = 3             ... temp = 1
            if(nums[temp-1] > 0)              // nums[3] > 0        nums[2] > 0          ... nums[0] > 0
                nums[temp-1] *= -1;           // [4,3,2,-7,8,2,3,1] [4,3,-2,-7,8,2,3,1]  ... [-4,-3,-2,-7,8,2,-3,-1]
        } 
		
		// 2nd for loop: nums = [-4,-3,-2,-7,8,2,-3,-1]
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)         // the 4th & 5th indexes are positive
                ans.push_back(i+1); // ans = [5,6]
				
        return ans;
    }
~~~

思路：利用数组自带的上下限特性，储存一个二元数组表示该位置的数字是否存在。e.x. [0, 0, 0, 1, 1, 0, 0, 0]

#### Eliminate Repetition

`nums.erase(unique(nums.begin(), nums.end()), nums.end());` 

**vector的erase函数和unique函数结合**

`unique(first, last)` ：

> Removes all but the first element from every consecutive group of equivalent elements in the range `[first,last)`. 
>
> The function cannot alter the properties of the object containing the range of elements (i.e., it cannot alter the size of an array or a container): The removal is done by replacing the duplicate elements by the next element that is not a duplicate, and signaling the new size of the shortened range by returning an iterator to the element that should be considered its new *past-the-end* element.$^{[1]}$

即将相邻且重复的元素放到vector的尾部，然后返回指向第一个重复元素的迭代器。

`erase(position); erase(first, last)`

erase函数抹除指定位置/范围的vector，input为迭代器

> Removes from the vector either a single element (position) or a range of elements ([first,last)).This effectively reduces the container size by the number of elements removed, which are destroyed.
>
> Because vectors use an array as their underlying storage, erasing elements in positions other than the vector end causes the container to relocate all the elements after the segment erased to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).$^{[3]}$

#### Difference Set$^{[4]}$

~~~c++
template <typename T>
std::vector<T> diff_cmp(std::vector<T>& first, std::vector<T>& second) {
    std::vector<T> diff;
    /* 排序 */
    std::sort(first.begin(), first.end(), std::less<T>());
    std::sort(second.begin(), second.end(), std::less<T>());
    /* 求两个集合差集 */
    std::set_difference(first.begin(), first.end(), second.begin(),
                        second.end(), std::inserter(diff, diff.begin()));
    return diff;
}
~~~

#### Other Set Operation$^{[2]}$

~~~c++
vector<int> vectors_intersection(vector<int> v1,vector<int> v2){
	vector<int> v;
	sort(v1.begin(),v1.end());   
	sort(v2.begin(),v2.end());   
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v, v.begin())); //求交集 
	return v;
}

vector<int> vectors_set_union(vector<int> v1,vector<int> v2){
	vector<int> v;
	sort(v1.begin(),v1.end());   
	sort(v2.begin(),v2.end());   
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v, v.begin())); //求并集 
	return v;
}
~~~



## Leetcode 45. Jump Game II

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [2,3,0,1,4]
Output: 2
```

**Constraints:**

- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 1000`

#### My Solution

Following this video https://www.youtube.com/watch?v=Ua_Vqtdd61E , applyng BFS.

~~~c++
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
~~~



## Leetcode 42. Trapping Rain Water

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:**

![img](../../../../GitHub/FigureBed/rainwatertrap.png)

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

- `n == height.length`
- `1 <= n <= 2 * 104`
- `0 <= height[i] <= 105`

#### Best Solution

思路：对撞指针。

~~~c++
class Solution {
public:
    int trap(int A[], int n) {
        int left = 0; int right = n-1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while(left <= right){
            if(A[left] <= A[right]){
                if(A[left] >= maxleft) maxleft = A[left];
                else res + =maxleft - A[left];
                left++;
            }
            else{
                if(A[right] >= maxright) maxright = A[right];
                else res += maxright - A[right];
                right--;
            }
        }
        return res;
    }
};
~~~

更简洁的写法：https://github.com/luliyucoordinate/Leetcode/blob/master/src/0042-Trapping-Rain-Water/0042.cpp

~~~c++
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r) 
        {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};
~~~



#### Reference

[1]. https://www.cplusplus.com/reference/algorithm/unique/

[2]. https://blog.csdn.net/yongh701/article/details/51406458

[3]. https://www.cplusplus.com/reference/vector/vector/erase/

[4]. https://zhuanlan.zhihu.com/p/442460352