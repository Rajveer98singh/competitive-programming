#include <iostream>
#include <vector>

using namespace std;
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution solution;
    ListNode* a1 = new ListNode(1);
    ListNode* b1 = new ListNode(8);
    ListNode* c1 = new ListNode(4);
    a1->next=b1;
    b1->next=c1;
    ListNode* a2 = new ListNode(1);
    ListNode* b2 = new ListNode(3);
    ListNode* c2 = new ListNode(6);
    a2->next=b2;
    b2->next=c2;

     ListNode* res = solution.addTwoNumbers(a1,a2);

    while(res!=nullptr){
        cout<<res->val<<"->";
        res = res->next;
    }
    cout<<"nullptr"<<endl;
    // Write your main logic here

    return 0;
}