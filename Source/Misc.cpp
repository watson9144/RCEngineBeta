#include <fstream>
#include <sstream>
#include "Misc.h"

std::string CFile::ReadFile(const std::string& file_path)
{
	std::ifstream f(file_path);

	std::stringstream buffer;
	buffer << f.rdbuf();

	std::string file_content = buffer.str();
	return file_content;
}