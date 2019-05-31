//
//  Student_info.h
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#ifndef Student_info_h
#define Student_info_h

#include <iostream>
#include <string>
#include <vector>

/**
 学生信息
 */
struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

/// 用于学生信息排序的比较
bool compare(const Student_info& stu_a, const Student_info& stu_b);

/// 读取输入的学生信息，并保存到 stu 中
std::istream& read(std::istream& input, Student_info& stu);

/// 读取家庭作业成绩
std::istream& read_homework(std::istream& input, std::vector<double>& homework);

#endif /* Student_info_h */
