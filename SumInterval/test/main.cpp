#include <iostream>
#include <vector>
#include <utility>
#include "..\src\SumInter.h"

int count = 1;
void test(const std::vector<std::pair<int, int>> &testVec , int resoult)
{
	vec test = testVec;
	bool check = sum_intervals(test) == resoult;
	if (check) std::cout <<'#' << count <<"true\n";
	++count;

	if(!check)
	{
		std::cout << "{ ";
		for(int size = testVec.size(), index = 0; index < size; ++index)
		{
			std::cout << "{";
			std::cout  << testVec[index].first;
			std::cout << ", ";
			std::cout << testVec[index].second;
			std::cout << "} ";
		}
		std::cout << "}\n";
	}
}

int main()
{
	
	test( {{-10,-5},{-7,4},{2,10}}, 20 );
	test( {{-1000000000, 1000000000}}, 2000000000);
	test({ {0, 20}, {-100000000, 10}, {30, 40} }, 100000030);

}