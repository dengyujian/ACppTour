//
//  extract_fails.h
//  01
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#ifndef extract_fails_h
#define extract_fails_h

#include <vector>
#include "Student_info.h"

/// 把学生成绩分成及格和不及格的（方案一）
/// 返回结果为不及格的，并将不及格的从原容器中剔除掉
std::vector<Student_info> extract_fails_1(std::vector<Student_info>& students);

/// 把学生成绩分成及格和不及格的（方案二）
/// 返回结果为不及格的，并将不及格的从原容器中剔除掉
std::vector<Student_info> extract_fails_2(std::vector<Student_info>& students);

#endif /* extract_fails_h */
