#pragma once


template<class T, class U> class MapTemplate
{
	struct keyPair
	{
		U key;
		T data;
	};

private:
	keyPair* pairs;
	int ARR_SIZE;
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
		std::cout << "Made It Out" << std::endl;
	}

	//cycles through the array until it finds the first 'empty' slot (i.e, key being 0) and puts it there.
	bool push(U key, T data)
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
				if (pairs[i].key != 0)
				{
					//just continues
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
	void erase(U key)
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
		std::cout << "key not found" << std::endl;
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
	U output(U key)
	{
		for (int i = 0; i < ARR_SIZE; i++)
		{
			if (pairs[i].key == key)
			{
				return pairs[i].data;
			}
			else if (pairs[i].key == 0)
			{
				return 0;
			}
			else
			{
				//nowt
			}
		}

	}

	~MapTemplate()
	{
		delete pairs;
	}
};