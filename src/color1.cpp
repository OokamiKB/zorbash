//
// Copyright goblinhack@gmail.com
// See the README.md file for license info.
// Please use spaces indent of 2, no tabs and column width of 120 to view.
//

#include <strings.h> // do not remove
#include <string.h>  // do not remove
#include "my_sys.h"
#include "my_gl.h"
#include "my_string.h"
#include <strings.h> // do not remove, strcasecmp

color BLACK;
color BLUE;
color COLOR_NONE;
color DARKRED;
color GRAY10;
color GRAY20;
color GRAY30;
color GRAY40;
color GRAY50;
color GRAY60;
color GRAY70;
color GRAY80;
color GRAY90;
color GRAY;
color GREEN;
color ORANGE;
color PURPLE;
color RED;
color WHITE;
color YELLOW;
color DARKBLUE;
color DARKGREEN;
color BROWN;
color BLUE1;
color BLUE2;
color BLUE4;
color BLUE3;
color PINK;
color DARKGRAY;
color LIGHTBLUE;
color CYAN;
color LIMEGREEN;
color LIME;
color GOLD;
color FORESTGREEN;
color BROWN1;
color BROWN2;
color BROWN3;
color BROWN4;

#if 0
color ALICE_BLUE;
color ALICEBLUE;
color ANTIQUEWHITE1;
color ANTIQUEWHITE2;
color ANTIQUEWHITE3;
color ANTIQUEWHITE4;
color ANTIQUE_WHITE;
color ANTIQUEWHITE;
color AQUAMARINE1;
color AQUAMARINE2;
color AQUAMARINE3;
color AQUAMARINE4;
color AQUAMARINE;
color AZURE1;
color AZURE2;
color AZURE3;
color AZURE4;
color AZURE;
color BEIGE;
color BISQUE1;
color BISQUE2;
color BISQUE3;
color BISQUE4;
color BISQUE;
color BLACK;
color BLANCHEDALMOND;
color BLUE1;
color BLUE2;
color BLUE3;
color BLUE4;
color BLUE;
color BLUE_VIOLET;
color BLUEVIOLET;
color BURLYWOOD1;
color BURLYWOOD2;
color BURLYWOOD3;
color BURLYWOOD4;
color BURLYWOOD;
color CADETBLUE1;
color CADETBLUE2;
color CADETBLUE3;
color CADETBLUE4;
color CADET_BLUE;
color CADETBLUE;
color CHARTREUSE1;
color CHARTREUSE2;
color CHARTREUSE3;
color CHARTREUSE4;
color CHARTREUSE;
color CHOCOLATE1;
color CHOCOLATE2;
color CHOCOLATE3;
color CHOCOLATE4;
color CHOCOLATE;
color CORAL1;
color CORAL2;
color CORAL3;
color CORAL4;
color CORAL;
color CORNFLOWER_BLUE;
color CORNFLOWERBLUE;
color CORNSILK1;
color CORNSILK2;
color CORNSILK3;
color CORNSILK4;
color CORNSILK;
color CYAN1;
color CYAN2;
color CYAN3;
color CYAN4;
color DARKBLUE;
color DARKCYAN;
color DARKGRAY;
color DARKGREEN;
color DARKKHAKI;
color DARKMAGENTA;
color DARKOLIVEGREEN1;
color DARKOLIVEGREEN2;
color DARKOLIVEGREEN3;
color DARKOLIVEGREEN4;
color DARKOLIVEGREEN;
color DARKORANGE1;
color DARKORANGE2;
color DARKORANGE3;
color DARKORANGE4;
color DARKORANGE;
color DARKRED;
color DARKSEAGREEN1;
color DARKSEAGREEN2;
color DARKSEAGREEN3;
color DARKSEAGREEN4;
color DARKSEAGREEN;
color DARKSLATEBLUE;
color VDARKSLATEBLUE;
color VVDARKSLATEBLUE;
color DARKSLATEGRAY1;
color DARKSLATEGRAY2;
color DARKSLATEGRAY3;
color DARKSLATEGRAY4;
color DARKSLATEGRAY;
color DARKTURQUOISE;
color DARKVIOLET;
color DEEPPINK1;
color DEEPPINK2;
color DEEPPINK3;
color DEEPPINK4;
color DEEP_PINK;
color DEEPPINK;
color DEEPSKYBLUE1;
color DEEPSKYBLUE2;
color DEEPSKYBLUE3;
color DEEPSKYBLUE4;
color DEEPSKYBLUE;
color DIM_GRAY;
color DIMGRAY;
color DODGERBLUE1;
color DODGERBLUE2;
color DODGERBLUE3;
color DODGERBLUE4;
color DODGER_BLUE;
color DODGERBLUE;
color FIREBRICK1;
color FIREBRICK2;
color FIREBRICK3;
color FIREBRICK4;
color FIREBRICK;
color FLORAL_WHITE;
color FLORALWHITE;
color FOREST_GREEN;
color GAINSBORO;
color GHOST_WHITE;
color GHOSTWHITE;
color GOLD1;
color GOLD2;
color GOLD3;
color GOLD4;
#endif

