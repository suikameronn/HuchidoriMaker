#pragma once
#include<iostream>
#include<vector>
#include"FreeImage.h"

class GetPixelData
{
private:

	const int width, height;

public:
	GetPixelData(const int w,const int h);

	void copyAlpha(std::shared_ptr<FIBITMAP> image, std::vector<int>::iterator itr);

	int getWidth();
	int getHeight();
};