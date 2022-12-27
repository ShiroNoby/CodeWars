#include <iostream>
#include <string>

#ifdef small
#include "../src/SumStrToNum(smallInt).h"
#else
#include "../src/SumStrToNum.h"
#endif

int main()
{
#ifdef small
	if(scnv::ten_quad(0) == 1 ) std::cout			<< "#1.1true->ten_quad(0)" << std::endl;
	if(scnv::ten_quad(1) == 10 ) std::cout			<< "#1.2true->ten_quad(1)" << std::endl;
	if(scnv::ten_quad(2) == 100 ) std::cout			<< "#1.3true->ten_quad(2)" << std::endl;
	if(scnv::ten_quad(5) == 100000 ) std::cout		<< "#1.4true->ten_quad(5)" << std::endl;
	if(scnv::ten_quad(-1) == 1) std::cout			<< "#1.5true->ten_quad(-1)\n" << std::endl;
	
	if(scnv::stoi("") == 0)	std::cout				<< "#2.1true->stoi(0)" << std::endl;
	if(scnv::stoi("1") == 1) std::cout				<< "#2.2true->stoi(1)" << std::endl;
	if(scnv::stoi("45") == 45) std::cout			<< "#2.3true->stoi(45)" << std::endl;
	if(scnv::stoi("444") == 444) std::cout			<< "#2.4true->stoi(444)" << std::endl;
	if(scnv::stoi("5886") == 5886)	std::cout		<< "#2.5true->stoi(5886)" << std::endl;
	if(scnv::stoi("77284") == 77284)std::cout		<< "#2.6true->stoi(77284)\n" << std::endl;

	if (scnv::itos(0) == "0") std::cout				<< "#3.1true->itos(0)" << std::endl;
	if (scnv::itos(1) == "1") std::cout				<< "#3.2true->itos(1)" << std::endl;
	if (scnv::itos(45) == "45") std::cout			<< "#3.3true->itos(45)" << std::endl;
	if (scnv::itos(444) == "444") std::cout			<< "#3.4true->itos(444)" << std::endl;
	if (scnv::itos(5886) == "5886") std::cout		<< "#3.5true->itos(5886)" << std::endl;
	if (scnv::itos(77284) == "77284") std::cout		<< "#3.6true->itos(77284)" << std::endl;
#endif

	if (sum_strings("", "") == "0") std::cout 			<< "#4.1true->sum_strings(,)" << std::endl;
	if (sum_strings("1", "") == "1") std::cout 			<< "#4.2true->sum_strings(1,)" << std::endl;
	if (sum_strings("", "1") == "1") std::cout 			<< "#4.3true->sum_strings(,1)" << std::endl;
	if (sum_strings("10", "20") == "30") std::cout 		<< "#4.4true->sum_strings(10,20)" << std::endl;
	if (sum_strings("125", "428") == "553") std::cout 	<< "#4.5true->sum_strings(125,428)" << std::endl;
	if (sum_strings("22222222222", "33333333333333") == "33355555555555")
		std::cout 										<< "#4.6true->sum_strings(22222222222,33333333333333)"
														<< std::endl;
														
															//a=b
	if (sum_strings("794217948742146794854651249184214917945279481576297942179487421467948"
					"546512491842149179452794815762979421794874214679485465124918421491794"
					"52794815762979421794874214679485465124918421491794527948157629", 
					"957649157416457464541476127445197143217446517442169576491574164574645"
					"414761274451971432174465174421695764915741645746454147612744519714321"
					"74465174421695764915741645746454147612744519714321744651744216") == 
					"175186710615860425939612737662941206116272599901846751867106158604259"
					"396127376629412061162725999018467518671061586042593961273766294120611"
					"627259990184675186710615860425939612737662941206116272599901845")
		std::cout << "#4.7true->sum_strings(00022200022220000,3333333300300)"
		<< std::endl;

	//a<b
	if (sum_strings("94815764874214679485465124918421491794527948157629", 
					"957649157416457464541476127445197143217446517442169576491574164574645"
					"414761274451971432174465174421695764915741645746454147612744519714321"
					"74465174421695764915741645746454147612744519714321744651744216") == 
					"957649157416457464541476127445197143217446517442169576491574164574645"
					"414761274451971432174465174421695764915741645746454147612744519714321"
					"74465174421790580680615860425939612737662941206116272599901845")
		std::cout << "#4.8true->sum_strings()"
		<< std::endl;

	//a>b
	if (sum_strings("9576491574164574645414761274451971432174465174421695764915741645746454"
					"1476127445197143217446517442169576491574164574645414761274451971432174"
					"465174421790580680615860425939612737662941206116272599901845", 
					"74465174421695764915741645746454147612744519714321744651744216") == 
					"9576491574164574645414761274451971432174465174421695764915741645746454"
					"1476127445197143217446517442169576491574164574645414761274451971432248"
					"930348843486345596357506172393760350407460920438017251646061") std::cout << "#4.8true->sum_strings(,)" << std::endl;

	//a>b
	if (sum_strings("9576491574164574645414761274451971432174465174421695764915741645746454147612744519714321744651744216957649157416457464541476127445197143224893034884348634559635750617239376035040746092043801725164606195764915741645746454147612744519714321744651744216957649157416457464541476127445197143217446517442169576491574164574645414761274451971432248930348843486345596357506172393760350407460920438017251646061" , "9576491574164574645414761274451971432174465174421695764915741645746454147612744519714321744651744216957649157416457464541476127445197143224893034884348634559635750617239376035040746092043801725164606195764915741645746454147612744519714321744651744216957649157416457464541476127445197143217446517442169576491574164574645414761274451971432248930348843486345596357506172393760350407460920438017251646061") == "19152983148329149290829522548903942864348930348843391529831483291492908295225489039428643489303488433915298314832914929082952254890394286449786069768697269119271501234478752070081492184087603450329212391529831483291492908295225489039428643489303488433915298314832914929082952254890394286434893034884339152983148329149290829522548903942864497860697686972691192715012344787520700814921840876034503292122" ) std::cout << "#4.9true->sum_strings(,)" << std::endl;

}