/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mylistnode = new ListNode();
        ListNode* lastnode = mylistnode;
        ListNode* mylist = mylistnode;
        if (!list1) return list2;
        if (!list2) return list1;
        //determine next node
        while (1) {
            if (!list1 && !list2) {
                return mylistnode;
            } else if (!list1){
                lastnode->next = new ListNode(list2->val, list2->next);
                return mylistnode;
            } else if (!list2) {
                lastnode->next = new ListNode(list1->val, list1->next);
                return mylistnode;
            }
            
            //both list are not empty
            int cur_val;
            if (list1->val <= list2->val) {
                cur_val = list1->val;
                list1 = list1->next;
            } else {
                cur_val = list2->val;
                list2 = list2->next;
            }
            mylist->val = cur_val;
            mylist->next = new ListNode();
            lastnode = mylist;
            mylist = mylist->next;
        }
    }
};
// @lc code=end

