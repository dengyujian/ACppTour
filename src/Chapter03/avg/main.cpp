//
//  main.cpp
//  Chapter03
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision;

int main(int argc, char const *argv[]) {
    
    // 请求输入并读入学生的姓名
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    // 输入其中和期末成绩
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    cout << "Enter all your homework grades, "
    "followed by end-of-file: ";
    
    // 家庭作业个数以及成绩总和
    int count = 0;
    double sum = 0;
    
    double x;
    while (cin >> x) {
        ++count;
        sum += x;
    }
    
    streamsize prec = cout.precision(); // 获取 cout 的精度，后面还原精度时会用到
    cout << "Your final grade is " << setprecision(3)
    << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
    << setprecision((int)prec) << endl;
    
    return 0;
}
