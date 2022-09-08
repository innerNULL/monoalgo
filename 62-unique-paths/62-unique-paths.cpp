

int32_t get_unique_path_num(
        int32_t m, int32_t n, 
        std::unordered_map<std::string, int32_t>& cache) {
    if (m <= 0 || n <= 0) { return 0; }
    if (m == 1 || n == 1) { return 1; }
    
    std::string key = "";
    
    if (m <= n) {
        key = std::to_string(m) + "#" + std::to_string(n);
    } else {
        key = std::to_string(n) + "#" + std::to_string(m); 
    }
    if (cache.find(key) != cache.end()) { return cache[key]; }
    
    int32_t result = get_unique_path_num(m - 1, n, cache) 
            + get_unique_path_num(m, n - 1, cache);
    cache[key] = result;
    return result;
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        std::unordered_map<std::string, int32_t> cache;  
        return get_unique_path_num(m, n, cache); 
    }
};