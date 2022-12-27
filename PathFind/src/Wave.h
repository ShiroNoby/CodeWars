#include <string>
#include <vector>

const char NL = '\n';
const char W = 'W';
const char emp = '.';
const int walk = 2100000000;

using field = std::vector<std::vector<int>>;


inline field make_grid(const std::string& str)
{
	int	size = str.size();

	int	index = 1;
	for (int in = 0; in < size; ++in)
		if (str[in] == NL) {
			index = in; break;
		}

	field grid(index);

	//x |-->
	//y v
	int nowposy = 0;

	//parse str in grid
	//imagine this grid is n*n
	for (int index = 0; index < size; ++index)
	{
		char tmp = str[index];
		if (tmp == NL)
		{
			++nowposy;
		}

		if (tmp == W)
		{
			grid[nowposy].push_back(walk);
		}

		if (tmp == emp)
		{
			grid[nowposy].push_back(-2);
		}
	}

	return grid;
}

inline bool runWave(field& grid, int endposy, int endposx, int wave)
{
	bool valid = false;

	//сделать wave внутри
	for (int y = 0; y <= endposy; ++y)
	{
		for (int x = 0; x <= endposx; ++x)
		{
			int& val = grid[y][x];
			if (val == wave)
			{
				valid = true;

				//left
				if (!(x == 0)) {
					int& left = grid[y][x - 1];
					if (left != walk && left < 0) left = wave + 1;
				}

				//right
				if (!(x == endposx)) {
					int& right = grid[y][x + 1];
					if (right != walk && right < 0) right = wave + 1;
				}

				//up
				if (!(y == 0)) {
					int& up = grid[y - 1][x];
					if (up != walk && up < 0) up = wave + 1;
				}

				//down
				if (!(y == endposy)) {
					int& down = grid[y + 1][x];
					if (down != walk && down < 0) down = wave + 1;
				}

				if (x == endposx && y == endposy) return 0;
			}
		}
	}

	return valid;
}



int path_finder(std::string str)
{
	field grid = make_grid(str);

	//end pos
	//grid[n-1][n-1] = -1
	int endposy = grid.size() - 1;
	int endposx = grid[endposy].size() - 1;
	grid[endposy][endposx] = -1;

	//start pos
	//grid[0][0] = 1
	grid[0][0] = 0;

	if (grid.size())
	{
		for(int wave = 0; runWave(grid, endposy, endposx, wave); ++wave){}
		return grid[endposy][endposx];
	}

	return -1;
}