#include <string.h>
#include <iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) ;
};


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *result;
    ListNode *dump = new ListNode((int)0);
    ListNode **sum = &result;
    int carry = 0;
    int now = 0;
    while(l1 != dump || l2 != dump || carry != 0)
    {
        now = (l1->val + l2->val + carry)%10;
        carry = (l1->val + l2->val + carry)/10;
        *sum = new ListNode(now);
        sum = &(*sum)->next;    
        if (l2->next == NULL)
            l2 = dump;
        else l2 = l2->next;
        if (l1->next == NULL)
            l1 = dump;
        else l1 = l1->next;
    }
    delete dump;
    return result;
}

void print(ListNode *l)
{
    while (l)
    {
        cout<<(int)l->val<<endl;
        l = l->next;
    }
}
int main()
{
    ListNode *l1 = new ListNode((int)1);
    //l1->next = new ListNode((int)2);
    //l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode((int)9);
    l2->next = new ListNode((int)9);
    Solution s;
    ListNode* r = s.addTwoNumbers(l1, l2);
    print(r);
    cout<<"******"<<endl;
}
