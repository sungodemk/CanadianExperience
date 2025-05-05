/**
 * @file BubbleBlower.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "BubbleBlower.h"
/**
 *
 * @param imagesDir
 */
BubbleBlower::BubbleBlower(std::wstring imagesDir): mImagesDir(imagesDir), mBubbles(imagesDir)
{
    // Define the static shape of the blower (bottom‐centered)
    // so Component::Draw will put it in the right spot.
    mImage.Rectangle(-25, 10, 50, 150); // match your blower png size
    mImage.SetImage(mImagesDir + L"/blower.png"); // adjust path
}
/**
    * Set the animation time for the bubble blowero
    * @param rotation The current animation time.
    * This method updates the time-dependent state of the bubble blower, including spawning and managing bubbles.
    */
void BubbleBlower::SetRotation(double rotation)
{
    mCurrentRotation = rotation;
}
/**
 * 
 * @param graphics
 * 
 * @param machinePosition 
 */
void BubbleBlower::Draw(std::shared_ptr<wxGraphicsContext> graphics,
                        wxPoint machinePosition)
{
    // 0) Update our stored machinePosition
    mMachinePosition = machinePosition;

    // 1) Compute how many turns just happened
    //    (we already stored mLastRotation in SetRotation,
    //     but let's compute delta one more time here)
    double delta = mCurrentRotation - mLastRotation;
    if(delta < 0) delta = 0;
    mLastRotation = mCurrentRotation;

    // 2) Compute spawn origin—center of the blower polygon in world space
    auto localCenter = mImage.Center();
    wxPoint2DDouble worldOrigin(
        mMachinePosition.x + mLocation.x + localCenter.m_x + mSpawnOffset.m_x,
        mMachinePosition.y + mLocation.y + localCenter.m_y + mSpawnOffset.m_y
    );

    // 3) Emit new bubbles from *that* exact point
    mBubbles.Emit(delta, worldOrigin, mBlowLeft);



    // 5) Advance & draw bubbles
    constexpr double dt = 1.0/30.0;
    mBubbles.Update(dt);
    graphics->PushState();
    graphics->Translate(machinePosition.x, machinePosition.y);
    mBubbles.Draw(graphics);
    graphics->PopState();

    //) Now draw the blower graphic
    Component::Draw(graphics, machinePosition);
}
/**
 * Reset the blower: clear any accumulated bubbles, reset time.
 */
void BubbleBlower::Reset()
{
    // Reset the Component base (sets time, rotation, etc.)
    Component::Reset();

    // 2) Clear all bubbles
    mBubbles.Clear();

    mLastRotation = 0.0;


}

/**
 *
 * @param time
 */
void BubbleBlower::SetTime(double time)
{
    // 1) How much wall‐clock time has passed since last call?
    double dt = time - mLastTime;
    if (dt < 0) dt = 0;
    mLastTime = time;

    // 2) Advance bubble physics
    mBubbles.Update(dt);

    // 3) How much did we rotate since last emission?
    double deltaRot = mCurrentRotation - mLastRotation;
    if (deltaRot < 0) deltaRot = 0;  // clamp on rewind
    mLastRotation = mCurrentRotation;

    // 4) Compute spawn origin (with any offsets)
    auto c = mImage.Center();
    wxPoint2DDouble origin(
      mMachinePosition.x + mLocation.x + c.m_x + mSpawnOffset.m_x,
      mMachinePosition.y + mLocation.y + c.m_y + mSpawnOffset.m_y
    );

    // 5) Emit new bubbles
    mBubbles.Emit(deltaRot, origin, mBlowLeft);
}