void color_init1(void) {
  TRACE_AND_INDENT();
  color_set("brown1", &BROWN1, 255, 64, 64, 255);
  color_set("brown2", &BROWN2, 238, 59, 59, 255);
  color_set("brown3", &BROWN3, 205, 51, 51, 255);
  color_set("brown4", &BROWN4, 139, 35, 35, 255);
  color_set("lime", &LIME, 50, 205, 50, 255);
  color_set("limegreen", &LIMEGREEN, 50, 205, 50, 255);
  color_set("black", &BLACK, 0, 0, 0, 255);
  color_set("blue", &BLUE, 0, 0, 255, 255);
  color_set("none", &COLOR_NONE, 0, 0, 0, 0);
  color_set("darkred", &DARKRED, 139, 0, 0, 255);
  color_set("gray10", &GRAY10, 26, 26, 26, 255);
  color_set("gray20", &GRAY20, 51, 51, 51, 255);
  color_set("gray30", &GRAY30, 77, 77, 77, 255);
  color_set("gray40", &GRAY40, 102, 102, 102, 255);
  color_set("gray50", &GRAY50, 127, 127, 127, 255);
  color_set("gray60", &GRAY60, 153, 153, 153, 255);
  color_set("gray70", &GRAY70, 179, 179, 179, 255);
  color_set("gray80", &GRAY80, 204, 204, 204, 255);
  color_set("gray90", &GRAY90, 229, 229, 229, 255);
  color_set("gray", &GRAY, 190, 190, 190, 255);
  color_set("green", &GREEN, 0, 255, 0, 255);
  color_set("orange", &ORANGE, 255, 165, 0, 255);
  color_set("purple", &PURPLE, 160, 32, 240, 255);
  color_set("red", &RED, 255, 0, 0, 255);
  color_set("white", &WHITE, 255, 255, 255, 255);
  color_set("yellow", &YELLOW, 255, 255, 0, 255);
  color_set("darkblue", &DARKBLUE, 0, 0, 139, 255);
  color_set("darkgreen", &DARKGREEN, 0, 100, 0, 255);
  color_set("brown", &BROWN, 165, 42, 42, 255);
  color_set("blue1", &BLUE1, 0, 0, 255, 255);
  color_set("blue2", &BLUE2, 0, 0, 238, 255);
  color_set("blue4", &BLUE4, 0, 0, 139, 255);
  color_set("blue3", &BLUE3, 0, 0, 205, 255);
  color_set("pink", &PINK, 255, 192, 203, 255);
  color_set("darkgray", &DARKGRAY, 169, 169, 169, 255);
  color_set("lightblue", &LIGHTBLUE, 173, 216, 230, 255);
  color_set("cyan", &CYAN, 0, 255, 255, 255);
  color_set("gold", &GOLD, 255, 215, 0, 255);
  color_set("forestgreen", &FORESTGREEN, 34, 139, 34, 255);

#if 0
  color_set("aliceblue", &ALICEBLUE, 240, 248, 255, 255);
  color_set("antiquewhite1", &ANTIQUEWHITE1, 255, 239, 219, 255);
  color_set("antiquewhite2", &ANTIQUEWHITE2, 238, 223, 204, 255);
  color_set("antiquewhite3", &ANTIQUEWHITE3, 205, 192, 176, 255);
  color_set("antiquewhite4", &ANTIQUEWHITE4, 139, 131, 120, 255);
  color_set("antiquewhite", &ANTIQUEWHITE, 250, 235, 215, 255);
  color_set("aquamarine1", &AQUAMARINE1, 127, 255, 212, 255);
  color_set("aquamarine2", &AQUAMARINE2, 118, 238, 198, 255);
  color_set("aquamarine3", &AQUAMARINE3, 102, 205, 170, 255);
  color_set("aquamarine4", &AQUAMARINE4, 69, 139, 116, 255);
  color_set("aquamarine", &AQUAMARINE, 127, 255, 212, 255);
  color_set("azure1", &AZURE1, 240, 255, 255, 255);
  color_set("azure2", &AZURE2, 224, 238, 238, 255);
  color_set("azure3", &AZURE3, 193, 205, 205, 255);
  color_set("azure4", &AZURE4, 131, 139, 139, 255);
  color_set("azure", &AZURE, 240, 255, 255, 255);
  color_set("beige", &BEIGE, 245, 245, 220, 255);
  color_set("bisque1", &BISQUE1, 255, 228, 196, 255);
  color_set("bisque2", &BISQUE2, 238, 213, 183, 255);
  color_set("bisque3", &BISQUE3, 205, 183, 158, 255);
  color_set("bisque4", &BISQUE4, 139, 125, 107, 255);
  color_set("bisque", &BISQUE, 255, 228, 196, 255);
  color_set("black", &BLACK, 0, 0, 0, 255);
  color_set("blanchedalmond", &BLANCHEDALMOND, 255, 235, 205, 255);
  color_set("blue1", &BLUE1, 0, 0, 255, 255);
  color_set("blue2", &BLUE2, 0, 0, 238, 255);
  color_set("blue3", &BLUE3, 0, 0, 205, 255);
  color_set("blue4", &BLUE4, 0, 0, 139, 255);
  color_set("blue", &BLUE, 0, 0, 255, 255);
  color_set("blueviolet", &BLUEVIOLET, 138, 43, 226, 255);
  color_set("brown", &BROWN, 165, 42, 42, 255);
  color_set("burlywood1", &BURLYWOOD1, 255, 211, 155, 255);
  color_set("burlywood2", &BURLYWOOD2, 238, 197, 145, 255);
  color_set("burlywood3", &BURLYWOOD3, 205, 170, 125, 255);
  color_set("burlywood4", &BURLYWOOD4, 139, 115, 85, 255);
  color_set("burlywood", &BURLYWOOD, 222, 184, 135, 255);
  color_set("cadetblue1", &CADETBLUE1, 152, 245, 255, 255);
  color_set("cadetblue2", &CADETBLUE2, 142, 229, 238, 255);
  color_set("cadetblue3", &CADETBLUE3, 122, 197, 205, 255);
  color_set("cadetblue4", &CADETBLUE4, 83, 134, 139, 255);
  color_set("cadetblue", &CADETBLUE, 95, 158, 160, 255);
  color_set("chartreuse1", &CHARTREUSE1, 127, 255, 0, 255);
  color_set("chartreuse2", &CHARTREUSE2, 118, 238, 0, 255);
  color_set("chartreuse3", &CHARTREUSE3, 102, 205, 0, 255);
  color_set("chartreuse4", &CHARTREUSE4, 69, 139, 0, 255);
  color_set("chartreuse", &CHARTREUSE, 127, 255, 0, 255);
  color_set("chocolate1", &CHOCOLATE1, 255, 127, 36, 255);
  color_set("chocolate2", &CHOCOLATE2, 238, 118, 33, 255);
  color_set("chocolate3", &CHOCOLATE3, 205, 102, 29, 255);
  color_set("chocolate4", &CHOCOLATE4, 139, 69, 19, 255);
  color_set("chocolate", &CHOCOLATE, 210, 105, 30, 255);
  color_set("coral1", &CORAL1, 255, 114, 86, 255);
  color_set("coral2", &CORAL2, 238, 106, 80, 255);
  color_set("coral3", &CORAL3, 205, 91, 69, 255);
  color_set("coral4", &CORAL4, 139, 62, 47, 255);
  color_set("coral", &CORAL, 255, 127, 80, 255);
  color_set("cornflowerblue", &CORNFLOWERBLUE, 100, 149, 237, 255);
  color_set("cornsilk1", &CORNSILK1, 255, 248, 220, 255);
  color_set("cornsilk2", &CORNSILK2, 238, 232, 205, 255);
  color_set("cornsilk3", &CORNSILK3, 205, 200, 177, 255);
  color_set("cornsilk4", &CORNSILK4, 139, 136, 120, 255);
  color_set("cornsilk", &CORNSILK, 255, 248, 220, 255);
  color_set("cyan1", &CYAN1, 0, 255, 255, 255);
  color_set("cyan2", &CYAN2, 0, 238, 238, 255);
  color_set("cyan3", &CYAN3, 0, 205, 205, 255);
  color_set("cyan4", &CYAN4, 0, 139, 139, 255);
  color_set("darkblue", &DARKBLUE, 0, 0, 139, 255);
  color_set("darkcyan", &DARKCYAN, 0, 139, 139, 255);
  color_set("darkgray", &DARKGRAY, 169, 169, 169, 255);
  color_set("darkgreen", &DARKGREEN, 0, 100, 0, 255);
  color_set("darkkhaki", &DARKKHAKI, 189, 183, 107, 255);
  color_set("darkmagenta", &DARKMAGENTA, 139, 0, 139, 255);
  color_set("darkolivegreen1", &DARKOLIVEGREEN1, 202, 255, 112, 255);
  color_set("darkolivegreen2", &DARKOLIVEGREEN2, 188, 238, 104, 255);
  color_set("darkolivegreen3", &DARKOLIVEGREEN3, 162, 205, 90, 255);
  color_set("darkolivegreen4", &DARKOLIVEGREEN4, 110, 139, 61, 255);
  color_set("darkolivegreen", &DARKOLIVEGREEN, 85, 107, 47, 255);
  color_set("darkorange1", &DARKORANGE1, 255, 127, 0, 255);
  color_set("darkorange2", &DARKORANGE2, 238, 118, 0, 255);
  color_set("darkorange3", &DARKORANGE3, 205, 102, 0, 255);
  color_set("darkorange4", &DARKORANGE4, 139, 69, 0, 255);
  color_set("darkorange", &DARKORANGE, 255, 140, 0, 255);
  color_set("darkred", &DARKRED, 139, 0, 0, 255);
  color_set("darkseagreen1", &DARKSEAGREEN1, 193, 255, 193, 255);
  color_set("darkseagreen2", &DARKSEAGREEN2, 180, 238, 180, 255);
  color_set("darkseagreen3", &DARKSEAGREEN3, 155, 205, 155, 255);
  color_set("darkseagreen4", &DARKSEAGREEN4, 105, 139, 105, 255);
  color_set("darkseagreen", &DARKSEAGREEN, 143, 188, 143, 255);
  color_set("darkslateblue", &DARKSLATEBLUE, 72, 61, 139, 255);
  color_set("vdarkslateblue", &VDARKSLATEBLUE, 42, 31, 109, 255);
  color_set("vvdarkslateblue", &VVDARKSLATEBLUE, 32, 21, 99, 255);
  color_set("darkslategray1", &DARKSLATEGRAY1, 151, 255, 255, 255);
  color_set("darkslategray2", &DARKSLATEGRAY2, 141, 238, 238, 255);
  color_set("darkslategray3", &DARKSLATEGRAY3, 121, 205, 205, 255);
  color_set("darkslategray4", &DARKSLATEGRAY4, 82, 139, 139, 255);
  color_set("darkslategray", &DARKSLATEGRAY, 47, 79, 79, 255);
  color_set("darkturquoise", &DARKTURQUOISE, 0, 206, 209, 255);
  color_set("darkviolet", &DARKVIOLET, 148, 0, 211, 255);
  color_set("deeppink1", &DEEPPINK1, 255, 20, 147, 255);
  color_set("deeppink2", &DEEPPINK2, 238, 18, 137, 255);
  color_set("deeppink3", &DEEPPINK3, 205, 16, 118, 255);
  color_set("deeppink4", &DEEPPINK4, 139, 10, 80, 255);
  color_set("deeppink", &DEEPPINK, 255, 20, 147, 255);
  color_set("deepskyblue1", &DEEPSKYBLUE1, 0, 191, 255, 255);
  color_set("deepskyblue2", &DEEPSKYBLUE2, 0, 178, 238, 255);
  color_set("deepskyblue3", &DEEPSKYBLUE3, 0, 154, 205, 255);
  color_set("deepskyblue4", &DEEPSKYBLUE4, 0, 104, 139, 255);
  color_set("deepskyblue", &DEEPSKYBLUE, 0, 191, 255, 255);
  color_set("dimgray", &DIMGRAY, 105, 105, 105, 255);
  color_set("dodgerblue1", &DODGERBLUE1, 30, 144, 255, 255);
  color_set("dodgerblue2", &DODGERBLUE2, 28, 134, 238, 255);
  color_set("dodgerblue3", &DODGERBLUE3, 24, 116, 205, 255);
  color_set("dodgerblue4", &DODGERBLUE4, 16, 78, 139, 255);
  color_set("dodgerblue", &DODGERBLUE, 30, 144, 255, 255);
  color_set("firebrick1", &FIREBRICK1, 255, 48, 48, 255);
  color_set("firebrick2", &FIREBRICK2, 238, 44, 44, 255);
  color_set("firebrick3", &FIREBRICK3, 205, 38, 38, 255);
  color_set("firebrick4", &FIREBRICK4, 139, 26, 26, 255);
  color_set("firebrick", &FIREBRICK, 178, 34, 34, 255);
  color_set("floralwhite", &FLORALWHITE, 255, 250, 240, 255);
  color_set("gainsboro", &GAINSBORO, 220, 220, 220, 255);
  color_set("ghostwhite", &GHOSTWHITE, 248, 248, 255, 255);
  color_set("gold1", &GOLD1, 255, 215, 0, 255);
  color_set("gold2", &GOLD2, 238, 201, 0, 255);
  color_set("gold3", &GOLD3, 205, 173, 0, 255);
  color_set("gold4", &GOLD4, 139, 117, 0, 255);
#endif
}
