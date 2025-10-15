#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
    bool inc = true;
    bool dec = true;
    for (int i = 0; i < numsSize - 1; i++) {
        inc &= (nums[i] <= nums[i+1]);
        dec &= (nums[i] >= nums[i+1]);
    }
    return inc || dec;
}