//
//  main.cpp
//  03
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>

#include <vector>
#include <string>


using std::vector;
using std::string;

vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    
    while (i < s.size()) {
        while (i < s.size() && !isspace(s[i])) {
            ++i;
            string_size j = i;
            
            while (j < s.size() && !isspace(s[i])) {
                ++j;
            }
            
            if (i < j) {
                ret.push_back(s.substr(i, j - i));
                i = j;
            }
        }
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
