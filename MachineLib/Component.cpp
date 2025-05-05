/**
 * @file Component.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Component.h"



Component::Component()
{
}
Component::~Component()
{
    // destructor code (even if empty)
}

/**
 * Draw the component. The UML shows we have two parameters:
 * - The graphics context
 * - The machinePosition so we know where the machine is located overall.
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition)
{
    // We'll push the state so we can apply a local translation/rotation
    // without affecting the rest of the drawing.
    graphics->PushState();

    // Translate by the machine position plus this component's local location.
    graphics->Translate(machinePosition.x + mLocation.x, machinePosition.y + mLocation.y);

    // Convert rotation in turns to radians for wxGraphicsContext
    double rotationRadians = mRotation * 2.0 * M_PI;
    graphics->Rotate(rotationRadians);

    // Draw the polygon at (0,0) since we've already translated
     mImage.DrawPolygon(graphics, 0, 0);

    graphics->PopState();
}

void Component::SetRotation(double rotation)
{
    mRotation = rotation;
}

void Component::SetTime(double time)
{
    mTime = time;
    // In more advanced usage, you might change rotation/location, etc.,
    // based on time here.
}

void Component::SetLocation(wxPoint location)
{
    mLocation = location;
}

void Component::Reset()
{
    // Reset rotation and time to 0 (or any other state)
    mRotation = 0.0;
    mTime = 0.0;
    // You might also reset location to (0,0) if desired, etc.
}