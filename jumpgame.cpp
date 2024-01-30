#include <iostream>
using namespace std;

bool canJump(std::vector<int>& nums, int index) {
    if (index >= nums.size()-1) {
        return true;
    }

    int moves = nums[index];
    // if (moves == 0) {
    //     return false;
    // }

    // Try all possible moves
    for (int i = 1; i <= moves; i++) {
        // cout << i<<endl;
        bool kyahua = canJump(nums, index + i);
        // cout << kyahua<<endl;
        if (kyahua) {
            return true;
        }
    }

    // If none of the moves lead to a successful jump
    return false;
}

int main()
{
    vector<int> nums{3,2,1,1,4};
    cout << canJump(nums, 0);
}