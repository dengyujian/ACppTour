//
//  pic.h
//  04
//
//  Created by ShannonChen on 2019/5/12.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#ifndef pic_h
#define pic_h

#include <vector>
#include <string>


/// 找出 vector 容器中最长的字符串的长度
std::string::size_type width(const std::vector<std::string>& v);

std::vector<std::string> frame(const std::vector<std::string>& v);

/// 纵向连接两个 vector
std::vector<std::string> vact(const std::vector<std::string>& top, const std::vector<std::string>& bottom);

/// 横向连接两个 vector
std::vector<std::string> hact(const std::vector<std::string>& left, const std::vector<std::string>& right);

#endif /* pic_h */
