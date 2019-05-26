//
//  main.cpp
//  palindrome
//
//  Created by ShannonChen on 2019/5/25.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// 是否是回文
bool is_palindrome(const string& s) {
    // equal 函数比较两个序列以判断它们是否包含有相等的值
    return equal(s.begin(), s.end(), s.rbegin());
}

int main(int argc, const char * argv[]) {
    
    cout << "Please enter a string:" << endl;
    
    string str;
    cin >> str;
    
    if (is_palindrome(str)) {
        cout << str << " is palindrome." << endl;
    } else {
        cout << str << " is not palindrome." << endl;
    }
    
    return 0;
}
