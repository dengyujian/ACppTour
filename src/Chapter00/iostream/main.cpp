//
//  main.cpp
//  iostream
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>

int main(int argc, char const *argv[]) {
    std::cout << "Enter two numbers:" << std::endl;
    /*
     上面一行等价于下面这两行
     std::cout << "Enter two numbers:";
     std::cout << std::endl;
     */
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
    
    
    int sum = 0, value = 0;
    while (std::cin >> value) { // 不停接收输入的数字，直到按下 ctrl+D 才停止循环
        sum += value;
    }
    std::cout << "Sum is " << sum << std::endl;
    
    return 0;
}

