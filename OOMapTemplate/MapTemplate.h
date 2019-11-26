#pragma once


template<class T, class U> class MapTemplate
{
	struct keyPair
	{
		T key;
		U data;
	};

private:
	keyPair* pairs; // pointer to an array which is made in the constructor. 
	keyPair* pairs2;

	int ARR_SIZE; //Maximum size of the array - set in the constructor. Defaults to 1000 if not set by a user. 

public:
	//takes first key and data pair, constructs new map.
	MapTemplate(T key, U data) 
	{
		pairs = new keyPair[1];
		pairs[0].key = key;
		pairs[0].data = data;
		ARR_SIZE = 1;
	}

	//cycles through the array until it finds the first 'empty' slot (i.e, key being 0) and puts it there.
	bool push(T key, U data)
	{
		ARR_SIZE++;
		pairs2 = new keyPair[ARR_SIZE];

		//copies the old array over, deletes old array, then switches the new array back to the old pointer.
		for (int i = 0; i < ARR_SIZE - 1; i++)
		{
			pairs2[i].key = pairs[i].key;
			pairs2[i].data = pairs[i].data;
		}
		
		//deleting the old array after copying, then reassigning the old pointer to the new array before clearing the "new" one, ready for a reinsert
		delete pairs;
		pairs = pairs2;
		delete pairs2;

		//finally inserts the new data
		pairs[ARR_SIZE - 1].key = key;
		pairs[ARR_SIZE - 1].data = data;
		return true;
	}

	//deletes a specific member by replacing the key and data with 0.
	void erase(T key)
	{
		for (int i = 0; i < ARR_SIZE; i++)
		{
			if (pairs[i].key == key)
			{
				pairs[i].key = 0;
				pairs[i].data = 0;
				std::cout << "Data Erased" << std::endl;
				return;
			}
		}
		std::cout << "Erase attempt: Key not found!" << std::endl;
		return;
	}

	//returns true if array is empty.
	bool empty()
	{
		int counter = 0;
		for (int i = 0; i < ARR_SIZE; i++)
		{
			if (pairs[i].key != 0)
			{
				counter++;
			}
		}
		if (counter == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//checks to see how many items are in the array
	int size()
	{
		int counter = 0;
		for (int i = 0; i < ARR_SIZE; i++)
		{
			if (pairs[i].key != 0)
			{
				counter++;
			}
		}
		return counter;
	}

	//outputs the data attached to a key.
	U output(T key)
	{
		for (int i = 0; i < ARR_SIZE; i++)
		{
			if (pairs[i].key == key)
			{
				return pairs[i].data;
			}
			if (pairs[i].key == 0)
			{
				std::cout << "Output attempt: Key not found!" << std::endl;
				break;
			}
			else
			{
				//nowt
			}
		}
		return 0;

	}

	~MapTemplate()
	{
		//clears up the dynamically allocated array. 
		delete pairs;
		delete pairs2;
	}
};