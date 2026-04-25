/*a row of lockers. Some lockers are empty (0), and some have toys in them (numbers like 1, 3, 12).

The goal is to push all the toys to the left so they are side-by-side, leaving all the empty lockers at the very end. But there's a catch: you aren't allowed to make a "copy" of the lockers; you have to do it all inside the same row!

The "Two-Pointer" Strategy
We are going to use two imaginary "friends" to help us:

The Scout (i): This friend walks through every single locker from left to right.

The Keeper (lastNonZeroFoundAt): This friend stays at the spot where the next toy should go.

How it works
The Scout looks at a locker.

If it’s a 0, the Scout just keeps walking.

If it’s a toy (not 0), the Scout shouts to the Keeper. They swap whatever is in their lockers.

The Keeper then moves one step to the right to wait for the next toy.
The only case that bothers is when keeper is zero, scout is non-zero, do the SWAP*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int scout=0,keeper=0;
        for(;scout<n;scout++){
            if(nums[scout]!=0){
                swap(nums[scout],nums[keeper]);
                keeper++;
            }
        }
    }
};