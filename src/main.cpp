#include <iostream>
#include <algorithm>
#include <vector>

template <typename Container>
void Print(const Container& container)
{
	std::cout << "[ ";
	for (size_t i = 0; i < container.size(); ++i)
	{
		std::cout << container[i] << ", ";
	}
	std::cout << "]\n";
}

template <typename Type>
void Print(const Type arr[], const int& SIZE)
{
	std::cout << "[ ";
	for (size_t i = 0; i < SIZE; ++i)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "]\n";
}

template <typename Container>
void BubbleSort(Container& container)
{
	for (size_t i = 0; i < container.size(); ++i)
	{
		bool bIsSwapped = false;
		for (size_t j = 0; j < container.size() - i - 1; ++j)
		{
			if (container[j] > container[j + 1])
			{
				bIsSwapped = true;
				std::swap(container[j], container[j + 1]);
			}
		}
		if (!bIsSwapped) return;
	}
}

template <typename Container>
void InsertionSort(Container& container)
{
	for (size_t i = 1; i < container.size(); ++i)
	{
		auto key = container[i];
		size_t j = i;
		while (j > 0 && container[j - 1] > key)
		{
			container[j] = container[j - 1];
			--j;
		}
		container[j] = key;
	}
}

void ReverseString(std::string& str)
{
	auto begin = str.begin();
	auto end = str.end();
	--end;

	while (begin < end)
		std::iter_swap(begin++, end--);
}

bool MySubstring(const std::string& str, const std::string& substr)
{
	if (substr.length() > str.length()) return false;
	if (substr.empty()) return true;

	for (size_t i = 0; i <= str.length() - substr.length(); ++i)
	{
		bool bIsFound = true;
		for (size_t j = 0; j < substr.length(); ++j)
		{
			if (str[j + i] != substr[j])
			{
				bIsFound = false;
			}
		}
		if (bIsFound) return true;
	}

	return false;
}

template <typename Container>
void Heapify(Container& container, size_t n, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && container[left] > container[largest])
		largest = left;

	if (right < n && container[right] > container[largest])
		largest = right;

	if (largest != i)
	{
		std::swap(container[i], container[largest]);
		Heapify(container, n, largest);
	}
}

template <typename Container>
void HeapSort(Container& container)
{
	size_t n = container.size();

	for (int i = n / 2 - 1; i >= 0; --i)
		Heapify(container, n, i);

	for (int i = n - 1; i > 0; --i)
	{
		std::swap(container[0], container[i]);
		Heapify(container, i, 0);
	}
}

int main()
{
	
	std::vector<int> vec = { 128, 22, 258, 64, 25 };
	Print(vec);;
	HeapSort(vec);
	Print(vec);
	

	/*
	std::string str = "1234567890";
	std::cout << str << std::endl;
	ReverseString(str);
	std::cout << str << std::endl;
	*/

	/*
	std::string str = "Hello";
	std::string substr = "lo";
	std::cout << MySubstring(str, substr) << "\n";
	*/
	
	
	return 0;
}