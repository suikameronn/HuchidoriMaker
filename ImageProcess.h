#pragma once
#include<iostream>
#include<vector>
#include<FreeImage.h>

class ImageProcess
{
private:

public:
	void Huchidori(std::shared_ptr<FIBITMAP> image
		, std::vector<int>::iterator begin, std::vector<int>::iterator end, std::shared_ptr<FIBITMAP> output
			,int width,int height);
};