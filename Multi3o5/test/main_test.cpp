#include <iostream>
#include "../src/m3o5.h"

int main()
{
    //10
    int x = 23;

    //30
    int y = 195;

    //155 
    int z = 5478;

    //-10
    int m = 0;

    //10000
    int n = 23331668;

    if(solution(10) == x) 	std::cout << "#1true" << std::endl;
	else{std::cout << solution(10) << std::endl;}

    if(solution(30) == y) 	std::cout << "#2true" << std::endl;
	else{std::cout << solution(30) << std::endl;}

    if(solution(155) == z) 	std::cout << "#3true" << std::endl;
	else{std::cout << solution(155) << std::endl;}

    if(solution(-10) == m) 	std::cout << "#4true" << std::endl;
	else{std::cout << solution(-10) << std::endl;}

    if(solution(10000) == n) 	std::cout << "#5true" << std::endl;
	else{std::cout << solution(10000) << std::endl;}

return 0;
}