#include <iostream>

using namespace std;

void printElements( int elements[] )
{
        for( int k = 0; k < 10; k++ )
        {
                cout << elements[k] << " ";
        }
	cout << "\n";
}

void mergeElements( int low, int mid, int high, int elements[] )
{
	int tempElements[10], i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while ( i <= mid && j <= high )
	{
        	if ( elements[i] < elements[j] )
		{
			tempElements[k] = elements[i];
			k++;
			i++;
        	}
        	else
		{
			tempElements[k] = elements[j];
			k++;
			j++;
		}
    	}
    	while ( i <= mid )
	{
        	tempElements[k] = elements[i];
        	k++;
        	i++;
    	}
    	while ( j <= high )
	{
        	tempElements[k] = elements[j];
        	k++;
        	j++;
    	}
    	for ( i = low; i < k; i++ )
	{
        	elements[i] = tempElements[i];
    	}
}

void divideElements( int low, int high, int elements[] )
{
	if( low < high )
	{
		int middle = low + ( high - low ) / 2;
		divideElements( low, middle, elements );
		divideElements( middle + 1, high, elements );
		mergeElements( low, middle, high, elements );
	}
}

void mergeSort( int elements[] )
{
	int numberOfElements = 10;
        int low = 0;
        int high = numberOfElements - 1;
	divideElements( low, high, elements );
	printElements( elements );
}

int partition( int elements[], int low, int high )
{
	int pivot = elements[(low + high) / 2];
	while( low <= high )
	{
		while( elements[low] < pivot )
		{
			low++;
		}
		while( elements[high] > pivot )
		{
			high--;
		}
		if( low <= high )
		{
			int temp = elements[low];
			elements[low] = elements[high];
			elements[high] = temp;
			low++;
			high--;
		}
	}
	return low;
}

void quickSortRecursion( int elements[], int low, int high )
{
	int pivot = partition( elements, low, high );
	if( low < pivot - 1 )
	{
		quickSortRecursion( elements, low, pivot - 1 );
	}
	if( pivot < high )
	{
		quickSortRecursion( elements, pivot, high );
	}
}

void quickSort( int elements[] )
{
        int numberOfElements = 10;
        int low = 0;
        int high = numberOfElements - 1;
        quickSortRecursion(elements, low, high);
        printElements( elements );
}


void bubbleSort( int elements[] )
{
	int numberOfElements = 10;
	int temp = 0;
	for( int i = 0; i < numberOfElements; i++ )
	{
		int flag = 0;
		for( int j = 0; j < numberOfElements - 1 - i ; j++ )
		{
			if( elements[j] > elements[j + 1] )
			{
				temp = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = temp;
				flag = 1;
			}
		}
		if(flag == 0) 
		{
			break;
		}
	}
	printElements(elements);
}

void insertionSort( int elements[] )
{
	int numberOfElements = 10;
	int temp;
	int j;

	for( int i = 1; i < numberOfElements; i++ )
	{
		temp = elements[i];
		j = i - 1;
		while( j >= 0 && elements[j] > temp )
		{
			elements[j + 1] = elements[j];
			j--;
		}
		elements[j + 1] = temp;
	}
	printElements(elements);
}

int main()
{
	cout << "Select Which Sort  Operation You Want To Perform: \n" << "1. Bubble Sort\n2. Insertion Sort \n3. Quick Sort\n4. Merge Sort" << endl;
	int choose;
	cin >> choose;
	int elements[10] = {432, 233, 1234, 987, 4333, 2123, 4322, 973536, 75337, 6266};
	cout << "Unsorted Elements Are: " << endl;
	printElements( elements );
	cout << "Sorted Elements Are: " << endl;

	switch( choose )
	{
		case 1:
			bubbleSort(elements);
			break;
		case 2:
			insertionSort(elements);
			break;
		case 3:
			quickSort(elements);
			break;
		case 4:
			mergeSort(elements);
			break;
		defaut:
			cout << "Invalid Input" << endl;
	}
	return 0;
}
