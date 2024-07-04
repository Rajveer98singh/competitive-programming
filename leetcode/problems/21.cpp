#include <iostream>
#include <vector>

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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *currNode = &dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                currNode->next = list1;
                list1 = list1->next;
            }
            else
            {
                currNode->next = list2;
                list2 = list2->next;
            }
            currNode = currNode->next;
        }
        if (list1 != nullptr)
        {
            currNode->next = list1;
        }
        if (list2 != nullptr)
        {
            currNode->next = list2;
        }
        return dummy.next;
    }
};

int main()
{
    Solution solution;
    ListNode* a1 = new ListNode(1);
    ListNode* b1 = new ListNode(2);
    ListNode* c1 = new ListNode(4);
    a1->next=b1;
    b1->next=c1;
    ListNode* a2 = new ListNode(1);
    ListNode* b2 = new ListNode(3);
    ListNode* c2 = new ListNode(4);
    a2->next=b2;
    b2->next=c2;

    ListNode* res = solution.mergeTwoLists(a1,a2);

    while(res!=nullptr){
        cout<<res->val<<"->";
        res = res->next;
    }
    cout<<"nullptr"<<endl;


    // Write your main logic here

    return 0;
}