#include <iostream>

int main(){
	std::cout << "Hello CMake!" << std::endl;
#ifdef WINDOWS_BUILD
	std::cout << "Windows" << std::endl;
#elif defined LINUX_BUILD
	std::cout << "Linux" << std::endl;
#else
	std::cout << "Unknown system" << std::endl;
	return __LINE__;
#endif	
	return 0;
}
