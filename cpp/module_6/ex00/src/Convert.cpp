#include "../header/Convert.hpp"

Convert::Convert()
{
}

Convert::Convert(std::string type)
{
	if (type.empty)	
}

Convert::Convert(Convert const &src)
{
	*this = src;
}

Convert::~Convert()
{
}

Convert	&Convert::operator=(Convert const &src)
{
	(void)src;
	return *this;
}
