#pragma once
#include<iostream>
#include<vector>
#include"FreeImage.h"

class GetPixelData
{
private:

	const int width, height;

	RGBQUAD color;

	std::vector<int>::iterator begin;
	std::vector<int>::iterator end;

public:
	GetPixelData(const int w,const int h);

	void copyAlpha(std::shared_ptr<FIBITMAP> image, std::vector<int> &edgeLoc);

	int getWidth();
	int getHeight();
};