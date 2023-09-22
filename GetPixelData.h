#pragma once
#include<iostream>
#include"FreeImage.h"

class GetPixelData
{
private:

	const int width, height;

public:
	GetPixelData(const int w,const int h);

	void copyAlpha(std::shared_ptr<FIBITMAP> image, std::shared_ptr<unsigned char[]> alpha);

	int get_Width();
	int get_Height();
};