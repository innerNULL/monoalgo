

int32_t get_climbing_stair_ways(
        int32_t n, std::unordered_map<int32_t, int32_t>& cache) {
    if (n == 1) { return 1; }
    if (n == 2) { return 2; }
    if (cache.find(n) != cache.end()) { return cache[n]; }
    int32_t result = get_climbing_stair_ways(n - 1, cache) 
            + get_climbing_stair_ways(n - 2, cache);
    cache[n] = result;
    return result;
}


class Solution {
public:
    int climbStairs(int n) {
        std::unordered_map<int32_t, int32_t> cache;
        return get_climbing_stair_ways(n, cache);
    }
};