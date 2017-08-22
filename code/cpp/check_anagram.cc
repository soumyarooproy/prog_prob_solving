bool is_anagram_with_sorting(string s, string t)
{
    if (s.size() != t.size())
        return false;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    return s == t;
}

bool is_anagram_with_hashtable(string s, string t)
{
    unordered_map<char, int> num_chars;
    
    // Compute the char -> freq table for s
    for (auto c : s)
        ++num_chars[c];
        
    // For every char in t, decrement its freq in the table
    // and remove the entry if the freq goes down to 0; if
    // the char is not found in the table return false
    for (auto c : t) {
        auto entry = num_chars.find(c);
        if (entry == num_chars.end())
            return false;
        if (!--entry->second)
            num_chars.erase(entry);
    }
        
    return num_chars.empty();
}

bool is_anagram_with_integer_signatures(string s, string t)
{
    static vector<short> primes({2, 3, 5, 7, 11, 13, 17, 19,
                                 23, 29, 31, 37, 41, 43, 47,
                                 53, 59, 61, 67, 71, 73, 79,
                                 83, 89, 97, 101});
                                 
    auto product = [&primes] (size_t acc, char c) { return acc * primes[c - 'a']; };
    auto sig_s = accumulate(s.begin(), s.end(), 1, product);
    auto sig_t = accumulate(t.begin(), t.end(), 1, product);
    
    return sig_s == sig_t;
}
