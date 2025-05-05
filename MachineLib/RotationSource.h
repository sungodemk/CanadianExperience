/**
 * @file RotationSource.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef ROTATIONSOURCE_H
#define ROTATIONSOURCE_H


#include <vector>

// Forward declaration of RotationSink.
class RotationSink;

/**
 * RotationSource
 *
 * Provides a rotation value (in turns, where 1.0 equals 360°) that is pushed to its sink.
 * Copy constructor and assignment operator are disabled.
 */
class RotationSource {
public:
    RotationSource();
    ~RotationSource();

    // Disable copy constructor and assignment operator.
    RotationSource(const RotationSource &) = delete;
    RotationSource& operator=(const RotationSource &) = delete;

    /**
     * Connect a rotation sink to this source.
     * @param sink Pointer to the RotationSink to drive.
     */
    void SetSink(RotationSink* sink);

    /**
     * Drive the connected sink with the given rotation.
     * @param rotation Rotation (in turns) to drive.
     */
    void Drive(double rotation);
    /** add sinkptr */
    void AddSink(RotationSink *sink);

private:
    double mRotation;          ///< Current rotation in turns.
    std::vector<RotationSink*> mSinks;      ///< Connected sink (if any).
};




#endif //ROTATIONSOURCE_H
