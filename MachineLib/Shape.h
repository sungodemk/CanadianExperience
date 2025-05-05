/**
 * @file Shape.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef SHAPE_H
#define SHAPE_H



#include "Component.h"

/**
 * Shape class derived from the Component base class.
 *
 * In your UML this class represents a machine component that has a basic shape.
 * This class adds helper functions to set up specific shapes, such as a rectangle
 * or a circle, by manipulating the underlying Polygon stored in the base Component.
 */
class Shape : public Component
{
public:
    /// Constructor
    Shape();

    /// Destructor
    virtual ~Shape();

    /**
     * Override the Draw method.
     *
     * The base Component::Draw method is called to draw the underlying polygon;
     * Shape can later add extra drawing code if needed.
     *
     * @param graphics Graphics context to draw on.
     * @param machinePosition The overall machine position to offset the drawing.
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition) override;

    /**
     * Configure the shape as a rectangle.
     *
     * This sets the underlying polygon data for a rectangle.
     *
     * @param x The left side X coordinate.
     * @param y The bottom side Y coordinate.
     * @param width The width of the rectangle.
     * @param height The height of the rectangle.
     */
    void Rectangle(double x, double y, double width, double height);

    /**
     * Configure the shape as a circle.
     *
     * This sets the underlying polygon data for a circle.
     *
     * @param radius The circle's radius.
     * @param steps Number of segments to approximate the circle.
     */
    void Circle(double radius, int steps = 32);
    /**
     *
     * @param width
     * @param height
     */
    void BottomCenteredRectangle(double width, double height);
    /**
     *
     * @param filename
     */
    void SetImage(const std::wstring &filename);
    /**
     *
     * @param c
     */
    void SetColor(wxColour c) { mImage.SetColor(c); }
};




#endif //SHAPE_H
