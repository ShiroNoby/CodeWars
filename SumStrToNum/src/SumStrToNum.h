#pragma
#include <string>

//scnv -> String CONVertation
namespace scnv {

	constexpr size_t G_check = (size_t)'0';

	inline std::string sum(const std::string& str1, const std::string& str2)
	{
		size_t size1 = str1.size();
		size_t size2 = str2.size();
		size_t index = 1;
		size_t tmp = 0;

		if (size2 == 0) return {'0'};
		std::string buff;

		
		//str1 smolless
		for (; index <= size1; ++index)
		{
			size_t a = (size_t)str1[size1 - index] - G_check;
			size_t b = (size_t)str2[size2 - index] - G_check;
			size_t val = a + b + tmp;

			buff.push_back(val % 10 + G_check);
			tmp = val / 10;
		}

		//str2
		for (; index <= size2; ++index)
		{
			size_t a = (size_t)str2[size2 - index] - G_check;
			size_t val = a + tmp;

			buff.push_back(val % 10 + G_check);
			tmp = val / 10;
		}

		if (tmp) buff.push_back((char)(tmp + G_check));

		int bzise = buff.size();
		for (int index = 1; index < bzise; ++index)
		{
			if(buff[bzise - index] == '0') 
			{
				buff.pop_back();
				continue;
			}

			if(buff[bzise - index] != '0') 
			{
				break;
			}
		}


		auto it = buff.rbegin();
		auto end = buff.rend();
		std::string resoult(it, end);

		return resoult;
	}
}; //scnv


std::string sum_strings(const std::string& a, const std::string& b)
{ 
	size_t size1 = a.size();
	size_t size2 = b.size();

	if(size1 < size2) return scnv::sum(a, b);
	return scnv::sum(b, a);
}