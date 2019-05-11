//
//  extract_fails.cpp
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "extract_fails.h"
#include <vector>
#include <list>
#include "grade.h"

using std::vector;
using std::list;

/// 把学生成绩分成及格和不及格的（方案三）
/// 返回结果为不及格的，并将不及格的从原容器中剔除掉
vector<Student_info> extract_fails_3(vector<Student_info>& students) {
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (is_failed(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter); // 每次删除都可能会影响到容器中的其他元素的位置
        } else {
            ++iter;
        }
    }
    return fail;
}

/// 把学生成绩分成及格和不及格的（方案四）
/// 返回结果为不及格的，并将不及格的从原容器中剔除掉
list<Student_info> extract_fails_4(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (is_failed(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter); // 每次删除都不会影响到容器中的其他元素的位置
        } else {
            ++iter;
        }
    }
    return fail;
}
