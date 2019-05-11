//
//  grade.cpp
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "grade.h"
#include <vector>
#include <stdexcept>
#include "median.h"
#include "Student_info.h"


using std::vector;
using std::domain_error;


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

/// 计算最终成绩
double grade(const Student_info& stu) {
    return grade(stu.midterm, stu.final, stu.homework);
}

/// 是否不及格
bool is_failed(const Student_info& stu) {
    return grade(stu) < 60.0;
}
