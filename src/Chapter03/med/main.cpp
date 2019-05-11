//
//  main.cpp
//  med
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
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
    
    // 读取家庭作业数据并保存数据到向量容器中
    double x;
    vector<double> homework;
    while (cin >> x) {
        homework.push_back(x);
    }
    
    typedef vector<double>::size_type vec_size;
    vec_size size = homework.size();
    
    // 检测向量容器是否为空
    if (size == 0) {
        cout << endl << "You must enter your grades. "
                        "Please try again. " << endl;
        return 1;
    }
    
    // 排序
    sort(homework.begin(), homework.end());
    
    // 找出中值
    vec_size midIdx = size / 2;
    double median = (size % 2 == 0) ? (homework[midIdx] + homework[midIdx - 1]) / 2
                                    : homework[midIdx];
    
    streamsize prec = cout.precision(); // 获取 cout 的精度，后面还原精度时会用到
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision((int)prec) << endl;
    
    return 0;
}
