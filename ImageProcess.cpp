#include"ImageProcess.h"
#include<iostream>
#include"FreeImage.h"

std::shared_ptr<FIBITMAP> ImageProcess::Huchidori(std::shared_ptr<FIBITMAP> image
	,std::shared_ptr<unsigned char[]> alphaDegree,std::shared_ptr<FIBITMAP> output,int width,int height,RGBQUAD color)
{
	int i, j, k, m;
	RGBQUAD huchi = { 255,255,255,255 };

	for (i = 0; i < width - 2; i++)
	{
		for (j = 0; j < height - 2; j++)
		{
			if (alphaDegree[i] == 1)
			{
				FreeImage_GetPixelColor(image.get(), j + 1 + 1, i, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1 + 1, i, &huchi);
				}

				FreeImage_GetPixelColor(image.get(), j + 1 - 1, i, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1 - 1, i + 1, &huchi);
				}

				FreeImage_GetPixelColor(image.get(), j + 1 , i - 1, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1, i - 1, &huchi);
				}

				FreeImage_GetPixelColor(image.get(), j + 1, i + 1, &color);
				if (color.rgbReserved == 0)
				{
					FreeImage_SetPixelColor(output.get(), j + 1, i + 1, &huchi);
				}
			}
		}
	}
}