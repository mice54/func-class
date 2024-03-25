#pragma once
#include <map>
#include <string>
template<typename T>
class func {
public:
	std::map <std::string, T> func_name_list;
	std::map <int, T> func_id_list;
};