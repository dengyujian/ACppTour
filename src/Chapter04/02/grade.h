//
//  grade.h
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#ifndef grade_h
#define grade_h

#include <vector>
#include "Student_info.h"

/// 计算最终成绩
double grade(double midterm, double final, double homework);

/// 计算最终成绩
/// 注意：这里的第三个参数使用了引用作为参数，并且使用了 const 关键字
double grade(double midterm, double final, const std::vector<double>& homework);

/// 计算最终成绩
double grade(const Student_info& stu);

#endif /* grade_h */
