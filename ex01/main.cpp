#include "iter.hpp"

int main()
{
	//array JO CONST
	int arr[] = {1, 2, 3, 4};

	std::cout << "Before increment:" << std::endl;
	iter(arr, 4, print_value<int>);

	iter(arr, 4, increment<int>);

	std::cout << "After increment:" << std::endl;
	iter(arr, 4, print_value<int>);
	//array CONST
	const int const_arr[] = {10, 20, 30};
	std::cout << "Const array:" << std::endl;
	iter(const_arr, 3, print_value<int>);

	// iter(const_arr, 3, increment<int>); kjo S'DUHE TË KOMPILOJË
		//array JO CONST
	std::string words[] = {"hello", "world", "cpp"};

	std::cout << "Before modification:" << std::endl;
	iter(words, 3, print_string<std::string>);

	iter(words, 3, add_exclamation);

	std::cout << "After modification:" << std::endl;
	iter(words, 3, print_string<std::string>);

	//array CONST
	const std::string const_words[] = {"one", "two", "three"};

	std::cout << "Const string array:" << std::endl;
	iter(const_words, 3, print_string<std::string>); // OK

	//iter(const_words, 3, add_exclamation); //duhet të mos kompiloje
	return 0;
}
