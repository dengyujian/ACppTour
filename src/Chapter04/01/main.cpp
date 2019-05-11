//
//  main.cpp
//  01
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::domain_error;
using std::istream;
using std::string;
using std::streamsize;
using std::setprecision;


/// 计算中值
double median(vector<double> vec) {
    typedef vector<double>::size_type vec_size;
    vec_size size = vec.size();
    
    // 首先判断容器是否为空
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }
    
    // 排序
    sort(vec.begin(), vec.end());
    
    // 计算中值
    vec_size midIdx = size / 2;
    
    return (size % 2 == 0) ? (vec[midIdx] + vec[midIdx - 1]) / 2 : vec[midIdx];
}

/// 计算最终成绩
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

/// 计算最终成绩
/// 注意：这里的第三个参数使用了引用作为参数，并且使用了 const 关键字
double grade(double midterm, double final, const vector<double>& homework) {
    if (homework.size() == 0) {
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(homework));
}

/// 读取家庭作业成绩
istream& read_homework(istream& input, vector<double>& homework) {
    
    if (input) {
        // 清除原先的内容
        homework.clear();
        
        // 读家庭作业成绩
        double x;
        while (input >> x) {
            homework.push_back(x);
        }
        
        // 清除输入流以使输入动作对下一个学生有效
        input.clear();
    }
    
    return input;
}

int main(int argc, const char * argv[]) {
    
    // 输入名字
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    // 输入期中和期末成绩
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    // 输入家庭作业成绩
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    vector<double> homework; // 这个变量就是一个“左值”
    read_homework(cin, homework);
    
    // 计算总成绩
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize orig_prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision((int)orig_prec);
        
    } catch (domain_error e) {
        cout << endl << "You must enter your grades."
             << "Please try again." << endl;
        return 1;
    }
    
    return 0;
}
