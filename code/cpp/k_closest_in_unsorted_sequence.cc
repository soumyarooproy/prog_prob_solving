vector<int> find_k_closest_unsorted(const vector<int>& arr, int k, int x)
{
    // Copy the first k elements into a vector
    vector<int> k_closest(arr.begin(), arr.begin() + k);

    // Construct a compare function for the heap
    auto comp = [&x] (int i, int j) { return abs(i - x) < abs(j - x); };

    // Rearrange the vector elements to construct a max heap
    make_heap(k_closest.begin(), k_closest.end(), comp);

    // For the rest of the elements in the array, replace the top of the heap
    // with a new element if the (absolute) diff is lower
    auto it = arr.begin() + k;
    for (auto end = arr.end(); it < arr.end(); ++it) {
        if (abs(*it - x) < abs(k_closest[0] - x)) { // 0th item is the top of the heap
            pop_heap(k_closest.begin(), k_closest.end(), comp);
            k_closest.back() = *it;
            push_heap(k_closest.begin(), k_closest.end(), comp);
        }
    }

    // Sort the contents of the heap before returning them
    sort(k_closest.begin(), k_closest.end());
    return k_closest;
}
