//
//  main.cpp
//  Chapter04
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::streamsize;
using std::setprecision;
using std::max;
using std::setw;
using std::domain_error;

int main(int argc, const char * argv[]) {
    
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // 读取并保存所有的学生记录，然后找出最长的名字的长度
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    // 按照学生名字字母顺序对学生进行排序
    sort(students.begin(), students.end(), compare);
    
    // 逐个计算学生的成绩，并打印学生信息
    for (vector<Student_info>::size_type i = 0; i < students.size(); ++i) {
        // 输出名字
        cout << setw((int)maxlen+1) << students[i].name;
        
        // 计算并输出名字
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision((int)prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        
        cout << endl;
    }
    
    
    return 0;
}
