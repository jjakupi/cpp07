#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{

	Array<std::string> emptyArray(0);
	std::cout << "emptyArray size: " << emptyArray.size() << std::endl;
	Array<std::string> nrray(1);
	std::cout << "nray size: " <<nrray.size() << std::endl;
	try
	{
		nrray[1] = "elolo";
		std::cout << nrray[1] << std::endl;
		nrray[2] = "elol444";//index out of bounds
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	//SCOPE
	{
		numbers[1] = 2;
		numbers[2] = 4;
		Array<int> tmp;
		tmp = numbers;
		Array<int> test(tmp);
		std::cout << "Testing the deep copy and the copy constructor and assignment\n";
		std::cout << "Before changing the value: \n";
		std::cout << "tmp[1]: " << tmp[1] << "\n";
		std::cout << "tmp[2]: " << tmp[2] << "\n";
		std::cout << "number1: " << numbers[1]<< "\n" << "number2: " << numbers[2] << "\n";
		std::cout << "checking the size of the array\n";
		std::cout << numbers.size() << "\n";
		std::cout << tmp.size() << "\n";
		std::cout << test.size() << "\n";
		tmp[1] = -10;
		tmp[2] = -20;
		std::cout << "tmp[1] and tmp[2] wont have the same value as numbers[1], numbers[2] if the deep copy works\n";
		std::cout << "tmp[1]: " << tmp[1] << "\n";
		std::cout << "tmp[2]: " << tmp[2] << "\n";
		std::cout << "numbers[1]: " << numbers[1] << "\n";
		std::cout << "numbers[2]: " << numbers[2] << "\n";
	}
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// for (int i = 0; i < MAX_VAL; i++)
	// {
	// 	numbers[i] = rand();
	// }
	delete [] mirror;//
	return 0;
}

// int main()
// {
//     std::cout << "---- normal access ----" << std::endl;

//     Array<int> a(9999999);
// 	Array<int> b(a);
//     a[0] = 10;
//     a[1] = 20;
//     a[2] = 30;

//     std::cout << a[0] << std::endl;
//     std::cout << a[1] << std::endl;
//     std::cout << a[2] << std::endl;
// 	std::cout << b[0] << std::endl;
//     std::cout << b[1] << std::endl;
//     std::cout << b[2] << std::endl;
// }


// int main()
// {
//     const Array<int> ca(3);
//     std::cout << "ca.size() = " << ca.size() << std::endl;
// 	ca[0] = 444;
//     // leximi duhet të lejohet
//     std::cout << "ca[0] = " << ca[0] << std::endl;
// }
