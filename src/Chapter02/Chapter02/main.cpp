//
//  main.cpp
//  Chapter02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
    
    // 输入的名字
    cout << "Please enter your first name: ";
    
    string name;
    cin >> name;
    
    const string greeting = "Hello, " + name + "!";
    
    // 画边框
    const int pad = 1;  // 空白边框的数目
    const int rows = pad * 2 + 3; // 行数
    const string::size_type cols = greeting.size() + pad * 2 + 2; // 列数
    
    // 换行
    cout << endl;
    
    // 逐行打印
    for (int r = 0; r < rows; ++r) {
        string::size_type c = 0;
        
        // 打印每一行的内容
        while (c < cols) {
            if (r == pad + 1 && c == pad + 1) {
                // 输出问候语
                cout << greeting;
                c += greeting.size();
            } else {
                // 边界
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1) {
                    // 边框
                    cout << "*";
                } else {
                    // 空白区域
                    cout << " ";
                }
                ++c;
            }
        }
        
        // 换行
        cout << endl;
    }
    
    return 0;
}

