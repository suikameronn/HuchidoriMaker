#include<iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include"FreeImage.h"
#include"IO.h"
#include"GetPixelData.h"
#include"ImageProcess.h"

int main(void)
{
    FreeImage_Initialise();

    char input[100];
    char output[100];
    std::string finish;

    while (true)
    {
        std::cout << "�����Ƃ�摜�̃f�B���N�g������͂��Ă�������" << std::endl;
        std::cin >> input;

        std::cout << "���H��̉摜�̕ۑ���̃f�B���N�g������͂��Ă�������" << std::endl;
        std::cin >> output;

        std::cin.clear();
        std::cin.ignore(1024, '\n');

        try
        {
            IO io;
            std::shared_ptr<FIBITMAP> image = std::shared_ptr<FIBITMAP>(io.GenericLoader(input, 0), FreeImage_Unload);
            if (!image)
            {
                throw std::runtime_error("Load failed");
            }

            GetPixelData pixels(FreeImage_GetWidth(image.get()), FreeImage_GetHeight(image.get()));

            std::shared_ptr<FIBITMAP> copy = std::shared_ptr<FIBITMAP>(FreeImage_Clone(image.get()));

            std::vector<int> edgeLoc(pixels.getWidth() * pixels.getHeight(),-1);
            pixels.copyAlpha(copy.get(), edgeLoc);

            ImageProcess ip;
            ip.Huchidori(copy.get(), edgeLoc, pixels.getWidth(), pixels.getHeight());

            if (!io.GenericWriter(copy.get(), output, 0))
            {
                throw std::runtime_error("Huchidori failed");
            }
        }
        catch (std::exception& e)
        {
            std::cout << "exception!\n" << e.what() << std::endl;
        }

        std::cout << "�����ĉ��H����ꍇ�́A'y'�Ɠ��͂��Ă�������\n��߂�ꍇ�͂���ȊO�̕�������͂��Ă�������" << std::endl;
        getline(std::cin, finish);
        if (finish.length() != 1)
        {
            break;
        }
        else if (finish != "y")
        {
            break;
        }
    }
}