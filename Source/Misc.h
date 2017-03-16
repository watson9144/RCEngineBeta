#pragma once
//一些杂项先放在这
#include <string>

class CFile
{
public:
	static std::string ReadFile(const std::string& file_path);
};