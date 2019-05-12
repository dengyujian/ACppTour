//
//  split.cpp
//  03
//
//  Created by ShannonChen on 2019/5/12.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "split.h"

using std::vector;
using std::string;

/// 以字符串中空白符为分割点，将其拆成多个子字符串
vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    
    while (i < s.size()) {
        
        // 找出“子字符串”的起始位置
        while (i < s.size() && isspace(s[i])) {
            ++i;
        }
        
        // 找出“子字符串”的结束位置
        string_size j = i;
        while (j < s.size() && !isspace(s[j])) {
            ++j;
        }
        
        // 如果找到了非空的“子字符串”
        if (i < j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    
    return ret;
}
