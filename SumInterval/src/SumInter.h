#include <vector>
#include <utility>

using vec = std::vector<std::pair<int, int>>;

// Xn -> Yn
// Y1 < Xn
// Y1 > Xn > Yn && X1 > Xn
// X1 < Xn && Y1 > Xn > Yn -> Xn = 0, Yn = 0
// Y1 > Xn < Yn -> Y1 = Y1 - (Y1 - Xn)
// [Xn , Yn] 	-> [Xn - Xn, Yn - Xn ]   -> [0, Yn - Xn]
int sum_intervals(vec& intervals)
{
	int vecSize = intervals.size();
	if (vecSize == 0) return 0;

	for(int index = 0; index < vecSize; ++index)
	{
		int& X1 = intervals[index].first;

		for (int in = index + 1; in < vecSize; ++in)
		{
			int& Xn = intervals[in].first;

			if( X1 >  Xn) intervals[index].swap(intervals[in]);
		}
	}

	int sum = 0;
	for (int index = 0; index < vecSize; ++index)
	{
		int& X1 = intervals[index].first;
		int& Y1 = intervals[index].second;

		if(!X1 && !Y1) continue;

		// Y1 > Xn < Yn -> Y1 = Y1 - (Y1 - Xn)			
		for (int in = index + 1; in < vecSize; ++in)
		{
			int& Xn = intervals[in].first;
			int& Yn = intervals[in].second;

			if(X1 <= Xn && Y1 > Xn)
			{
				if(Y1 <= Yn) 
				{
					//Y1 = Y1 - (Y1 - Xn)	
					Y1 = (Y1)-((Y1)-(Xn));
				}

				if(Y1 > Yn) {
					Yn = 0;
					Xn = 0;
				}
			}			
		}

		// [Xn , Yn] 	-> [Xn - |Xn|, Yn - |Xn| ]   -> [0, Yn - |Xn|]
		int temp = X1;
		X1 = 0;
		Y1 -= temp;

		sum += Y1;
	}

	return sum;
}