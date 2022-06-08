## Binary Search

#### Precondition

- Ordered array
- Can only return one result
- Time complexity: **O(logN)**

#### Takeaways

- Be clear about `[Left, Right]` or` [Left, Right)`
- Be clear about invarient. For example in the `[Left, Right]` case, target is always in `[Left, Right + 1]`
- Whenever you hit not found condition **do `s = mid+1` or `e = mid-1`** according to the condition without worrying.
- Default to writing **`mid = s + (e-s)/2`** and NOT **`mid = (s+e)/2`**.
  Reason : The later can result in an overflow when you are not searching in an array but rather on an answer space, specially because binary search if it can be applied is a great tool for huge numbers.

#### Problems

- **Basic**: 704
- **Variant**: 35
- **Advanced**: 34
