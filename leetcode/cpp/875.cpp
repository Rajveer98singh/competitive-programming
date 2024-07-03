#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (hourTaken(piles, mid) <= h) {
                high = mid; // try to find a smaller k
            } else {
                low = mid + 1; // increase the eating speed
            }
        }

        return low;
    }

private:
    int hourTaken(const vector<int>& piles, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // This ensures we round up without using floating-point division
        }
        return hours;
    }
};


int main() {
    Solution solution;

    vector<int> piles = {30,11,23,4,20};
    int h = 9;
    cout << solution.minEatingSpeed(piles,h) <<endl;

    return 0;
}