
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

static void	putnaninf(std::string &toConvert)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	double	d = std::atof(toConvert.c_str());
	float	f = static_cast<float>(d);
	std::cout << RED << "float: " << f << "f" << RESET << std::endl;
	std::cout << RED << "double: " << d << RESET << std::endl;
}

static int	whatFormat(std::string &toConvert)
{
	if (toConvert[toConvert.size() - 1 ] == 'f')
	{
		// std::cout << "f find\n";
		std::string copy = toConvert;
		copy.resize(copy.size() - 1);

		std::stringstream ss(copy.c_str());
		float f;

		ss >> f;
		if (!ss.fail() && ss.eof())
		{
			std::cout << "ok float !\n";
			return 2;
		}
		return 0;
		// std::cout << "not an float !\n";
	}

	// std::cout << toConvert << std::endl;

	if (toConvert.find(".") != std::string::npos) {

		std::stringstream ss(toConvert.c_str());

		int i;
		ss >> i;
		if (!ss.fail() && ss.eof())
		{
			std::cout << "ok int!\n";
			return 1;
		}
	}
	std::stringstream ss(toConvert.c_str());

	double d;
	ss >> d;
	if (!ss.fail() && ss.eof())
	{
		std::cout << "ok double!\n";
		return 3;
	}
	return 0;
}

static void	putChar(char c)		{std::cout << GREEN << "char: '" << c << "'" << RESET << std::endl;}
static void	putInt(int i)		{std::cout << GREEN << "int: " << i << RESET << std::endl;}
static void	putDouble(double d)	{std::cout << GREEN << "double: " << d << RESET << std::endl;}

#include <cmath> // for std::isinf

static void	putFloat(float f)
{
	if (std::isinf(f)){
		std::cout << RED << "float: " << f << "f" << RESET << std::endl;
	} else {
		std::cout << GREEN << "float: " << f << "f" << RESET << std::endl;
	}
}

void	ScalarConverter::convert(std::string &toConvert)
{
	double	d;
	int i;
	float f;
	char c;


	if (isnaninf(toConvert)){
		putnaninf(toConvert);
		return ;
	}


	if (isalpha(toConvert[0]) && toConvert.size() == 1)
	{
		std::stringstream cchar(toConvert.c_str());

		cchar >> c;
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<char>(c);
	}
	else
	{
		int format = whatFormat(toConvert);
		if (format == 1){
			// conver to int
			std::stringstream nb(toConvert.c_str());

			nb >> i;
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		} else if (format == 2) {
			// conver to float
			std::stringstream nb(toConvert.c_str());

			nb >> f;
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
		} else if (format == 3) {

			std::stringstream nb(toConvert.c_str());

			nb >> d;
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);

		} else {
			std::cout << RED << "Bad format." << RESET << std::endl;
			return ;
		}
	}






	if (!isprint(c))
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
