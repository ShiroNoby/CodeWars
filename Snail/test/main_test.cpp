#include <vector>
#include <iostream>
#include "../src/SnainSort.h"

int main()
{
	std::vector<int> nulltest = {};
	if(snail({ {} }) == nulltest) std::cout << "#1true -> nulltest" << std::endl;
	
	std::vector<int> onetest = {1};
	if (snail({ {1} }) == onetest) std::cout << "#2true - > onetest" << std::endl;

	std::vector<int> test3 = { 1,2,3,6,9,8,7,4,5 };
	matt test33 = {{1,2,3},{4,5,6},{7,8,9}};
	if (snail(test33) == test3) std::cout << "#3true" << std::endl;

	std::vector<int> test4 = { 1,2,3,4 };
	matt test44 = { {1,2}, {4,3} };
	if (snail(test44) == test4) std::cout << "#4true" << std::endl;

	std::vector<int> test5 = {};
	matt test55 = { {1,2} };
	if (snail(test55) == test5) std::cout << "#5true" << std::endl;

	std::vector<int> test6 = { 1,2,3,4, 5,6,7,8,9,10,11,12,13,14,15,16 };
	matt test66 = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
	if (snail(test66) == test6) std::cout << "#6true" << std::endl;


	std::vector<int> test11;
	for(int index = 0; index < 121; ++index) test11.push_back(1 + index);
	matt test111 = { 
	{1 ,2 ,3 ,4  ,5  ,6  ,7  ,8  ,9 ,10,11}, 
	{40,41,42,43 ,44 ,45 ,46 ,47 ,48,49,12},
	{39,72,73,74 ,75 ,76 ,77 ,78 ,79,50,13},
	{38,71,96,97 ,98 ,99 ,100,101,80,51,14},
	{37,70,95,112,113,114,115,102,81,52,15},
	{36,69,94,111,120,121,116,103,82,53,16},
	{35,68,93,110,119,118,117,104,83,54,17},
	{34,67,92,109,108,107,106,105,84,55,18},
	{33,66,91,90 ,89 ,88 ,87 ,86 ,85,56,19},
	{32,65,64,63 ,62 ,61 ,60 ,59 ,58,57,20},
	{31,30,29,28 ,27 ,26 ,25 ,24 ,23,22,21}
	};
	if (snail(test111) == test11) std::cout << "#11true" << std::endl;

	return 0;
}