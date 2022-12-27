#include <iostream>
#include "..\src\coder.h"


int chek = 1;
void entest(const std::string &str1, const std::string& str2, int rail) {

	if (encode_rail_fence_cipher(str1, rail) == str2) std::cout << chek << " true" << std::endl;
	++chek;
}

void detest(const std::string& str1, const std::string& str2, int rail) {

	if (decode_rail_fence_cipher(str1, rail) == str2) std::cout << chek << " true" << std::endl;
	++chek;
}

int main()
{
	entest("WEAREDISCOVEREDFLEEATONCE", "WECRLTEERDSOEEFEAOCAIVDEN", 3);
	entest("Hello, World!", "Hoo!el,Wrdl l", 3);
	entest("Hello, World!", "H !e,Wdloollr", 4);
	entest("", "", 3);

	detest("H !e,Wdloollr", "Hello, World!", 4);
	detest("WECRLTEERDSOEEFEAOCAIVDEN", "WEAREDISCOVEREDFLEEATONCE", 3);
	detest("WIREEEDSEEEACAECVDLTNROFO", "WEAREDISCOVEREDFLEEATONCE", 4);
	detest("", "", 3);
}