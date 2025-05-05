/**
 * @file Shape.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Shape.h"
// Constructor
Shape::Shape()
{
    // Additional initialization for Shape can be added here.
}

// Destructor
Shape::~Shape()
{
}

// Override Draw - here we simply call the base Component draw.
// You could add additional drawing (for example, a border or other embellishments) if desired.
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition)
{
    // Call the base class draw which uses the underlying Polygon (mImage)
    Component::Draw(graphics, machinePosition);

    // Additional drawing code specific to Shape could be added here.
}

// Configures the underlying polygon as a rectangle.
// This simply delegates to the Polygon method.
void Shape::Rectangle(double x, double y, double width, double height)
{
    // The base class Component stores the shape as a Polygon in mImage.
    mImage.Rectangle(x, y, width, height);
}

// Configures the underlying polygon as a circle.
// Delegates to the Polygon::Circle method.
void Shape::Circle(double radius, int steps)
{
    mImage.Circle(radius, steps);
}

// Configures the underlying polygon as a bottom-centered rectangle.
void Shape::BottomCenteredRectangle(double width, double height)
{
    mImage.BottomCenteredRectangle(width, height);
}

void Shape::SetImage(const std::wstring& filename)
{
    // mImage is inherited from Component (or could be directly in Shape if defined there)
    mImage.SetImage(filename);
}
