#include "stdafx.h"
#include "Button.h"

#define AVERAGE_LETTER_WIDTH 3

Button::Button() 
  : Button("", 0, 0, 0, 0)
{
}

Button::Button(string buttonText, int posX, int posY, int width, int height)
  : Button(buttonText, Color(255, 255, 255), Color(0, 0, 0), posX, posY, width, height)
{}

Button::Button(string buttonText, Color& textColor, Color& buttonColor, int posX, int posY, int width, int height)
	: ClickableItems(buttonText, textColor, posX, posY, width, height)
{
	backgroundColor = new Color(buttonColor);
    buttonTextLength = buttonText.length();
}

Button::Button(const Button & other)
{
  this->backgroundColor = other.backgroundColor;
  this->hit = other.hit;
  this->pressed = other.pressed;
}

Button::~Button()
{
  delete backgroundColor;
}

void Button::SetButtonColor(Color & color)
{
	backgroundColor = &color;
}

Color Button::GetButtonColor()
{
	return *backgroundColor;
}


void Button::OnPaint()
{
	/*Bredden delat med tv� (minus) uppskattade bredden p� str�ngen f�r att centrera i x led*/
	text->SetPosition((X + Width / 2) - buttonTextLength*AVERAGE_LETTER_WIDTH, Y + (Height / 2) + 5);
	SetColor(backgroundColor->GetColor().r, backgroundColor->GetColor().g, backgroundColor->GetColor().b);
	if (pressed)
	{
		SetColor(128, 128, 128);
		FillRectangle(X, Y, Width, Height);//Ritar tillf�lligt en ny rektangel ovanp� den gamla
		DrawRectangle(X - 1, Y - 1, Width + 1, Height  + 1);//S� att hover border stannar �ven n�r man klickar
	}
	else if (hit)//Hit == n�r man hovrar �ver knappen
	{
		FillRectangle(X, Y, Width, Height);
		DrawRectangle(X - 1, Y - 1, Width + 2, Height + 2);//Ger button en border n�r man hovrar
	}
	else
	{
		FillRectangle(X, Y, Width, Height);
		SetColor(0, 0, 0);
		DrawRectangle(X, Y, Width + 1, Height + 1);//Fin svart border p� knappen
	}
  ClickableItems::OnPaint();//F�r att rita ut label p� knappen
}
