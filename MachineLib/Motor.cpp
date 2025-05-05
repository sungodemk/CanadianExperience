/**
 * @file Motor.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Motor.h"
#include <cmath>    // For M_PI if needed
#include <iostream>

// Constructor: Initialize the motor's shaft and body shapes.
Motor::Motor(std::wstring imagesDir) :
        mImagesDir(imagesDir)
{
    // Configure the shaft using the inherited mImage (from Component).
    //  use a centered square of size 50 for the shaft.
    mImage.CenteredSquare(25);
   // mImage.SetColor(*wxBLUE);
    mImage.SetImage( mImagesDir + L"/shaft.png");

    // Configure the motor body shape. For example, you might choose a circle:
    mBody.CenteredSquare(80); // A circle of radius 30 with 32 segments
    mBody.SetImage( mImagesDir + L"/motor3.png");

    // (Optionally, adjust additional properties such as color, rotation,
    // or local offsets here if necessary.)
}

Motor::~Motor()
{
    // Destructor logic if needed
}

// Override the Draw function.
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition)
{
    // First, upcall the base class draw function to draw the shaft.
    Component::Draw(graphics, machinePosition);
    // Now add additional drawing for the motor body.
    // as the shaft, or with some offset.
    graphics->PushState();

    // Translate to the component's position
    graphics->Translate(machinePosition.x + mLocation.x, machinePosition.y + mLocation.y);

    // Draw the motor body
    mBody.DrawPolygon(graphics, 0, 0);

    graphics->PopState();

}
void Motor::SetTime(double time)
{
    // Choose a speed (turns per second). You can store this in a member.
    const double speed = 1.0;
    // Compute the rotation (in turns) based on time.
    mRotation = speed * time;
    // Also propagate to base in case it does other work:
    Component::SetTime(time);
    // Push the rotation to any connected sinks
    mSource.Drive(mRotation);
}

void Motor::SetImage(const std::wstring& filename)
{
    // mImage is the inherited Polygon for the shaft
    mImage.SetImage(filename);
}