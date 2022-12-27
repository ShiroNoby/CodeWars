#include <vector>

//     n1
//  z1 z2 z3
// |  |  |  | 
//vector<vector<ui>>.size 	= n
//vector<ui>.size 			= z
using mat3to3 = std::vector<std::vector<unsigned int>>;

//        z1 z2 z3 z4 z5 z6 z7 z8 z9
// x1 -> |  |  |  |  |  |  |  |  |  |
//vector<mat3to3>.size 		= x
//mat3to3.size 				= n
//mat3to3[].size 			= z
using mat9to9 = std::vector<mat3to3>;

//cannot be more than one instance of the number 1-9 in one line
inline bool RowValid(mat3to3& row)
{
	unsigned int board[10] = {0};
	
	for(int n = 0; n < 3; ++n)
	{
		for(int index = 0; index < 3; ++index)
		{
			++board[ (row[n][index]) ];
		}
	}
	
	if(board[0] > 0) return false;
	
	for(int index = 1; index < 10; ++index)
	{
		if(board[index] > 1) return false;
	}
	
	return true;
}

bool validSolution(unsigned int board[9][9])
{
	mat9to9 B9x3x3(9);
	for(int Row = 0; Row < 9; ++Row)
	{
		B9x3x3[Row].resize(3);
		int col	= 0;
		
		for(; col < 3; ++col)
		{
			B9x3x3[Row][0][col] = board[Row][col];
		}
		
		for(int bcol = 0; col < 6; ++col, ++bcol)
		{
			B9x3x3[Row][1][bcol] = board[Row][col];
		}
		
		for(int bcol = 0; col < 9; ++col, ++bcol)
		{
			B9x3x3[Row][2][bcol] = board[Row][col];
		}
		
		if(RowValid(B9x3x3[Row])) return false;
	}
	
	int x = 0;
	int z = 0;
	for(int Row = 0; Row < 3; ++Row)
	{
		for(int col = 0; col < 3; ++col)
		{
			mat3to3 b3x3(3);
			for(int index = 0; index < 3; ++index)
			{
				//x = Row * 3
				//z = col * 3
				b3x3[col][]
			}
		}
	}
	
	
   
   return false;
}