//
//  main.cpp
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "extract_fails.h"

using std::vector;
using std::list;

int main(int argc, const char * argv[]) {
    
    vector<Student_info> students;
    list<Student_info> student_list;
    for (int i = 0; i < 5; i++) {
        bool is_even = (i % 2 == 0);
        
        Student_info record;
        record.name = is_even ? "aaa" : "bbb";
        record.midterm = is_even ? 98 : 46;
        record.final = is_even ? 96 : 55;
        vector<double> hw_even = {97.0, 89.0};
        vector<double> hw_odd =  {56.0, 47.0};
        record.homework = is_even ? hw_even : hw_odd;
        
        students.push_back(record);
        student_list.push_back(record);
    }
    
    sort(students.begin(), students.end(), compare);
    vector<Student_info> fails = extract_fails_3(students);
    
    student_list.sort(compare);
    list<Student_info> fail_list = extract_fails_4(student_list);
    
    return 0;
}
