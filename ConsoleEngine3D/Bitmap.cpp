#include "pch.h"
#include "Bitmap.h"
template <class T>
Bitmap<T>::Bitmap(const int width, const int height, const T background)
 : width(width), height(height), bufferSize(width * height), background(background){
	buffer = new T[bufferSize];
	fill(background);
}

template <class T>
Bitmap<T>::~Bitmap(){
	delete buffer;
}

template <class T>
const void Bitmap<T>::fill(const T chr) {
	for (int i = 0; i < bufferSize; i++) {
		set(chr, i);
	}
}

template<typename T>
const void Bitmap<T>::clear(){
	fill(background);
}

template <class T>
const void Bitmap<T>::fill(const Bitmap<T> &bitmap, int offsetX, int offsetY) {
	for (int i = 0; i < bitmap.bufferSize; i++) {
		int x = offsetX + i % bitmap.width;
		int y = offsetY + i / bitmap.width;
		if (x < width && y < height && x >= 0 && y >= 0) {
			set(bitmap.buffer[i], x, y);
		}
	}
}
template <class T>
const int Bitmap<T>::getIndex(const int x, const int y) {
	return x + y * width;
}

template <class T>
const T Bitmap<T>::get(const int x, const int y) {
	int index = getIndex(x, y);
	if (index >= 0 && index < bufferSize) {
		return buffer[index];
	}
	else {
		return 'ë';
	}
}

template <class T>
const T Bitmap<T>::get(const int index) {
	if (index >= 0 && index < bufferSize) {
		return buffer[index];
	}
	else {
		return 'ë';
	}
}

template <class T>
const void Bitmap<T>::set(const T chr, const int x, const int y) {
	int index = getIndex(x, y);
	if (index >= 0 && index < bufferSize) {
		buffer[index] = chr;
	}
}

template <class T>
const void Bitmap<T>::set(const T chr, const int index) {
	if (index >= 0 && index < bufferSize) {
		buffer[index] = chr;
	}
}

template <class T>
const void Bitmap<T>::operator = (const T chr) {
	fill(chr);
}
template <class T>
const void Bitmap<T>::operator = (const T* buff) {
	for (int i = 0; i < bufferSize; i++) {
		if (buff[i] == '\0') {
			break;
		}
		set(buff[i], i);
	}
}