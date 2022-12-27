#include <vector>
#include <iostream>
#include "..\src\MoveZeroEnd.h"

int main()
{
	// {0,0,0,0} ++> {0,0,0,0}
	// {1,1,1,1} ++> {1,1,1,1}
	// {1,0,1,1} ++> {1,1,1,0}
	// {0,1,1,0} ++> {1,1,0,0}
	
	std::vector<int> test11 = {0,0,0,0};
	std::vector<int> test12 = {0,0,0,0};
	
	std::vector<int> test21 = {1,1,1,1};
	std::vector<int> test22 = {1,1,1,1};
	
	std::vector<int> test31 = {1,0,1,1};
	std::vector<int> test32 = {1,1,1,0};
	
	std::vector<int> test41 = {0,1,1,0};
	std::vector<int> test42 = {1,1,0,0};
	
	std::vector<int> test51 = {};
	std::vector<int> test52 = {};
	
	if(move_zeroes(test11) == test12) std::cout << "#1true ";
		
	if(move_zeroes(test21) == test22) std::cout << "#2true ";
		
	if(move_zeroes(test31) == test32) std::cout << "#3true ";
		
	if(move_zeroes(test41) == test42) std::cout << "#4true ";
	
	if(move_zeroes(test51) == test52) std::cout << "#5true ";
	
	return 0;
}