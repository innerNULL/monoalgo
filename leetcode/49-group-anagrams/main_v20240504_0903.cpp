class Solution {
public:
    vector<vector<string>> 
    groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> out = {};

        std::unordered_map<std::string, std::vector<std::string>>
        recorder = {};

        /* Old-School
        for (const std::string& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            if (recorder.find(key) == recorder.end()) {
                recorder[key] = {};
            } 
            recorder[key].emplace_back(std::move(str));
        }
        */
        std::for_each(
            strs.begin(),
            strs.end(),
            [&recorder](const std::string& str) {
                std::string key = str;
                std::sort(key.begin(), key.end());
                if (recorder.find(key) == recorder.end()) {
                    recorder[key] = {};
                }
                recorder[key].emplace_back(std::move(str));
            }
        );
        std::for_each(
            recorder.begin(), 
            recorder.end(),
            [&out](
                const std::pair<std::string, std::vector<std::string>>& x
            ) {
                out.emplace_back(std::move(x.second));
            }
        );
        return out;
    }
};
