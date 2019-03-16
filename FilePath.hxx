#include <string>

namespace the5 {
namespace util {	
namespace file {	
    
    static std::string getPathMistakes(const std::string &filepath)
	{
		std::string warning("");
		if (filepath.find(':/') == std::string::npos && filepath.find(':\\') == std::string::npos) warning += "\n FILE:\tThere does not seem to be a drive letter present, is this the FULL path?";
		if (filepath.size() < 20) warning += "\n FILE:\tThe Path seems quite short, did you specify the FULL path?";
		return warning;
	}
}
}
}