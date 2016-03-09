#pragma once
#include "Container.h"

#include <string>

class SelectorGroup :
  public Container
{
public:
  SelectorGroup(int x, int y, int w, int h, string title);
  SelectorGroup(const SelectorGroup& other);
  ~SelectorGroup();
  virtual void OnPaint();
private:
  Label* title;
  Color* boarderColor;
  //Boarder????? Acecceble via set/get functions
};

