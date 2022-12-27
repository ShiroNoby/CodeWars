#include <string>
#include <vector>
#include <deque> 

using vec = std::vector<std::string>;
using deq = std::deque<char>;
using vecdeq = std::vector<deq>;


std::string encode_rail_fence_cipher(const std::string &str, int Rail) 
{
	int size = str.size();
	int direct = 0;
	int pos = 0;
	
	if(!size) return "";
	
	vec strVect(Rail);
		
	for(int index = 0; index < size; ++index, pos += direct)
	{
		if(!pos) direct = 1;
		if(pos == Rail - 1) direct = -1;
		
		strVect[pos].push_back(str[index]);		
	}
		
	
	for(int index = 1, sz = strVect.size(); index < sz; ++index) strVect[0] += strVect[index];
	
	return strVect[0];
}


vecdeq make_rail_str(const std::string& str, int Rail)
{
	int size = str.size();
	vecdeq strQue(Rail);

	//array => str intervals 
	//0-x x-n n-y y-z ...
	auto script = [&strQue, &str](int Rail, const std::vector<int>& array)
	{
		for (int c_str = 0; c_str < Rail; ++c_str)
		{
			int first = c_str * 2;
			int second = first + 1;
			for (int index = array[first]; index < array[second]; ++index)
			{
				strQue[c_str].push_back(str[index]); 
			}
		}
	};

	int sumBbetween = (Rail - 1) + (Rail - 1);
	int sumCrest = (Rail)+(Rail - 1);

	int countUpCrest = 1;
	if(size >= sumCrest)
	{
		int sz = (size - sumCrest) / sumBbetween;
		countUpCrest = 2 + sz;
	}

	int countDownCrest = 0;
	if(size >= Rail) 
	{
		int sz = (size - Rail) / sumBbetween;
		countDownCrest = 1 + sz;
	}

	
	std::vector<int> array(Rail * 2);
	array[0] = 0;
	array[1] = countUpCrest;

	array[array.size() - 2] = size - countDownCrest;
	array[array.size() - 1] = size;

	bool small = size < sumCrest + sumBbetween;
	
	for(;small;)
	{
		//[0 - Rail]
		if (size > 0 && size < Rail)
		{
			sumCrest = 1;
			break;
		}

		//[Rail]
		if (size == Rail)
		{
			sumCrest = 1;
			break;
		}

		//[Rail - sumCrest]
		if (size > Rail && size < sumCrest)
		{
			sumCrest = 1;
			break;
		}

		//[sumCrest]
		if(size == sumCrest ) break;

		//[sumCrest - sumcrest + Rail]
		if(size > sumCrest && size < Rail + sumBbetween) break;

		//[sumCrest + Rail]
		if (size == Rail + sumBbetween)
		{
			--countDownCrest;
			break;
		}

		//[sumCrest + Rail - Sumcrest + sumBetween]
		if (size > Rail + sumBbetween && size < sumCrest + sumBbetween)
		{
			--countDownCrest;
			break;
		}
	}

	int countBetween = (size - sumCrest) / sumBbetween;
	int fullValStr = sumCrest + sumBbetween * countBetween;
	
	if(!small && size - fullValStr >= Rail - 1) --countDownCrest;

	//size replase sumCrest
	int miniSize = (fullValStr - countUpCrest - countDownCrest) / (Rail - 2);
	int idStr = size - fullValStr;

	for (int c_str = 1; c_str < Rail - 1; ++c_str)
	{
		int first = c_str * 2;
		int second = first + 1;

		int firstVal = array[first - 1];
		int secondVal = firstVal + miniSize;

		if (idStr < Rail && (c_str <= idStr)) secondVal += 1;
		if (idStr >= Rail && (c_str < (sumBbetween - idStr))) secondVal += 1;
		if (idStr >= Rail && (c_str >= (sumBbetween - idStr))) secondVal += 2;

		array[first] = firstVal;
		array[second] = secondVal;
	}

	script(Rail, array);

	return strQue;
}


std::string decode_rail_fence_cipher(const std::string &str, int Rail) 
{
	int size = str.size();
	int direct = 0;
	int pos = 0;

	if(!size) return "";
	
	vecdeq strQue = make_rail_str(str, Rail);
	std::string resoult;
	
	for (int index = 0; index < size; ++index, pos += direct)
	{
		if (!pos) direct = 1;
		if (pos == Rail - 1) direct = -1;

		if(strQue[pos].size()) 
		{
			resoult.push_back(strQue[pos].front());
			strQue[pos].pop_front();
		}
	}

	return resoult;
}