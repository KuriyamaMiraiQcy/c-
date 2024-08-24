//
// Created by 62339 on 2023/11/22.
//
#include <iostream>
#include <string>
#include "dirent.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
std::vector<std::string> get_files(std::string& cate_dir) {
    std::vector<std::string> files;

    _finddatai64_t file;
    long long lf;

    if ((lf = _findfirsti64(cate_dir.c_str(), &file)) == -1) {
        std::cout << cate_dir << " not found!" << std::endl;
    } else {
        while (_findnexti64(lf, &file) == 0) {
            if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0) {
                continue;
            }
            if (!(file.attrib & _A_SUBDIR)) {
                files.emplace_back(file.name);
            }
        }
    }
    _findclose(lf);
    std::sort(files.begin(), files.end());
    return files;
}

std::string remove_prefix(std::string& s) {
    std::unordered_set<std::string> set = {"hhd800.com@", "[ThZu.Cc]", "ddr91@", "[Mosaic Removed Uncensored]", "[Mosaic Removed Uncensored ]",
                                           "[44x.me]", "[Thz.la]", "[99u.me]", "avmans.com-"};
    for (auto& pre:set) {
        if (s.starts_with(pre)) {
            return s.replace(0, pre.size(), "");
        }
    }
    return s;
}

//int main() {
//    std::string dir,a;
//    std::cout << "input dir path:" << std::endl;
//    std::cin >> dir;
//    std::cout << dir << std::endl;
//    a = dir + "\\*";
//
//    std::vector<std::string> files = get_files(a);
//    for (auto& f:files) {
//        std::string path = dir + "\\" + f;
//        std::string new_path = dir + "\\" + remove_prefix(f);
//        if (path != new_path) {
//            std::cout << new_path << std::endl;
//
//
//                if (rename(path.c_str(), new_path.c_str()) == -1) {
//                    std::cout << "rename fail" << std::endl;
//                }
//        }
//    }
//    return 0;
//}