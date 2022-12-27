#include <string>
#include <vector>
#include <deque> 


using deq = std::deque<char>;
using vecdeq = std::vector<deq>;

vecdeq make_rail_str(const std::string &str, int Rail)
{
	int size = str.size();
	vecdeq strQue(Rail);
	
	//array => str intervals 
	//0-x x-n n-y y-z ...
	auto script = [&strQue, &str](int Rail, const std::vector<int> &array)
	{
		for(int c_str = 0; c_str < Rail; ++c_str)
		{
			int first = c_str * 2;
			int second = first + 1;
			for(int index = array[first]; index < array[second]; ++index )
			{
				strQue[c_str].push_back(str[index]);
			}
		}
	};
	
	int sumBbetween = (Rail - 1) + (Rail - 1);
	int consistCrest = (Rail) + ( Rail - 1);
	
	int val = size / sumBbetween;
	int sumCrest = consistCrest + (sumBbetween * (val - 1));
	
	//down crest
	int twoCrest = 0;
	if(sumCrest + Rail - 1 <= size)	twoCrest = 1;
	
	int val1 = val + 1;
	int val2 = val + twoCrest;
	
	std::vector<int> array(Rail * 2);	
	array[0] = 0;
	array[1] = val1;
	
	array[array.size() - 2] = size - val2;
	array[array.size() - 1] = size;
	
	int miniSize = (size - val1 - val2) / (Rail - 2);
	int idStr = size - sumCrest;
	
	for(int c_str = 1; c_str < Rail - 1; ++c_str)
	{
		int first = c_str * 2;
		int second = first + 1;
		
		int firstVal = array[first - 1];
		int secondVal = firstVal + miniSize;
		
		if(idStr < Rail && c_str == idStr % 3) secondVal += 1;
		if(idStr > Rail && c_str == Rail - idStr % 3) secondVal += 1;
		
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

		resoult.push_back(strQue[pos].front());
		if(strQue[pos].size()) strQue[pos].pop_front();
	}

	return resoult;
}