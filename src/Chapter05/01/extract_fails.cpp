//
//  extract_fails.cpp
//  01
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "extract_fails.h"
#include <vector>
#include "grade.h"

using std::vector;

/// 把学生成绩分成及格和不及格的（方案一）
vector<Student_info> extract_fails_1(vector<Student_info>& students) {
    vector<Student_info> pass, fail;
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        if (is_failed(students[i])) {
            fail.push_back(students[i]);
        } else {
            pass.push_back(students[i]);
        }
    }
    
    students = pass;
    return fail;
}


/// 把学生成绩分成及格和不及格的（方案二）
vector<Student_info> extract_fails_2(vector<Student_info>& students) {
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;
    
    while (i != students.size()) {
        if (is_failed(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i); // 每次删除都可能会影响到容器中的其他元素的位置
        } else {
            ++i;
        }
    }
    return fail;
}
