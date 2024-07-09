#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Add your methods here
};

int main() {
    Solution solution;

    int arr[6] = {10,2,4,8,6,9};

    priority_queue<int> pqMax;
    for(int i = 0; i < 6; i++){
        pqMax.push(arr[i]);
    }

    cout<< "priority queue max heap: ";
    while(!pqMax.empty()){
        cout<< pqMax.top() << ", ";
        pqMax.pop();
    }
    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pqMin;
    for(int i = 0; i < 6; i++){
        pqMin.push(arr[i]);
    }

    cout<< "priority queue min heap: ";
    while(!pqMin.empty()){
        cout<< pqMin.top() << ", ";
        pqMin.pop();
    }


    // Write your main logic here

    return 0;
}