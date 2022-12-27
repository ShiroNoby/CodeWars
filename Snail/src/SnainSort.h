#include <vector>

using matt = std::vector<std::vector<int>>;

int arrCheck(const matt& arr, int& size)
{
	for (int index = 0; index < size; ++index)
	{
		if (size != arr[index].size()) return -1;
	}
	return 0;
}

std::vector<int> snail(const matt& arr)
{
	int arrSize = arr.size();
	int &n		= arrSize;
	if (!arrSize) 					return {};

	if (arrCheck(arr, arrSize)) 	return {};
	if (arrSize == 1) 				return {arr[0][0]};

	std::vector<int> resoult((arrSize * arrSize));

	int pos = 0;
	int Row = 0;
	int col = 0;

	int right = n - 1;
	int down = n;
	int left = n;
	int up = n - 1;

	//0  1 2  3 
	//-> v <- ^
	//first 2 itter + (n-2 - 1(last itter)*2) itter 
	int MattSizeItter = 2 + (n - 2 - 1) * 2;

	//first itter
	for (;Row < n; ++pos, ++Row) resoult[pos] = arr[col][Row];

	bool tLeft = 0;
	bool tUp = 0;
	int tmp = 1;
	for (int itter = 0; itter < MattSizeItter; ++itter)
	{
		if (tmp == 0)
		{
			for (Row += 1; Row < right; ++pos, ++Row) resoult[pos] = arr[col][Row];
			--right;
			++tmp;
			continue;
		}

		if (tmp == 1)
		{
			for (col += 1; col < down; ++col, ++pos) resoult[pos] = arr[col][Row - 1];
			--down;
			++tmp;
			continue;
		}

		if (tmp == 2)
		{
			--Row;
			if(tLeft)--left;

			for (int index = 1; index < left; ++index, ++pos, --Row) resoult[pos] = arr[col - 1][Row - 1];
			--left; 
			tLeft = true;
			++tmp;
			continue;
		}

		if (tmp == 3)
		{
			--col;			
			if(tUp)--up;
			for (int index = 1; index < up; ++index, ++pos, --col) resoult[pos] = arr[col - 1][Row];
			--up;
			tUp = true;
			tmp = 0;
			continue;
		}
	}
	
	int resSize = resoult.size();
	//last itter
	//need tmp col Row pos
	//need add last 2 values
	if (n % 2)
	{
		--col;
		for (; pos < resSize; ++pos, ++Row)
		{
			resoult[pos] = arr[col - 1][Row];
		}
	}

	if (n / 2)
	{
		++col;
		for (; pos < resSize; ++pos, --Row)
		{
			resoult[pos] = arr[col][Row - 1];
		}
	}

	return resoult;
}