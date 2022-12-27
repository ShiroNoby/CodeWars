#include <iostream>
#include "..\src\TexasPoker.h"


int chek = 1;
void test(const char* p1, const char* p2, Result back){
	PokerHand ph1(p1);
	PokerHand ph2(p2);
	Result resoult = compare(ph1, ph2);
	if( resoult == back ) std::cout << chek << " true" << std::endl;
	++chek;
}

int main()
{
   test ("2H 3H 4H 5H 6H", "KS AS TS QS JS", Result::Loss); // "Highest straight flush wins"
   test ("2H 3H 4H 5H 6H", "AS AD AC AH JD", Result::Win ); // "Straight flush wins of 4 of a kind"
   test ("AS AH 2H AD AC", "JS JD JC JH 3D", Result::Win ); // "Highest 4 of a kind wins"
   test ("2S AH 2H AS AC", "JS JD JC JH AD", Result::Loss); // "4 Of a kind wins of full house"
   test ("2S AH 2H AS AC", "2H 3H 5H 6H 7H", Result::Win ); // "Full house wins of flush"
   test ("AS 3S 4S 8S 2S", "2H 3H 5H 6H 7H", Result::Win ); // "Highest flush wins"
   test ("2H 3H 5H 6H 7H", "2S 3H 4H 5S 6C", Result::Win ); // "Flush wins of straight"
   test ("2S 3H 4H 5S 6C", "3D 4C 5H 6H 2S", Result::Tie ); // "Equal straight is tie"
   test ("2S 3H 4H 5S 6C", "AH AC 5H 6H AS", Result::Win ); // "Straight wins of three of a kind"
   test ("2S 3H 4H 5S AC", "AH AC 5H 6H AS", Result::Win ); // "Low-ace straight wins of three of a kind"
   test ("2S 2H 4H 5S 4C", "AH AC 5H 6H AS", Result::Loss); // "3 Of a kind wins of two pair"
   test ("2S 2H 4H 5S 4C", "AH AC 5H 6H 7S", Result::Win ); // "2 Pair wins of pair"
   test ("6S AD 7H 4S AS", "AH AC 5H 6H 7S", Result::Loss); // "Highest pair wins"
   test ("2S AH 4H 5S KC", "AH AC 5H 6H 7S", Result::Loss); // "Pair wins of nothing"
   test ("2S 3H 6H 7S 9C", "7H 3C TH 6H 9S", Result::Loss); // "Highest card loses"
   test ("4S 5H 6H TS AC", "3S 5H 6H TS AC", Result::Win ); // "Highest card wins"
   test ("2S AH 4H 5S 6C", "AD 4C 5H 6H 2C", Result::Tie ); // "Equal cards is tie"
} 