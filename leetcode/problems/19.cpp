#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return nullptr;
        int s = ListSize(head)-n;
        if(s == 0){
            ListNode* newNode = head->next;
            delete(head);
            return newNode;
        }
        ListNode* curr = head;
        while(curr!=nullptr){
            s--;
            if(s ==0) break;
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
        
        return head;
    }
private:
    int ListSize(ListNode* head){
        int s =0;
        while(head!=nullptr){
            s++;
            head = head->next;
        }
        return s;
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

    int n = 3;

    ListNode* res = solution.removeNthFromEnd(a,n);

    while(res!=nullptr){
        cout<<res->val<<"->";
        res = res->next;
    }
    cout<<"nullptr"<<endl;

    // Write your main logic here

    return 0;
}