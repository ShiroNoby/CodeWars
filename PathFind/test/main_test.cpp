#include <iostream>
#include "..\src\Wave.h"


int main()
{
	if(path_finder(".W.\n.W.\n...") == 4) std::cout << "1" << std::endl;
	if (path_finder(".W.\n.W.\nW..") == -1) std::cout << "2" << std::endl;
	if (path_finder("......\n......\n......\n......\n......\n......") == 10) std::cout << "3" << std::endl;
	if (path_finder(".") == 0) std::cout << "4" << std::endl;
	if (path_finder("..") == 1) std::cout << "5" << std::endl;
	if (path_finder("..\n..") == 2) std::cout << "6" << std::endl;
	if (path_finder(".....\nWWWW.\n.....\n.WWWW.\n.....") == 16) std::cout << "7" << std::endl;
}