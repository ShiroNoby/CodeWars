#include <iostream>
#include <vector>
#include "..\src\MaxSubSum.h"

int main()
{
	std::vector<int> v1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	if( maxSequence(v1) == 6) std::cout << "#1true" << std::endl;
	std::cout << maxSequence(v1) << std::endl;
	
	std::vector<int> v2 = { -2, -1, -3, -4, -1, -2, -1, -5, -4 };
	if (maxSequence(v2) == 0) std::cout << "#2true" << std::endl;
	std::cout << maxSequence(v1) << std::endl;
	
	return 0;
}