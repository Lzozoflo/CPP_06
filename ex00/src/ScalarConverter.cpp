
#include "ScalarConverter.hpp"

#include <limits>

/*---------------constructor------Canonical-------destructor----------------*/
ScalarConverter::ScalarConverter( void ){}
ScalarConverter::ScalarConverter( const ScalarConverter &other ){(void)other;}
ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ){(void)other; return (*this);}
ScalarConverter::~ScalarConverter( void ){}
/*---------------constructor------Canonical-------destructor----------------*/

static bool	isnaninf(std::string &toConvert)
{
	return (toConvert == "nan" ||
			toConvert == "+inf" ||
			toConvert == "+inff" ||
			toConvert == "-inf" ||
			toConvert == "-inff");
}

static bool	isFormat(std::string &toConvert)
{
	char c = toConvert[0];
	size_t i = 0;
	if (toConvert.empty())
		return (false);
	if ( c == '-' || c == '+')
		i = 1;
	if (i == toConvert.size())
		return (false);
	for (; i < toConvert.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(toConvert[i])))
			return false;
	}
	return (true);
}

static void	putChar(char c)		{std::cout << GREEN << "char: '" << c << "'" << RESET << std::endl;}
static void	putInt(int i)		{std::cout << GREEN << "int: " << i << RESET << std::endl;}
static void	putFloat(float f)	{std::cout << GREEN << "float: " << f << "f" << RESET << std::endl;}
static void	putDouble(double d)	{std::cout << GREEN << "double: " << d << RESET << std::endl;}

static void	putnaninf(std::string &toConvert)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	double	d = std::atof(toConvert.c_str());
	float	f = static_cast<float>(d);
	std::cout << RED << "float: " << f << "f" << RESET << std::endl;
	std::cout << RED << "double: " << d << RESET << std::endl;
}

void	ScalarConverter::convert(std::string &toConvert)
{
	if (isnaninf(toConvert)){
		putnaninf(toConvert);
		return ;
	}
	if (!isFormat(toConvert))
	{
		std::cout << RED << "Bad format." << RESET << std::endl;
		return ;
	}
	double		d;

	std::stringstream nb(toConvert.c_str());

	nb >> d;
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	// char
	if (!isprint(d))
		std::cout << RED << "char: Non displayable" << RESET << std::endl;
	else
		putChar(c);

	// int
	if ( d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() )
		std::cout << RED << "int: impossible" << RESET << std::endl;
	else
		putInt(i);


	// precision 0.0?..
	std::cout << std::fixed << std::setprecision(1);

	// float
	putFloat(f);


	// double
	putDouble(d);

}
