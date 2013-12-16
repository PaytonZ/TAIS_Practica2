/*
* SplitString.cpp
*
*  Created on: 17/10/2012
*      Author: alberto
*/

#include "SplitString.h"
#include <memory>

int charCount(string str, string delim)
{
	int size = 0, temp = 0, pos = 0;
	while ( (temp = str.find(delim, pos) ) > -1)
	{
		pos = 1 + temp + delim.length(); size++;
	}
	return size + 1;
}

std::shared_ptr<string> split(string str, string delim, int& outSize)
{ /* TODO: free this memory when finished!!! */
	outSize = charCount(str, delim);
	if (outSize == 0)
		return NULL;
	std::shared_ptr<string> out( new string[outSize], []( string *p ) { delete[] p; } );
	for (int index = 0, start = 0, find = 0; index < outSize; index++)
	{
		find = str.find(delim, start);
		if (find < 0 || find < start)
		{
			auto p = out.get();
			p[index] = str.substr(start);
			break;
		}
		else
		{
			auto p = out.get();
			p[index] = str.substr(start, find - start);
		}
		start = find + delim.length();
	}
	return out;
} /* delete [] varName */

std::shared_ptr<string> split(string str, char delim, int& outSize)
{
	return std::shared_ptr<string>(split(str, string(1, delim), outSize));
}




