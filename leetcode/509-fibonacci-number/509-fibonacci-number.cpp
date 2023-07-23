

int32_t get_fib(int32_t n, std::unordered_map<int32_t, int32_t>& cache) {
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    if (cache.find(n) != cache.end()) { return cache[n]; }
    int32_t out = get_fib(n - 1, cache) + get_fib(n - 2, cache);
    cache[n] = out;
    return out;
}


class Solution {
public:
    int fib(int n) {    
        std::unordered_map<int32_t, int32_t> cache;
        return get_fib(n, cache);
    }
    
    
    int fib_v0(int n) {
        if (n == 0) { return 0; }
        if (n == 1) { return 1; }
        return fib(n - 1) + fib(n - 2);
    }
};