#include "stdafx.h"
#include "ClickableItems.h"


ClickableItems::ClickableItems()
	: ClickableItems("")
{
	
}

ClickableItems::ClickableItems(string text)
	:ClickableItems(text, 0, 0)
{
	
}

ClickableItems::ClickableItems(string text, int x, int y)
	: ClickableItems(text, Color(0,0,0), x, y)
{
	
}

ClickableItems::ClickableItems(string text, Color & color, int x, int y)
	: ClickableItems(text, color, x, y, 0, 0)
{
	
}

ClickableItems::ClickableItems(string text, Color & color, int x, int y, int w, int h)
	: ZControlBase(x, y, w, h)
{
	hit = pressed = mouseButtonDown = false;
	this->text = new Label(text, color, x, y);
}


ClickableItems::ClickableItems(const ClickableItems & other)
{
	this->text = other.text;
	this->hit = other.hit;
	this->pressed = other.pressed;
}

ClickableItems::~ClickableItems()
{
	delete text;
}

//Done
void ClickableItems::SetText(string text)
{
  this->text->SetText(text);
}

//Done
string ClickableItems::GetText()
{
  return text->GetText();
}

//Done
void ClickableItems::SetTextColor(Color& newColor)
{
  this->text->SetTextColor(newColor);
}

Color ClickableItems::GetTextColor()
{
	return text->GetTextColor();
}

void ClickableItems::OnPaint()
{
	text->OnPaint();
}

void ClickableItems::OnMouseDown(int button, int x, int y)
{
	if (hit && button==MOUSE_LEFT)
	{
		pressed = true;
	}
}

void ClickableItems::OnMouseMove(int button, int x, int y)
{
	if (x > X && x < X + Width && y>Y && y < Y + Height)
	{
		hit = true;
	}
	else
	{
		pressed = hit = false;
	}
}

void ClickableItems::OnMouseUp(int button, int x, int y)
{
	pressed = false;
}
