

typedef struct Context {
    int32_t size = 0;
    int32_t diff = 0;
    std::unordered_map<char, int32_t> recorder;
    std::unordered_map<char, int32_t> dict;
    // 0 for same, 1 for diff
    std::unordered_map<char, int32_t> diff_flag; 
} Context;


void context_init(
        Context* ctx, const std::string& target) {
    for (char x : target) { ctx->dict[x] = 0; } 
    for (char x : target) { ctx->dict[x] += 1; }
    for (char x : target) { ctx->recorder[x] = 0; } 
    for (char x : target) { ctx->diff_flag[x] = 1; }  
    ctx->diff = ctx->dict.size();
}


void print_map(std::unordered_map<char, int32_t>& input) {
    for (auto iter = input.begin(); 
            iter != input.end(); ++iter) {
        std::cout << "key=" << iter->first;
        std::cout << ", val=" << iter->second << std::endl;
    }
    printf("end print_map\n");
}


void context_register(Context* ctx, char c) {
    if (ctx->dict.find(c) == ctx->dict.end()) {
        return;
    }
    ctx->recorder[c] += 1;
    if (ctx->recorder[c] == ctx->dict[c]
            && ctx->diff_flag[c] == 1) { 
        ctx->diff_flag[c] = 0; 
        ctx->diff -= 1;
    } else if (ctx->recorder[c] != ctx->dict[c] 
            && ctx->diff_flag[c] == 0) {
        ctx->diff_flag[c] = 1;
        ctx->diff += 1;    
    } 
}


void context_deregister(Context* ctx, char c) {
    if (ctx->dict.find(c) == ctx->dict.end()) {
        return;
    }
    ctx->recorder[c] -= 1;
    if (ctx->recorder[c] != ctx->dict[c]
            && ctx->diff_flag[c] == 0) { 
        ctx->diff_flag[c] = 1;  
        ctx->diff += 1; 
    } else if (ctx->recorder[c] == ctx->dict[c] 
            && ctx->diff_flag[c] == 1) {
        ctx->diff_flag[c] = 0;
        ctx->diff -= 1;
    }
}


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::vector<int32_t> out;
        if (p.size() > s.size()) { return out; }

        int32_t anagram_size = p.size();
        Context* ctx = new Context(); 
        context_init(ctx, p);
        //print_map(ctx->dict); 
        //printf("dbg: diff=%i\n", ctx->diff);

        for (int32_t i = 0; i < anagram_size; ++i) {
            context_register(ctx, s.at(i));
            //printf("dbg: diff=%i\n", ctx->diff);
        }
        //print_map(ctx->recorder); 
        for (int32_t i = anagram_size; i < s.size(); ++i) {
            //printf("dbg: start=%i, end=%i\n", i - anagram_size, i);
            if (ctx->diff == 0) {
                out.emplace_back(i - anagram_size); 
            }
            int32_t deregister_idx = i - anagram_size; 
            char deregister_char = s.at(deregister_idx);
            char register_char = s.at(i);
            std::string sub_str = s.substr(i - anagram_size, anagram_size + 1);
            context_deregister(ctx, s.at(i - anagram_size));
            context_register(ctx, s.at(i));
            //printf("dbg: diff=%i\n", ctx->diff);
        }
        if (ctx->diff == 0) { 
            out.emplace_back(s.size() - anagram_size); 
        }
        return out;
    }
};