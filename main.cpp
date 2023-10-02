#include<iostream>
#include<vector>
#include<stdlib.h>
#include <string>
#include"FreeImage.h"
#include"IO.h"
#include"GetPixelData.h"
#include"ImageProcess.h"

#include<time.h>

int main(void)
{
    FreeImage_Initialise();

    char input[100];
    char output[100];
    std::string finish;

    while (true)
    {
        std::cout << "縁をとる画像のディレクトリを入力してください" << std::endl;
        std::cin >> input;

        std::cout << "加工後の画像の保存先のディレクトリを入力してください" << std::endl;
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

            std::vector<int> edgeLoc(pixels.getWidth() * pixels.getHeight(),-1);
            pixels.copyAlpha(image.get(), edgeLoc);

            for (int i = 0; i < edgeLoc.size(); i++)
            {
                if (true)
                {
                    //std::cout << edgeLoc[i] << std::endl;
                }
            }

            ImageProcess ip;
            ip.Huchidori(image.get(), edgeLoc, pixels.getWidth(), pixels.getHeight());

            if (!io.GenericWriter(image.get(), output, 0))
            {
                throw std::runtime_error("Huchidori failed");
            }
        }
        catch (std::exception& e)
        {
            std::cout << "exception!\n" << e.what() << std::endl;
        }

        std::cout << "続けて加工する場合は、'y'と入力してください\nやめる場合はそれ以外の文字を入力してください" << std::endl;
        getline(std::cin, finish);
        if (finish.length() != 1)
        {
            break;
        }
        else if (finish != "y")
        {
            break;
        }

        std::cin.clear();
        std::cin.ignore(1024, '\n');
    }
}

//エッジ抽出 0.033sec
// エッジ抽出 生ポインタ 0.026sec
//縁取り 0.148sec
// 縁取り 0.144sec
//全体で0.21sec