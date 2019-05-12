//
//  main.cpp
//  04
//
//  Created by ShannonChen on 2019/5/12.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>

#include "pic.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;


int main(int argc, const char * argv[]) {
    
    
    vector<string> orig_text_vec;
    orig_text_vec.push_back("this is an");
    orig_text_vec.push_back("example");
    orig_text_vec.push_back("to");
    orig_text_vec.push_back("illustrate");
    orig_text_vec.push_back("framing");
    
    
    // 加边框
    cout << "picture with border: " << endl << endl;
    vector<string> new_text_vec = frame(orig_text_vec);
    for (vector<string>::size_type i = 0; i < new_text_vec.size(); ++i) {
        cout << new_text_vec[i] << endl;
    }
    cout << endl;
    
    // 纵向连接两个 vector
    cout << "vertical concatenated pictures: " << endl << endl;
    vector<string> vcat_text_vec = vact(orig_text_vec, new_text_vec);
    for (vector<string>::size_type i = 0; i < vcat_text_vec.size(); ++i) {
        cout << vcat_text_vec[i] << endl;
    }
    cout << endl;
    
    // 横向连接两个 vector
    cout << "horizontal concatenated pictures: " << endl << endl;
    vector<string> hcat_text_vec = hact(orig_text_vec, new_text_vec);
    for (vector<string>::size_type i = 0; i < hcat_text_vec.size(); ++i) {
        cout << hcat_text_vec[i] << endl;
    }
    cout << endl;
    
    return 0;
}
