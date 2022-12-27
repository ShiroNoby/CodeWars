#include <vector>

int pos1 = 0;
int pos2 = 0;
int max  = 0;

void sum(const std::vector<int>& arr, int tpos1, int tpos2)
{
	int summ = 0;
	for(int p1 = tpos1; p1 < tpos2; ++p1)
	{
		//в будущем добавить динамики
		summ += arr[p1];
	}
	
	if(summ > max)
	{
		max = summ;
		pos1 = tpos1;
		pos2 = tpos2;
	}
}

int maxSequence(const std::vector<int>& arr)
{
	int index = 0;
	int size  = arr.size();
	pos1 	  = 0;
	pos2 	  = 0;
	max  	  = 0;
	
	//для динамики развернуть в обратном направлении
	//от 1 до size
	for( ; index < size; ++index)
	{
		for(int in = 0; in <= index ; ++in)
		{
			int tpos = (size - index) + in;
			sum(arr, in, tpos);
		}
	}
	
	return max;
}