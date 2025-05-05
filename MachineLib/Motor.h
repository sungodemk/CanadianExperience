/**
 * @file Motor.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef MOTOR_H
#define MOTOR_H



#include "Component.h"
#include "Polygon.h"
#include <string>
#include <memory>
#include <wx/graphics.h>

#include "RotationSource.h"

/**
 * Motor class derived from Component.
 *
 * This class uses the inherited polygon (mImage) from Component as the shaft.
 * It also has an additional Polygon member (mBody) for the motor body.
 * The Draw function is overridden so that it upcalls the base Component draw
 * (drawing the shaft) and then draws the motor body.
 */
class Motor : public Component
{
public:
    /**
     * Constructor.
     * @param imagesDir Directory to load images from.
     */
    Motor(std::wstring imagesDir);

    /**
     * Destructor.
     */
    virtual ~Motor();

    /**
     *
     * @param filename
     */
    void SetImage(const std::wstring& filename);

    /**
     * Draw the motor.
     * First upcalls the Component::Draw to draw the shaft; then draws the motor body.
     * @param graphics Graphics context to draw on.
     * @param machinePosition The overall machine position (for relative transforms).
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition) override;
    /**
     *
     * @param time
     */
    void SetTime(double time) override;

    /**
     * Get a pointer to the rotation source for this component.
     * @return Pointer to the RotationSource object.
     */
    RotationSource* GetSource() { return &mSource; }


private:
    /** Emission & physics constants */
    cse335::Polygon mImage;
    /** Emission & physics constants */
    std::wstring mImagesDir;
    /// Rotation source for this component.
    RotationSource mSource;
    /// Polygon for the body of the motor.
    cse335::Polygon mBody;
};



#endif //MOTOR_H
