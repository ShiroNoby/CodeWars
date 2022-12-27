#include <algorithm>
#include <functional>

//PokerHandDefenit
struct PokerHand {
private:
	
	const char* 	hand;
	int				array[16] = {};

	int 			doub = 0;
	bool 			triple = 0;
	bool			strit = 0;
	bool			flesh = 0;
	bool			fullhouse = 0;
	bool 			four = 0;
	bool			stritflesh = 0;
	bool			fleshroall = 0;

public:
	//наибольшее значение комбинации
	int				comb = 0;
	int				&lastH = array[0];
	int				&high = array[1];
	int				order[5] = {};

	PokerHand(const char* pokerhand) : hand(pokerhand) 
	{
		for (int index = 0, pos = 0; index < 5; ++index, pos += 3)
		{			
			char	tmp = hand[pos];
			int		val = ctoi(tmp);

			if(val > 0) ++array[val];
		}

		calc_total(); 
	}

private:
	void 			calc_total()
	{
		calc_order();

		check_pair();
		check_triple();
		check_strit();
		check_flesh();
		check_full_house();
		calc_four();
		check_strit_flesh();
		check_flesh_roal(); 

		std::sort(order, order + 5, std::greater<int>());
	}
	
	void 			calc_order()
	{
		comb = 1;
		for (int index = 0; index < 5; ++index) order[index] = ctoi(hand[index * 3]);
	}
		
	bool 			check_pair()
	{
		for(int index = 2; index < 15; ++index) 
		{
			if(array[index] == 2) 
			{
				++doub;
				max_vel(index, 3);
				to_order(index);
			}
		}

		comb += doub;
		return (doub) ? true : false;		
	}

	bool 			check_triple()
	{
		for (int index = 2; index < 15; ++index)
		{
			if (array[index] == 3)
			{
				triple = true;
				comb = 4;
				max_vel(index, comb);
				to_order(index);

				return true;
			}
		}
		
		return false;
	}

	bool 			check_strit()
	{
		if (doub || triple || four) return false;

		int arr[5] = {};
		for (int index = 0; index < 5; ++index) arr[index] = ctoi(hand[index * 3]);
		std::sort(arr, arr + 5);


		//low ace
		int check[5] = { 2,3,4,5,14 };
		int low_ace[5] = { 1,2,3,4,5 };

		for(int index = 0; index < 5; ++index)
		{
			if(arr[index] != check[index]) break;

			if(index == 4) 
			{
				for(int in = 0; in < 5; ++in)
				{
					arr[in] = low_ace[in];
				}
			}
		}

		int last = arr[0];
		for (int index = 1; index < 5; ++index)
		{
			if (arr[index] - last != 1)
			{
				return false;
			}

			last = arr[index];
		}

		comb = 5;
		strit = true;
		max_vel(arr[4], comb);
		return true;
	}

	bool 			check_flesh()
	{
		if (doub || triple || four) return false;

		char arr[5];
		for (int index = 0; index < 5; ++index) arr[index] = hand[(index * 3) + 1];

		for (int index = 1; index < 5; ++index)
		{
			if (arr[index] != arr[index - 1]) return false;
		}

		comb = 6;
		flesh = true;

		int ar[5] = {};
		for (int index = 0; index < 5; ++index) ar[index] = ctoi(hand[index * 3]);
		std::sort(ar, ar + 5);
		max_vel(ar[4], comb);
		
		return true;
	}

	bool 			check_full_house()
	{
		if ( doub && triple ) 
		{
			comb = 7;
			fullhouse = true;
			return true;
		}

		return false;
	}

	bool 			calc_four()
	{
		for (int index = 2; index < 15; ++index)
		{
			if (array[index] == 4)
			{
				four = true;
				comb = 8;

				max_vel(index, comb);
				to_order(index);
				return true;
			}
		}

		return false;
	}

	bool			check_strit_flesh()
	{
		if(strit && flesh) 
		{
			comb = 9;
			stritflesh = true;
			return true;
		}

		return false;
	}

	bool			check_flesh_roal()
	{
		if(stritflesh && array[1] == 14)
		{
			comb = 10;
			fleshroall = true;
			return true;
		}

		return false;
	}
	
	int 			ctoi(char input)
	{
		if(input > '1' && input <= '9')
		{
			return (int)input - (int)'0';
		}

		switch(input)
		{
			case 'T': return 10;
			case 'J': return 11;
			case 'Q': return 12;
			case 'K': return 13;
			case 'A': return 14;
		}
		
		return -1;
	}

	void			max_vel(int index, int prio)
	{
		if (!array[1]) 
		{
			array[1] = index;		
			
			//save prio
			array[15] = prio;
			return;
		}


		if (array[1])
		{
			if( prio > array[15] ) 
			{
				array[0] = array[1];
				array[1] = index;

				//save prio
				array[15] = prio;
				return;
			}

			if( prio <= array[15] )
			{
				if (array[1] < index)
				{
					array[0] = array[1];
					array[1] = index;

					//save prio
					array[15] = prio;
					return;
				}

				if (array[1] > index)
				{
					array[0] = index;

					//save prio
					array[15] = prio;
					return;
				}
			}	
		}
	}

	void			to_order(int index)
	{
		for(int in = 0; in < 5; ++in) 
		{
			if(order[in] == index) order[in] = 0;
		}
	}
};

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) 
{
	if(player.comb > opponent.comb) return Result::Win;

	if(player.comb < opponent.comb) return Result::Loss;

	if(player.comb == opponent.comb) 
	{
		if(player.high > opponent.high) return Result::Win;
		if(player.high < opponent.high) return Result::Loss;

		if(player.lastH > opponent.lastH) return Result::Win;
		if(player.lastH < opponent.lastH) return Result::Loss;
	}

	for(int index = 0; index < 5; ++index)
	{
		if(player.order[index] > opponent.order[index]) return Result::Win;;
		if(player.order[index] < opponent.order[index]) return Result::Loss;;
	}
	
	return Result::Tie;
}