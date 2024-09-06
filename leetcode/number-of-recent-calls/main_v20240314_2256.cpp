#include <queue>


class RecentCounter {
public:
    std::queue<int32_t> requests = {};

    RecentCounter() {}
    
    int ping(int t) {
        while (
            static_cast<int32_t>(this->requests.size()) != 0 
            && this->requests.front() < t - 3000
        ) {
            this->requests.pop();
        }
        this->requests.push(t);
        return static_cast<int32_t>(this->requests.size());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
