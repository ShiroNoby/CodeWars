#include <vector>
#include <cstddef>

std::vector<int> move_zeroes(const std::vector<int>& input) 
{
  size_t count = 0;
  size_t size = input.size();
  std::vector<int> temp(size);
  
  for(size_t index = 0; index < size; ++index)
  {
	int intTemp = input[index];
	if(intTemp) 
	{
		temp[count] = intTemp;
		++count;
	}
  }
  
  return temp;
}