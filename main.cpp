#include<iostream>
#include<vector>
#include"FreeImage.h"
#include"IO.h"
#include"GetPixelData.h"
#include"ImageProcess.h"

int main(void)
{
    FreeImage_Initialise();

    std::cout << "FreeImage ver. " << FreeImage_GetVersion() << std::endl;
    std::cout << FreeImage_GetCopyrightMessage() << std::endl;

    try
    {
        char path[] = "a.png";

        IO io;
        std::shared_ptr<FIBITMAP> image = std::shared_ptr<FIBITMAP>(io.GenericLoader(path, 0), FreeImage_Unload);
        if (!image)
        {
            throw std::runtime_error("Load failed");
        }

        RGBQUAD* color;
        GetPixelData pixels(FreeImage_GetWidth(image.get()), FreeImage_GetHeight(image.get()));

        std::shared_ptr<FIBITMAP> alpha = std::shared_ptr<FIBITMAP>(FreeImage_Allocate(pixels.getWidth(), pixels.getHeight(), FreeImage_GetBPP(image.get())),FreeImage_Unload);
        std::vector<int> edgeLoc(pixels.getWidth() * pixels.getHeight());
        pixels.copyAlpha(image, edgeLoc.begin());

        ImageProcess ip;
        std::shared_ptr<FIBITMAP> output = std::shared_ptr<FIBITMAP>(FreeImage_Allocate(pixels.getWidth(), pixels.getHeight()
            , FreeImage_GetBPP(image.get())), FreeImage_Unload);
        ip.Huchidori(image, edgeLoc.begin(), output, pixels.getWidth(), pixels.getHeight());

        io.GenericWriter(output.get(), "convert.png", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "exception!\n" << e.what() << std::endl;
    }
}