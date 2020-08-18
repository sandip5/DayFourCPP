#include <iostream>

using namespace std;

void linearSearch( int elements[], int size )
{
	cout << "Enter Element Which You Want To Find: " << endl;
	int item;
	cin >> item;

	int temp = 0;
	for( int i = 0; i < size; i++ )
	{
		if( elements[i] == item )
		{
			cout << "Item Found, Position: " << i << endl;
			temp = temp + 1;
		}
	}
	if( temp == 0 )
	{
		cout << "Item Not Found" << endl;
	}
}

void binarySearch( int elements[], int size )
{
        cout << "Enter Element Which You Want To Find: " << endl;
        int item;
        cin >> item;
        int first = 0;
        int last = size - 1;
        int middle = ( first + last ) / 2;

        while ( first <= last )
        {
                if( elements[middle] < item )
                {
                        first = middle + 1;
                }
                else if( elements[middle] == item )
                {
                        cout<< item <<" found in the array at the location "<< middle+1 << endl;
                        break;
                }
                else
                {
                        last = middle - 1;
                }
                middle = ( first + last ) / 2;
        }
        if( first > last )
        {
           cout<< item <<" not found in the array";
        }
}

int main()
{
	cout << "Search Element By Choosing Given Option:\n1. Linear Search\n2. Binary Search" << endl;
	int select;
	cin >> select;
	int elements[10] = {432, 233, 1234, 987, 4333, 2123, 4322, 973536, 75337, 6266};
	int sortedElements[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int size = sizeof( elements ) / sizeof( elements[0] );
	
	switch( select )
	{
		case 1:
			linearSearch( elements, size );
			break;
		case 2:
			binarySearch( sortedElements, size );
			break;
		default:
			cout << "Invalid Selection" << endl;
	}
}
