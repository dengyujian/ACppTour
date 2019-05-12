//
//  pic.cpp
//  04
//
//  Created by ShannonChen on 2019/5/12.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "pic.h"

#include <algorithm>

using std::vector;
using std::string;
using std::max;


/// 找出 vector 容器中最长的字符串的长度
string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i < v.size(); ++i) {
        maxlen = max(maxlen, v[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);
    
    // 顶部和底部的边框字符串
    string border(maxlen + 4, '*');
    
    // 顶部边框
    ret.push_back(border);
    
    // 内部的每一行都用左右两个星号和空格框起来
    for (vector<string>::size_type i = 0; i < v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }
    
    // 底部的边框
    ret.push_back(border);
    
    return ret;
}

/// 纵向连接两个 vector
vector<string> vact(const vector<string>& top, const vector<string>& bottom) {
    
    // 先复制顶部的图案
    vector<string> ret = top;
    
    // 然后在复制底部的图案
    //    for (vector<string>::const_iterator iter = bottom.begin();
    //         iter < bottom.end();
    //         ++iter) {
    //        ret.push_back(*iter);
    //    }
    //    // 上面这个 for 循环的操作等效于下面的这一行代码
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    
    return ret;
}

/// 横向连接两个 vector
vector<string> hact(const vector<string>& left, const vector<string>& right) {
    
    vector<string> ret;
    
    // 提前计算好左侧图案的宽度
    string::size_type left_width = width(left);
    
    // 逐行复制
    vector<string>::size_type i = 0, j = 0;
    while (i < left.size() || j < right.size()) {
        string s;
        
        // 复制左边的图案
        if (i < left.size()) {
            s = left[i];
            i++;
        }
        
        // 在左右两幅图案之间加一个空格
        s += string(left_width + 1 - s.size(), ' ');
        
        // 复制右边图案
        if (j < right.size()) {
            s += right[j];
            j++;
        }
        
        ret.push_back(s);
    }
    
    return ret;
}
