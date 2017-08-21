vector<int> find_k_closest(const vector<int>& arr, int k, int x)
{
    auto first = lower_bound(arr.begin(), arr.end(), x);
    auto last = upper_bound(arr.begin(), arr.end(), x);
    // If x is not in the array, first == last
    
    // If there is at least k occurrences of x, return k copies
    // of x
    if (last - first >= k)
        return vector<int>(k, x);

    // Compute the diff sums of the candidate ranges and find the minimum
    // diff sum
    first = max(arr.begin(), first - k);
    auto sum_diff = accumulate(first, first + k, 0, [x] (int sum, int v) { return sum + abs(v - x); });
    auto min_start = first;
    auto min_diff = sum_diff;

    for (auto it = first, end = arr.end(); it < last && it + k < end; ++it) {
        sum_diff += abs(*(it + k) - x) - abs(*it - x);
        if (sum_diff < min_diff) {
            min_diff = sum_diff;
            min_start = it + 1;
        } else // found the minima at this point; ignore the rest
            break;
    }
    return vector<int>(min_start, min_start + k);
}
