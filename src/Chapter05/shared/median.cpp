//
//  median.cpp
//  02
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include "median.h"
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;

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
