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

    return true;
  }


private:

};
