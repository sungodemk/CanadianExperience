/**
 * @file Bubbles.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef BUBBLES_H
#define BUBBLES_H


#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <wx/graphics.h>
#include "Polygon.h"

/**
 * A simple particle system of soap bubbles.
 */
class Bubbles
{
public:
    /**
     *
     * @param imagesDir
     */
    Bubbles(std::wstring imagesDir);
    /**
     * Emit new bubbles based on how much rotation has occurred.
     * @param rotationDelta Amount of new turns since last emit.
     * @param origin World‐space point where bubbles should be born.
     * @param blowLeft
     */
    void Emit(double rotationDelta, const wxPoint2DDouble &origin, bool blowLeft);
    virtual ~Bubbles() = default;




    /**
     * Advance all existing bubbles by deltaTime seconds (gravity & motion).
     * @param dt Seconds since last advance.
     */
    void Update(double dt);

    /**
     * Draw all active bubbles. The graphics context should already
     * be in world‐space.
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    ///clears the thing out
    void Clear() { mBubbles.clear(); }

private:
    ///images dir
    std::wstring mImagesDir;
    /**
     * Draw all active bubbles. The graphics context should already
     * be in world‐space.
     *
     */
    struct Bubble
    {   /** Emission & physics constants */
        wxPoint2DDouble pos;
        /** Emission & physics constants */
        wxPoint2DDouble vel;
    };
    /** Emission & physics constants */
    std::vector<Bubble> mBubbles;
    /** Emission & physics constants */
    cse335::Polygon     mImage;    // single bubble graphic
    /** Emission & physics constants */
    std::mt19937        mRandom;   // RNG engine

    /** Gravity acceleration applied to bubbles (pixels/s²) */
    static constexpr double Gravity            = 2;   // px/s²
    /** Emission & physics constants */
    static constexpr double BubblePerRotation  = 5.0;
    /** Emission & physics constants */
    static constexpr double BubbleVarPerSec    = 50.0;
    /** Emission & physics constants */
    static constexpr double AngleVar           = 0.1;
    /** Emission & physics constants */
    static constexpr double MachAngleRange     = 0.25;
    /** Emission & physics constants */
    static constexpr double OffsetBase         = 100.0;
    /** Emission & physics constants */
    static constexpr double OffsetVar          = 5.0;
    /** Emission & physics constants */
    static constexpr double VelMin             = 20.0;
    /** Emission & physics constants */
    static constexpr double VelMax             = 40.0;
    /** Emission & physics constants */
    static constexpr int    BubbleRadius       = 20;
    /** Emission & physics constants */
    static constexpr int    BubbleCircleSteps  = 32;

    /**
     * Generate a uniformly distributed real number in [a, b].
     * @param a Lower bound
     * @param b Upper bound
     * @return Random real in [a, b]
     */
    double RandReal(double a, double b)
    {
        std::uniform_real_distribution<> dist(a, b);
        return dist(mRandom);
    }
};



#endif //BUBBLES_H
