#include <vector>
#include <iostream>
using namespace std;

int searchInsertionPosition(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main ()
{
    vector<int> num1 {1,3,5,7,9};
    int tar1 = 6;

    cout << searchInsertionPosition(num1, tar1) << endl;

    vector<int> num2 {1,3,3,3,3};
    int tar2 = 3;


    cout << searchInsertionPosition(num2, tar2) << endl;

    return 0;
}
