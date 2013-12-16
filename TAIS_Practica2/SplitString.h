/*
 * SplitString.h
 *
 *  Created on: 17/10/2012
 *      Author: alberto
 */

#ifndef SPLITSTRING_H_
#define SPLITSTRING_H_

#include <string>
#include <memory>
typedef std::string string;

std::shared_ptr<string> split(string str, string delim, int& outSize);
std::shared_ptr<string> split(string str, char delim, int& outSize);


#endif /* SPLITSTRING_H_ */
