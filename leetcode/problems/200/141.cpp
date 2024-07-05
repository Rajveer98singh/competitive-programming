#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        int val = 1000000;
        ListNode* curr = head;
        while(curr!=nullptr){
            if(curr->val == val) return true;
            curr->val = val;
            curr = curr->next;
        }
        return false;
    }
};

int main() {
    Solution solution;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(6);
    ListNode* g = new ListNode(7);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=b;

    bool res = solution.hasCycle(a);

    if(res) {
        cout<<"This List have cycles"<<endl;
    }else{
        cout<<"This List does have cycles"<<endl;
    }

    // Write your main logic here

    return 0;
}