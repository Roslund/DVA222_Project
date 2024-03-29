#include "stdafx.h"
#include "Selector.h"

Selector::Selector()
  : Selector("")
{}

Selector::Selector(string text)
  : Selector(text, 0, 0)
{}


Selector::Selector(string text, int x, int y)
  : Selector(text, Color(0, 0, 0), x, y)
{}

Selector::Selector(string text, Color& color, int x, int y)
  : ClickableItems(text, color, x, y)
{}

Selector::~Selector()
{
}

bool Selector::GetStatus()
{
  return pressed;
}

void Selector::SetStatus(bool newStatus)
{
  pressed = newStatus;
}

void Selector::OnPaint()
{
  checked->SetX(X);
  checked->SetY(Y);
  hover->SetX(X);
  hover->SetY(Y);
  normal->SetX(X);
  normal->SetY(Y);
  text->SetPosition(X + 20, Y + 14);//Plus 20 och 14 f�r att flytta label till bredvid en selector
  if(pressed == true)
  {
    checked->OnPaint();
  }
  else if(hit == true)
  {
    hover->OnPaint();
  }
  else
  {
    normal->OnPaint();
  }
  text->OnPaint();
}


void Selector::OnMouseDown(int button, int x, int y)
{
  //kollar om musen �r inuti selectorn
  if(hit && button == MOUSE_LEFT && mouseButtonDown == false)
  {
    mouseButtonDown = true;
    pressed = !pressed;
  }
}

void Selector::OnMouseMove(int button, int x, int y)
{
    //kollar om musen �r inuti selectorn
    if(x > X && x < X + 16 && y > Y && y < Y + 16)
    {
      hit = true;
    }
    else
    {
      hit = false;
    }
}

/*M�ste overloada OnMouseUp, annars s�tter Clickable items pressed == false varje g�ng
man trycker p� en radiobutton.*/
void Selector::OnMouseUp(int button, int x, int y)
{
  mouseButtonDown = false;
}
