#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.hpp"
#include "DEFINITIONS.hpp"

class game : public olc::PixelGameEngine {
public:
  game(){
    sAppName = "temp";
  }


  bool OnUserCreate() override {

    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override {
    Clear(olc::BLACK);

    // std::cout << GetMouseX() << " " << GetMouseY() << '\n';

    int mouseX = GetMouseX();
    int mouseY = GetMouseY();


    for(int y = 0; y < map.size(); y++){
      for(int x = 0; x < map.at(y).size(); x++){
        if(map.at(y).at(x) == 1){

          int newx = (xOffset + (x*16)) - ((xOffset + (x*16)))/2;
          int newy = (yOffset + (y*16)) - ((yOffset + (y*16)))/2;
          DrawRect(xOffset + (x*16), yOffset + (y*16), 16, 16);
          // std::cout << xOffset + (x*16) << " " << yOffset + (y*16) << '\n';

        }
      }
    }

    int mapX = (map.size() * 16) - (map.size() * 16);
    int mapY = (map.size() * 16) - (map.size() * 16);


    if(GetMouse(0).bHeld){
      std::cout << xOffset << " " << yOffset << '\n';
      xOffset = mouseX;
      yOffset = mouseY;
    }

    return true;
  }


private:
  std::vector<std::vector<int>> map = {
    {0, 0, 0, 1, 0 ,0, 0},
    {0, 1, 1, 0, 1 ,1, 0},
    {0, 1, 0, 0, 0 ,0, 1},
    {0, 0, 1, 0, 0 ,1, 0},
    {0, 0, 1, 1, 1 ,1, 0},
  };

  int xOffset = 0;
  int yOffset = 0;

};
