/*
 * @Author: xumai07 maizehsu@outlook.com
 * @Date: 2022-05-16 18:46:10
 * @LastEditors: xumai07 maizehsu@outlook.com
 * @LastEditTime: 2022-05-16 19:24:02
 * @FilePath: \Spark CN\Week 2\leetcode_2.cpp
 * @Description: leetcode 2. Add Two Numbers
 */

#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Method 1. Purely using new.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *l3 = new ListNode(0);
    ListNode *head = l3;

    while (true)
    {
        // This will be 0 in the first pass, but the carry henceforth.
        int sum = l3->val;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        // Place value (last digit)
        l3->val = (sum % 10);
        // Break out condition
        if ((l1 == NULL) && (l2 == NULL) && sum < 10)
        {
            break;
        }
        // Each node requires a new.
        // Store the carry-over to the next loop
        l3->next = new ListNode(sum / 10);
        l3 = l3->next;
    }

    return head;
};

// Method 2. Double pointer
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int sum = 0;
    ListNode *l3 = NULL;
    // Pointers to l3;
    ListNode **node = &l3;

    while (true)
    {
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        // Place value (last digit)
        (*node) = new ListNode(sum % 10);
        // Break out condition
        if ((l1 == NULL) && (l2 == NULL) && sum < 10)
        {
            break;
        }
        // Store the carry-over to the next loop
        sum /= 10;
        node = &((*node)->next);
    }
    return l3;
}
