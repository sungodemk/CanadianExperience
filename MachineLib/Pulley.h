/**
 * @file Pulley.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef PULLEY_H
#define PULLEY_H

#include "Component.h"
#include "RotationSink.h"
#include <wx/graphics.h>
#include <memory>
#include "RotationSource.h"

/**
 * Pulley
 *
 * A Pulley is a Component that acts as a rotation sink.
 * It overrides SetRotation to update its rotation value, and it owns a RotationSink.
 */
class Pulley : public Component
{
public:
    /**
     * Constructor.
     * @param radius The radius of the pulley.
     */
    Pulley(double radius,std::wstring imagesDir);

    virtual ~Pulley() = default;

    // Disable copy and assignment.
    Pulley(const Pulley&) = delete;
    Pulley& operator=(const Pulley&) = delete;

    /**
     * Set the rotation for the pulley (in turns).
     * @param rotation Rotation value (1.0 equals 360°).
     */
    void SetRotation(double rotation) override;

    /**
     * Draw the pulley.
     * @param graphics Graphics context.
     * @param machinePosition Machine’s origin for translation.
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition) override;
    /**
     *
     * @param pulley
     */
    void Drive(std::shared_ptr<Pulley> pulley);
    /**
     *
     * @param child
     */
    void SetChild(std::shared_ptr<Pulley> child);

    /**
     * Get a pointer to this pulley's RotationSink.
     * @return Pointer to RotationSink.
     */
    RotationSink* GetSink() { return &mSink; }

    /**
     * Get the pulley's radius.
     * @return The radius.
     */
    double GetRadius() const { return mRadius; }

    /**
 * Get a pointer to this pulley’s RotationSource
 * @return Pointer to the RotationSource
 */
    RotationSource* GetSource() { return &mSource; }

private:
    /** Emission & physics constants */
    std::wstring mImagesDir;
    /** Emission & physics constants */
    double mRadius;
    /** Emission & physics constants */
    RotationSink mSink; // Composition: this pulley “has a” RotationSink.
    /** Emission & physics constants */
    RotationSource mSource;               // Rotation source for connected child
    /** Emission & physics constants */
    std::shared_ptr<Pulley> mChild;       // The smaller pulley in the center
    /** Emission & physics constants */
    std::vector<std::shared_ptr<Pulley>> mBeltChildren;
};



#endif //PULLEY_H
