//
// Created by 62339 on 2023/10/31.
//
#include <string>
class find_index_first_occurrence_string {
public:
    int strStr(std::string s, std::string p) {
        int n = s.size(), m = p.size();
        for(int i = 0; i <= n - m; i++){
            int j = i, k = 0;
            while(k < m and s[j] == p[k]){
                j++;
                k++;
            }
            if(k == m) return i;
        }
        return -1;
    }
};