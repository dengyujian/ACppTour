//
//  main.cpp
//  Chapter06
//
//  Created by ShannonChen on 2019/5/12.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "split.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, const char * argv[]) {
    
    cout << "Please enter strings which contains spaces:" << endl;
    
    string s;
    // 读取并分割每一行的输入
    while (getline(cin, s)) {
        vector<string> v = split(s);
        
        // 输出 v 中的每一个单词
        for (vector<string>::size_type i = 0; i < v.size(); ++i) {
            cout << v[i] << endl;
        }
    }
    
    return 0;
}
