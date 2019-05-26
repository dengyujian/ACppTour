//
//  split.cpp
//  Chapter06
//
//  Created by ShannonChen on 2019/5/25.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "split.hpp"
#include <_ctype.h>
#include <algorithm>

using std::vector;
using std::string;

bool space(char c) {
    return isspace(c);
}

bool not_space(char c) {
    return !isspace(c);
}


// 将包含空白字符的字符串拆成多个单独的字符串
vector<string> split(const string& str) {
    typedef string::const_iterator iter;
    vector<string> ret;
    
    iter i = str.begin();
    while (i != str.end()) {
        // 忽略前面的空白：从第 i 个开始，找到第一个非空的字符所在的位置
        // 找到后，更新 i 的值
        i = find_if(i, str.end(), not_space);
        
        // 找出单词的结尾：从第 i 个开始，找到第一个空白字符所在的位置
        iter j = find_if(i, str.end(), space);
        
        // 复制在 [i, j) 中的字符
        if (i != str.end()) {
            ret.push_back(string(i, j));
        }
        
        i = j;
    }
    
    return ret;
}
