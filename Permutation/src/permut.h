#include <string>
#include <vector>

using VecStr = std::vector<std::string>;
VecStr permutations(std::string str)
{
	VecStr array;

	std::sort(str.begin(), str.end());

	do{
		array.push_back(str);
	}while(std::next_permutation(str.begin(), str.end()));

	return array;
}