#ifndef WRAPPER_H
#define WRAPPER_H

template<class T>
class Wrapper
{
public:
	Wrapper() : DataPtr{ nullptr }
	{
	}

	Wrapper(const T& inner)
	{
		DataPtr = inner.clone();
	}

	Wrapper(const Wrapper<T>& original)
	{
		if (original.DataPtr)
			DataPtr = original.DataPtr->clone();
		else
			DataPtr = nullptr;
	}

	~Wrapper()
	{
		delete DataPtr;
	}

	Wrapper& operator=(const Wrapper<T>& original)
	{
		if (this != original)
		{
			if (DataPtr)
				delete DataPtr;
			if (original.DataPtr)
				DataPtr = original.DataPtr->clone();
			else
				DataPtr = nullptr;
		}
	}

	T& operator*()
	{
		return *DataPtr;
	}

	const T& operator*() const
	{
		return *DataPtr;
	}

	T* operator->()
	{
		return DataPtr;
	}

	const T* operator->() const
	{
		return DataPtr;
	}

private:
	T* DataPtr;
};

#endif
