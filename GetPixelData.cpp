#pragma once
#include <iostream>
#include "FreeImage.h"
#include "GetPixelData.h"

GetPixelData::GetPixelData(int w, int h): width(w),height(h)
{
	pColor[(width - 2) * (height - 2)];
}

void GetPixelData::copyAlpha(std::shared_ptr<FIBITMAP> image,std::shared_ptr<FIBITMAP> alpha)
{
	int i,j;

	//œZ‚ğ‰ñ”ğ‚·‚é
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			FreeImage_GetPixelColor(image.get(), j, i, &color);
			FreeImage_SetPixelColor(alpha.get(), j, i, &color);
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
				tmp = 255;
			}

			/*
			printf("%d", color.rgbRed);
			printf("%d", color.rgbGreen);
			printf("%d", color.rgbBlue);
			printf("%d\n", color.rgbReserved);
			*/

			color = { (unsigned char)tmp,(unsigned char)tmp,(unsigned char)tmp,(unsigned char)tmp};
			pColor[j + i * (width - 2)] = tmp;
		}
	}
}

int GetPixelData::get_Width()
{
	return width;
}

int GetPixelData::get_Height()
{
	return height;
}