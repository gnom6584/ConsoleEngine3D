#pragma once
template <typename T>
class Bitmap{
protected:
	T* buffer;
	int bufferSize = 0;
	T background;
	const void fill(const T chr);
	const int getIndex(const int x, const int y);
public:
	unsigned int width = 0;
	unsigned int height = 0;
	Bitmap(const int width, const int height, const T background);
	~Bitmap();
	//operators
	const void clear();
	const void fill(const Bitmap &bitmap, int offsetX = 0, int offsetY = 0);
	const T get(const int x, const int y);
	const T get(const int index);
	const void set(const T chr, const int x, const int y);
	const void set(const T chr, const int index);
	const void operator = (const T chr);
	const void operator = (const T* buff);
};
template class Bitmap<char>;
template class Bitmap<int>;
template class Bitmap<float>;

