#pragma
#include <string>

//scnv -> String CONVertation
namespace scnv {

	constexpr int G_check = (int)'0';

	//10^x
	inline int ten_quad(int x)
	{
		int sum = 1;
		for (int index = 0; index < x; ++index)
		{
			sum *= 10;
		}
		return sum;
	}

	inline int stoi(const std::string& str)
	{
		int size = str.size();
		int sum = 0;
		int last = size - 1;

		if (size == 0) 	return 0;

		for (int index = 0; index < size; ++index)
		{
			int val = (int)str[last - index] - G_check;
			sum += val * ten_quad(index) ;
		}

		return sum;
	}


	inline std::string itos(const int x)
	{
		if (x == 0) return { '0' };
		std::string buff;

		//last
		int var = x % 10;
		buff.push_back((char)(var + G_check));

		for (int index = 1, ten = 10; x / ten; ++index, ten = ten_quad(index))
		{
			var = (x / ten) % 10;
			buff.push_back((char)(var + G_check));
		}

		auto it = buff.rbegin();
		auto end = buff.rend();
		std::string resoult(it, end);

		return resoult;
	}
}; //scnv


std::string sum_strings(const std::string& a, const std::string& b) 
{
	return scnv::itos( scnv::stoi(a) + scnv::stoi(b) );
}