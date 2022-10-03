struct Range {
	int start, length;
	struct Iterator {
		int value;
		int& operator*() { return value; }
		bool operator!=(const Iterator& r) { return value != r.value; };
		Iterator& operator++() { value++; return *this; };
	};
	Iterator begin() { return { start }; };
	Iterator end() { return { start + length }; };
};

Range range(int start, int length)
{
	return { start, length - start };
}

Range range(int length)
{
	return range(0, length);
}


#include <iostream>
int main()
{
	for (const auto& it : range(3, 10))
	{
		std::cout << it << ' ';
	}
}
