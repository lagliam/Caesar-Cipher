/* A Simple Caesar Cipher 
* Can Encrypt and Decrypt Messages
*/

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

class Transformation 
{
	private : int shift;
	public : Transformation(int s) : shift(s) {}

	char op() (char c)
	{
		if (isspace(c))
			return ' ';
		else
		{
			static std::string letters("abcdefghijklmnopqrstuvwxyz");
			std::string::size_type found = letters.find(tolower(c));
			int shiftedPosition = (static_cast<int>(found)+ shift) % 26;
			if (shiftedPosition < 0) //this is in case of decryption possibilites
				shiftedPosition = 26 + shiftedPosition;
			char shifted = letters[shiftedPosition];
			return shifted;
		}
	}
};

int main()
{
	std::string input;
	std::cout << "Enter text to be encrypted below:\n";
	getline(std::cin, input);
	std::cout << "Enter shift amount below: \n";
	int sessionShift = 0;
	std::cin >>sessionShift;
	std::cout << "Pre-encrypted text:\n" << input << std::endl;
	std::transform (input.begin(), input.end(), input.begin(), Transformation(sessionShift));
	std::cout << "Encrypted Text:\n";
	std::cout << input << std::endl;
	sessionShift *= -1; //decrypted a second time
	std::transform (input.begin(), input.end(), input.begin(), Transformation(sessionShift));
	std::cout<< "Decrypted a second time:\n";
	std::cout << input <<std::endl;
	return 0;
}