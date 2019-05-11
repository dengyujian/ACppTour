//
//  Student_info.cpp
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "Student_info.h"

using std::cout;
using std::endl;
using std::istream;
using std::vector;

/// 用于学生信息排序的比较
bool compare(const Student_info& stu_a, const Student_info& stu_b) {
    return stu_a.name < stu_b.name;
}

/// 读取家庭作业成绩
istream& read_homework(istream& input, vector<double>& homework) {
    
    if (input) {
        // 清除原先的内容
        homework.clear();
        
        // 读家庭作业成绩
        cout << "Enter all your homework grades, "
                "followed by end-of-file: ";
        
        double x;
        while (input >> x) {
            homework.push_back(x);
        }
        
        // 清除输入流以使输入动作对下一个学生有效
        input.clear();
    }
    
    return input;
}

/// 读取输入的学生信息，并保存到 stu 中
istream& read(istream& input, Student_info& stu) {
    cout << "Please enter your first name: ";
    input >> stu.name;
    cout << "Hello, " << stu.name << "!" << endl;
    
    cout << "Please enter your midterm and final exam grades: ";
    input >> stu.midterm >> stu.final;
    
    read_homework(input, stu.homework);
    
    return input;
}
