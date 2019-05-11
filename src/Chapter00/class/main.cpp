//
//  main.cpp
//  class
//
//  Created by ShannonChen on 2019/5/11.
//  Copyright © 2019年 ShannonChen. All rights reserved.
//

#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[]) {
    
    std::cout << "Please enter total: ";
    
    Sales_item total;
    
    if (std::cin >> total) {
        std::cout << "Please enter trans: ";
        Sales_item trans;
        while (std::cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    
    
    return 0;
}

