#pragma once
#include<iostream>
#include<vector>
#include<FreeImage.h>

class ImageProcess
{
private:
	std::vector<int>::iterator x;
	std::vector<int>::iterator y;

public:
	void Huchidori(std::shared_ptr<FIBITMAP> image, std::vector<int> &edgeLoc,int width,int height);
};