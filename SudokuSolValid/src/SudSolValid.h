#include <vector>

using matt = std::vector<unsigned int>;

inline bool RowValid(const matt& row)
{
	unsigned int board[10] = { 0 };

	for (int index = 0; index < 9; ++index)
	{
		unsigned int val = row[index];
		// if(val > 9){}
		
		++board[val];
		if (board[val] > 1) return false;
	}

	return (board[0] == 0) ? true : false;
}


bool validSolution(unsigned int board[9][9])
{
	auto script = [&board](int Row, bool tr = true)
	{
		matt BRow(9);

		for(int col = 0; col < 9; ++col)
		{
			if (tr) 				BRow[col] = board[Row][col];
			if (!tr) 				BRow[col] = board[col][Row];
		}
		if (!RowValid(BRow)) 	return false;

		return true;
	};

	for (int Row = 0; Row < 9; ++Row)
	{
		//check strValid
		if (!script(Row)) 			return false;
		if (!script(Row, false)) 	return false;
	}

	//check 3x3
	for (int Row = 0; Row < 3; ++Row)
	{
		for (int col = 0; col < 3; ++col)
		{
			matt BRow(9);
			for (int index = 0; index < 9; ++index)
			{
				int x = (index / 3) + ( 3 * Row);
				int y = (index % 3) + ( 3 * col);

				BRow[index] = board[x][y];
			}

			if (!RowValid(BRow)) 	return false;
		}
	}

	return true;
}