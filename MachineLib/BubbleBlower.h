/**
 * @file BubbleBlower.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef BUBBLEBLOWER_H
#define BUBBLEBLOWER_H


#pragma once

#include "Component.h"
#include "RotationSink.h"
#include "Bubbles.h"

/**
 * A BubbleBlower is a Component that accepts rotation but
 * does not rotate itself—rather it emits bubbles.
 */
class BubbleBlower : public Component
{
public:
    BubbleBlower(std::wstring imagesDir);
    virtual ~BubbleBlower() = default;

    /**
     * Set the animation time for the bubble blowero
     * @param rotation The current animation time.
     * This method updates the time-dependent state of the bubble blower, including spawning and managing bubbles.
     */
    virtual void SetRotation(double rotation) override;

    /// Draw the blower graphic + its bubbles
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition) override;
    void Reset() override;

    /**
     * Set the animation time for the bubble blower.
     * []
     *
     * This method updates the time-dependent state of the bubble blower, including spawning and managing bubbles.
     */
    void SetTime(double time) override;

    /**
     * Expose our rotation sink so sources can hook to us.
     * @return &mSink Pointer to the RotationSink for this component.
     *
     * Allows other components to drive this blower by providing rotation input.
     */
    RotationSink *GetSink() { return &mSink; }

    /**
     * Set the direction of the bubble spray.
     * @param left If true, spray bubbles to the left; otherwise to the right.
     *
     * Changes the direction in which bubbles are emitted.
     */
    void SetBlowLeft(bool left) { mBlowLeft = left; }

    /**
     * Set the direction of the bubble spray.
     * @param o If true, spray bubbles to the left; otherwise to the right.
     *
     * Changes the direction in which bubbles are emitted.
     */
    void SetSpawnOffset(wxPoint2DDouble o) { mSpawnOffset = o; }




private:
    /** Gravity acceleration applied to bubbles (pixels/s²) */
    double mLastTime = 0.0;
    /**
     * images member
     */
    std::wstring mImagesDir;
    /**
     * spawn offset member
     */
    wxPoint2DDouble mSpawnOffset{0,0};
    /**
     * blow bubble left
     */
    bool mBlowLeft = false;
    /* time */
    RotationSink mSink{this};   ///< Receives rotation//* time */
    /* time */
    Bubbles mBubbles;      ///< Manages bubble particles
    /* time */
    double mLastRotation = 0.0; ///< For computing delta
    /**
     * blow bubble left
     */
    double mCurrentRotation = 0.0;
    /**
     * blow bubble left
     */
    wxPoint mMachinePosition{0, 0};
};



#endif //BUBBLEBLOWER_H
