#include <iostream>

using namespace std;

int main()
{
	cout << "Enter Number To Check Palindrome: " << endl;
	int number;
	cin >> number;

	int temp = number;
	int reverseOfNumber = 0;
	
	while( number != 0 )
	{
		reverseOfNumber = reverseOfNumber * 10 + ( number % 10 );
		number = number/10;
	}

	if( reverseOfNumber == temp )
	{
		cout << "Palindrome Number" << endl;
	}
	else
	{
		cout << "Not Palindrome Number" << endl;
	}
	return 0;
}
