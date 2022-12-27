#include <string>
#include <vector>

using vec = std::vector<std::string>;

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