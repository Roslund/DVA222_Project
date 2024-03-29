// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Graphix.h"
#include "glut.h"

#include "Label.h"
#include "ImageBox.h"
#include "Button.h"

#include "RadioButton.h"
#include "Checkbox.h"

#include "Window.h"
#include "Panel.h"

#include "RadioButtonGroup.h"
#include "CheckboxGroup.h"

using namespace std;


int _tmain(int argc, char** argv)
{
  //A new object of Button type is create and passed to the InitOGL function. 
  //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
  //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
  //------------------------------------------------------------------------------------------------------------------------------------

  //Skapa MainWindow
  Window* mainWindow = new Window("I am a dragable window", Color(255, 252, 255), Color(0, 0, 0), Color(230, 230, 230), 50, 50, 700, 500);
  
  //Create Content
  ZControlBase* topText = new Label("I am a Label. Actually all the text that you see down there are Labels contained in the Panels. My text has a different color", 5, 45, 0, 0, 255);
  ZControlBase* image = new ImageBox("DaloGoatBig.bmp", 30, 350, 112, 120);
  ZControlBase* freeRadioButton = new RadioButton("I am a free RadioButton. This Window is my container.", 30, 190);
  ZControlBase* freeCheckbox = new Checkbox("I am a free CheckBox.", 30, 210);
  ZControlBase* freeButton = new Button("I am a button imprissoned in the panel", Color(0, 0, 0), Color(255, 255, 100), 30, 80, 320, 30);

  //Create pannels
  Panel* greenPanel = new Panel(250, 300, 405, 120, Color(0, 255, 110), 100);
  greenPanel->AddObject(new Label("I am also a Panel. As you can see i'm behind the other panel.", 30, 30, 0, 0, 0));
  greenPanel->AddObject(new Checkbox("I am a Captured CheckBox.", 30, 50));

  Panel* bluePanel = new Panel(200, 350, 405, 120, Color(0, 200, 255), 50);
  bluePanel->AddObject(new Label("I am a Panel. I can contain stuff inside (like the button below).", 30, 30, 0, 0, 0));
  bluePanel->AddObject(new Label("I can also have different colors.", 30, 48, 0, 0, 0));
  bluePanel->AddObject(new Button("I am a button imprissoned in the panel", Color(0, 0, 0), Color(255, 255, 100), 30, 80, 320, 30));

  //Test checkboxGroup
  CheckboxGroup* checkboxGroup = new CheckboxGroup("I am a Checkbox Group", 30, 70, 250);
  checkboxGroup->AddObject(new Checkbox("I am a CheckBox."));
  checkboxGroup->AddObject(new Checkbox("I am another CheckBox."));
  Checkbox* selectedCheckbox1 = new Checkbox("I am a selected CheckBox.");
  Checkbox* selectedCheckbox2 = new Checkbox("I am another selected CheckBox.");
  selectedCheckbox1->SetStatus(true);
  selectedCheckbox2->SetStatus(true);
  checkboxGroup->AddObject(selectedCheckbox1);
  checkboxGroup->AddObject(selectedCheckbox2);

  //Test RadioButtonGroup
  RadioButtonGroup* radioButtonGroup = new RadioButtonGroup("I am a RadioButton Group", 300, 70, 365);
  radioButtonGroup->AddObject(new RadioButton("I am a RadioButton."));
  radioButtonGroup->AddObject(new RadioButton("I am another RadioButton."));
  RadioButton* selectedadioButton = new RadioButton("I am The selected RadioButton. The One and only.");
  selectedadioButton->SetStatus(true);
  radioButtonGroup->AddObject(selectedadioButton);
  radioButtonGroup->AddObject(new RadioButton("I am just another poor RadioButton."));
  
  //Add objects to main window
  mainWindow->AddObject(topText);
  mainWindow->AddObject(image);
  mainWindow->AddObject(freeRadioButton);
  mainWindow->AddObject(freeCheckbox);
  mainWindow->AddObject(static_cast<ZControlBase*>(greenPanel));
  mainWindow->AddObject(static_cast<ZControlBase*>(bluePanel));
  mainWindow->AddObject(static_cast<ZControlBase*>(checkboxGroup));
  mainWindow->AddObject(static_cast<ZControlBase*>(radioButtonGroup));

  //Typecasta mainwindow och k�r InitOGL
  InitOGL(argc, argv, static_cast<ControlBase*>(mainWindow));

  //Delete stuff - but will it ever run?
  delete mainWindow;
	
	return 0;
}

