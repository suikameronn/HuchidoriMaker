#pragma once
#include<iostream>
#include<vector>
#include<FreeImage.h>

class ImageProcess
{
private:
	std::vector<int>::iterator begin;

public:
	void Huchidori(std::shared_ptr<FIBITMAP> image, std::vector<int> edgeLoc);
};