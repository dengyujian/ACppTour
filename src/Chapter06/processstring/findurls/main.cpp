//
//  main.cpp
//  findurls
//
//  Created by ShannonChen on 2019/5/25.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// 判断一个字符是不是 URL 中的字符
bool not_url_char(char c) {
    // 除了数字和字母外，其他有可能出现在一个 URL 中的字符
    static const string url_ch = "~;/?:@=&$-_.+!*`(),'";
    
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

// 找出 URL 的结尾
string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

// 找出 URL 的开头
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";
    
    typedef string::const_iterator iter;
    
    // i 标记了查找到的分隔符的位置
    iter i = b;
    
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        
        if (i != b && i + sep.size() != e) {
            iter beg = i;
            
            while (beg != b && isalpha(beg[-1])) {
                --beg;
            }
            
            if (beg != i && i + sep.size() != e && !not_url_char(i[sep.size()])) {
                return beg;
            }
        }
        
        if (i != e) {
            i += sep.size();
        }
    }
    
    return e;
}

vector<string> find_urls(const string& str) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = str.begin(), e = str.end();
    
    while (b != e) {
        b = url_beg(b, e);
        
        if (b != e) {
            iter after = url_end(b, e);
            
            ret.push_back(string(b, after));
            
            b = after;
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    string str = "http://www.ctrip.com|http://www.trip.com|http://baidu.com|http://www.qunar.com";
    vector<string> urls = find_urls(str);

    for (int i = 0; i < urls.size(); i++) {
        cout << urls[i] << endl;
    }
    
    return 0;
}
