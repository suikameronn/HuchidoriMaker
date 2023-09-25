#pragma once
#include<iostream>
#include<FreeImage.h>

class ImageProcess
{
private:

public:
	void Huchidori(std::shared_ptr<FIBITMAP> image
		, std::shared_ptr<unsigned char[]> alphaDegree, std::shared_ptr<FIBITMAP> output
			,int width,int height);
};