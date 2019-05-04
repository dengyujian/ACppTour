

#include <iostream>
#include <string>


int main(int argc, char const *argv[]) {
	
	// 输入名字
	std::cout << "Please enter your first name: ";

	std::string name;
	std::cin >> name;
	
 
	/* 输出带框的名字 */
	// 构造输出的内容
    const std::string greeting = "Hello, " + name + "!";

    const std::string spaces(greeting.size(), ' '); // 使用构造函数定义变量
    const std::string second = "* " + spaces + " *";

    const std::string first(second.size(), '*');

	std::cout << std::endl;
	std::cout << first <<  std::endl;
	std::cout << second <<  std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	return 0;
}