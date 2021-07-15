
#include <iostream>
#include "ft2build.h"
#include FT_FREETYPE_H  

int main(){
    FT_Library ftLib;
    if (FT_Init_FreeType(&ftLib)){
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        return -1;
    }

    FT_Face face;
    if (FT_New_Face(ftLib, "kaiti.ttf", 0, &face)){
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
        return -1;
    }
    
    FT_Set_Pixel_Sizes(face , 0 , 32);

    if (FT_Load_Char(face, 'B', FT_LOAD_RENDER)){
        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
        return -1;
    }

    std::cout << "width = " << face->glyph->bitmap.width << std::endl;
    std::cout << "height = " << face->glyph->bitmap.rows << std::endl;
    std::cout << "pitch  = " << face->glyph->bitmap.pitch << std::endl;

    std::cout << "left = " << face->glyph->bitmap_left << std::endl;
    std::cout << "top  = " << face->glyph->bitmap_top << std::endl;

    std::cout << "advance  = " << face->glyph->advance.x / 64 << 
        " , " << face->glyph->advance.y << std::endl;

    FT_Bitmap fontBit = face->glyph->bitmap;

    for(int i = 0 ;  i < fontBit.rows ; i++ ){
        for(int j = 0 ; j < fontBit.width ; j++){
            std::cout << ((fontBit.buffer[i * fontBit.pitch + j] == 0)?" ":"x");
        }
        std::cout<< std::endl;
    }

    FT_Done_Face(face);
    FT_Done_FreeType(ftLib);
    return 0;
}


/**
 * 
 * 
 * xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx
xxxxxxxxxx

 * */
