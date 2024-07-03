#include <iostream>
#include <vector>

using namespace std;

class BinarySearch
{
public:
    int binarySearch(vector<int> v, int target) // Implementation of Iterative  Binary Search Algorithm:
    {
        int l = 0;
        int h = v.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (v[mid] == target)
                return mid;
            if (v[mid] > target)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }

    int binarySearchRecursive(vector<int> v, int target)
    {
        int l = 0;
        int h = v.size() - 1;
        return helperBinarySearchRecursive(v, target, l, h);
    }

private:
    int helperBinarySearchRecursive(vector<int> v, int target, int low, int high)
    {
        if (high >= low)
        {
            int mid = low + (high - low) / 2;
            if (v[mid] == target)
                return mid;
            if (v[mid] > target)
            {
                return helperBinarySearchRecursive(v, target, low, mid - 1);
            }
            else
            {
                return helperBinarySearchRecursive(v, target, mid + 1, high);
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int target = 6;

    BinarySearch binarySearch;
    cout << "binarySearch: " << binarySearch.binarySearch(v, target) << endl;
    cout << "binarySearchRecursive: " << binarySearch.binarySearchRecursive(v, target) << endl;

    return 0;
}


// Time Complexity: 
// Best Case: O(1)
// Average Case: O(log N)
// Worst Case: O(log N)
// Auxiliary Space: O(1), If the recursive call stack is considered then the auxiliary space will be O(logN).