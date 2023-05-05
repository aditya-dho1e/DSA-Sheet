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
    void solve(ListNode* head, vector<int>&arr){
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        solve(head,v);
        vector<int>v2 = v;
        reverse(v2.begin(),v2.end());
        return v == v2;
    }
};
