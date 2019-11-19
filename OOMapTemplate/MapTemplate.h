#pragma once


template<class T, class U> class MapTemplate
{
	struct keyPair
	{
		U key;
		T data;
	};

private:
	keyPair pairs[1000];
	


public:
	MapTemplate()
	{
		for (int i = 0; i < 1000; ++i)
		{
			pairs[i] = keyPair{ 0 , 0 };

		}
	}

	void push(T data, U key)
	{
		
	}

	void pop()
	{

	}

	U output(U key)
	{

		return pairs[index].data;
	}

};