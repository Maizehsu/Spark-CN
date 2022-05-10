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
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v, v.begin()));//求交集 
	return v;
}

vector<int> vectors_set_union(vector<int> v1,vector<int> v2){
	vector<int> v;
	sort(v1.begin(),v1.end());   
	sort(v2.begin(),v2.end());   
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),std::inserter(v, v.begin()));//求并集 
	return v;
}
~~~

#### Reference

[1]. https://www.cplusplus.com/reference/algorithm/unique/

[2]. https://blog.csdn.net/yongh701/article/details/51406458

[3]. https://www.cplusplus.com/reference/vector/vector/erase/

[4]. https://zhuanlan.zhihu.com/p/442460352