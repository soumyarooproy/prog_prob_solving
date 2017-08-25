// Return the index of the leftmost element that is NOT less than target; the input sequence may have duplicate elements
int lower_bound(const vector<int>& nums, int target)
{
    // Invariant - maintain [lb, ub] as the possible range in the following loop
    int lb = 0, ub = nums.size();

    // Terminate loop when lb == ub
    while (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] < target) 
            // mid is not a candidate, target is after mid
            lb = mid + 1;
        else // (nums[mid] >= target)
            // mid is a candidate
            ub = mid;
    }

    // If target does not exist in nums, return index past the last index in nums
    return lb == nums.size() || target != nums[lb] ? nums.size() : lb;
}

// Return the index of the leftmost element that is greater than target; the input sequence may have duplicate elements
int upper_bound(const vector<int>& nums, int target)
{
    // Invariant - maintain [lb, ub] as the possible range in the following loop
    int lb = 0, ub = nums.size();

    // Terminate loop when lb == ub
    while (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] > target)
            // mid is a candidate
            ub = mid;
        else // (nums[mid] <= target)
            // mid is not a candidate, target is before mid
            lb = mid + 1;
    }

    return ub;
}

pair<int, int> equal_range(const vector<int>& nums, int target)
{
    return make_pair(lower_bound(nums, target), upper_bound(nums, target));
    // This can be optimized so that upper_bound() is run on the range starting at index past
    // what is returned by lower_bound() through the end
}
    
// Return the index of the minimum element in a cyclically sorted sequence of distinct elements
int find_min_cyclically_sorted(vector<int>& nums)
{
    // Invariant - maintain [lb, ub] as the possible range in the following loop
    int lb = 0, ub = nums.size() - 1;

    // Terminate loop when lb == ub
    while (lb < ub) {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] > nums[ub])
            // mid is not a candidates, minimum is after mid
            lb = mid + 1;
        else // (nums[mid] < nums[ub])
            // mid is a candidate
            ub = mid;
    }

    return lb;
}
