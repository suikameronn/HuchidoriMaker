#pragma once
#include "GetPixelData.h"

GetPixelData::GetPixelData(int w, int h): width(w),height(h)
{
}

void GetPixelData::copyAlpha(std::shared_ptr<FIBITMAP> image, std::vector<int>::iterator itr)
{
	int i, j;
	RGBQUAD color;

	//���Z���������
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			FreeImage_GetPixelColor(image.get(), j, i, &color);
		}
	}

	int tmp;
	for (i = 1; i < height - 1; i++)
	{
		for (j = 1; j < width - 1; j++)
		{
			tmp = 0;

			FreeImage_GetPixelColor(image.get(), j, i, &color);
			tmp -= color.rgbReserved * 4;

			FreeImage_GetPixelColor(image.get(), j + 1, i, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image.get(), j - 1, i, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image.get(), j, i + 1, &color);
			tmp += color.rgbReserved;
			FreeImage_GetPixelColor(image.get(), j, i - 1, &color);
			tmp += color.rgbReserved;

			if (tmp != 0)
			{
				*itr = j + (width - 2) * i;
				itr++;
			}
		}
	}
}

int GetPixelData::getWidth()
{
	return width;
}

int GetPixelData::getHeight()
{
	return height;
}