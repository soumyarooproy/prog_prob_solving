vector<vector<string>> group_anagrams_sorting(vector<string>& strs)
{
    // Use the sorted sequence of characters in a string as the string's signature
    
    unordered_map<string, vector<string>> anagrams;
    for (auto& str : strs) {
        string str_copy(str);
        sort(str_copy.begin(), str_copy.end());
        anagrams[str_copy].emplace_back(str);
    }

    // Return the map contents as a vector
    vector<vector<string>> result;
    result.reserve(anagrams.size());
    for (auto& entry : anagrams) {
        result.emplace_back(move(entry.second));
    }

    return result;
}

// Hash function for char->freq map, which is of type unordered_map<char, int>
struct hash_char_freq
{
    size_t operator()(const unordered_map<char, int>& freq) const {
        return accumulate(freq.begin(), freq.end(), static_cast<size_t>(0),
                          [] (const size_t acc, const pair<char, int>& x) {
                              return acc ^ hash<char>()(x.first) ^ (hash<int>()(x.second) << 1); });
    }
};

// Function to compute and return the char->freq map for a string
unordered_map<char, int> char_freq(const string& s)
{
    unordered_map<char, int> freq;
    for (auto c : s) {
        ++freq[c];
    }
    return freq;
}

vector<vector<string>> group_anagrams_hash_table(vector<string>& strs)
{
    // All anagrams of a word have the same char->freq map
    // Construct a map from char->freq map to set (array) of words
    unordered_map<unordered_map<char, int>, vector<string>, hash_char_freq> anagrams;
    for (auto& str : strs) {
        anagrams[char_freq(str)].emplace_back(str);
    }

    // Return the map contents as a vector
    vector<vector<string>> result;
    result.reserve(anagrams.size());
    for (auto& entry : anagrams) {
        result.emplace_back(move(entry.second));
    }

    return result;
}
