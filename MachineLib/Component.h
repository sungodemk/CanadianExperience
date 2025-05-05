/**
 * @file Component.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef COMPONENT_H
#define COMPONENT_H

#include <wx/graphics.h>
#include <wx/gdicmn.h>    // for wxPoint
#include "Polygon.h"
#include <memory>

/**
 * Base class for machine components.
 *
 * In the UML:
 *   rotation : double
 *   location : Point = Point(0,0)
 *   image : Polygon
 *   Methods: Draw(graphics, machinePosition), SetRotation(double),
 *            SetTime(double), SetLocation(point), Reset()
 */
class Component
{
public:
    Component();
    virtual ~Component();

    /**
     * Draw the component, offset by the machine position.
     * @param graphics The graphics context to draw on
     * @param machinePosition The position of the "machine" overall
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition);

    /**
     * Set the rotation (in turns, i.e., 1.0 = 360 degrees).
     * @param rotation Rotation in turns
     */
    virtual void SetRotation(double rotation);

    /**
     * Set the current animation time for this component.
     * @param time The current time in some time units (e.g., frames, seconds)
     */
    virtual void SetTime(double time);

    /**
     * Set the relative location of this component.
     * @param location The new location
     */
    virtual void SetLocation(wxPoint location);

    /**
     * Reset the component to its initial state.
     * (e.g., rotation = 0, time = 0, or anything else you need)
     */
    virtual void Reset();

    /**
     * Get the current rotation.
     * @return The rotation in turns
     */
    double GetRotation() const { return mRotation; }

    /**
     * Get the current location.
     * @return The component's location
     */
    wxPoint GetLocation() const { return mLocation; }

protected:
    /// A shape for this component (from Polygon.h).
    /// The UML calls this "image," but it's effectively a polygon or shape
    cse335::Polygon mImage;
    /// Rotation in turns (1.0 = 360 degrees)
    double mRotation = 0.0;

    /// Current location, relative to the machine’s position
    wxPoint mLocation = wxPoint(0, 0);



    /// Current time for animation or other updates
    double mTime = 0.0;
private:

};




#endif //COMPONENT_H
