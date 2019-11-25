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
	int ARR_SIZE; //Maximum size of the array - set in the constructor. Defaults to 1000 if not set by a user. 

public:
	//pass in the size of the array, otherwise defaults to size 1000
	MapTemplate(int size = 1000) 
	{
		ARR_SIZE = size;
		pairs = new keyPair[size];

		//Fills the array with 0, so when scannng through to find an "empty" slot, first 0 in the key is fine to overwrite
		//need to work out how to sort this for string.. 
		for (int i = 0; i < size; i++)
		{
			pairs[i] = { 0,0 };
		}
	}

	//cycles through the array until it finds the first 'empty' slot (i.e, key being 0) and puts it there.
	bool push(T key, U data)
	{
		//though it will reject a key if it's integer 0.
		if (key == 0)
		{
			std::cout << "Rejected" << std::endl;
			return false;
		}
		else
		{
			for (int i = 0; i < ARR_SIZE; i++)
			{
				if (pairs[i].key == key)
				{
					std::cout << "key already exists.." << std::endl;
					return false;
				}
				else if (pairs[i].key != 0)
				{
					//nope
				}
				else
				{
					pairs[i].key = key;
					pairs[i].data = data;
					break;
				}
			}
			return true;
		}

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
	}
};