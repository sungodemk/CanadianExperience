/**
 * @file RotationSink.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef ROTATIONSINK_H
#define ROTATIONSINK_H
#include "Component.h"
#include "RotationSource.h"

/**
 * RotationSink
 *
 * Concrete class used to drive a Component’s rotation.
 * It stores a pointer to the target Component and, when driven,
 * calls SetRotation on that Component.
 * Copy and assignment are disabled.
 */
class RotationSink {
public:
    /**
     * Constructor.
     * @param connection Pointer to the Component this sink drives.
     */
    RotationSink(Component* connection);

    ~RotationSink();

    // Disable copy constructor and assignment operator.
    RotationSink(const RotationSink &) = delete;
    RotationSink& operator=(const RotationSink &) = delete;

    /**
     * Called by a RotationSource to set a new rotation.
     * @param rotation Rotation (in turns, where 1.0 = 360°).
     */
    void SetRotation(double rotation);

    /**
     * Connect this sink to a RotationSource.
     * @param source Pointer to the source that will drive this sink.
     */
    void SetDriven(RotationSource* source);

private:
    Component* mConnection;    ///< The component to drive.
};




#endif //ROTATIONSINK_H
