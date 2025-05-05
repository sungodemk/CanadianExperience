/**
 * @file Bubbles.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Bubbles.h"
#include <cmath>

Bubbles::Bubbles(std::wstring imagesDir):
    mImagesDir(imagesDir)
{
    // Seed RNG once
    std::random_device rd;
    mRandom.seed(rd());

    // Prepare one polygon we’ll reuse for every bubble
    mImage.Circle(BubbleRadius, BubbleCircleSteps);
    mImage.SetImage(mImagesDir+L"/bubble.png");  // adjust your path here
}

void Bubbles::Emit(double rotationDelta,
                   const wxPoint2DDouble &origin, bool blowLeft = false)
{
    if(rotationDelta <= 0) return;

    // How many bubbles this frame?
    int count = int(rotationDelta * (BubblePerRotation + RandReal(-BubbleVarPerSec, BubbleVarPerSec)));

    for(int i = 0; i < count; i++)
    {
        // flip by π if blowLeft
        double base = blowLeft ? M_PI : 0.0;
        double ang  = base + RandReal(-AngleVar, AngleVar);

        double dx =  cos(ang);
        double dy =  sin(ang);

        double offset = OffsetBase + RandReal(-OffsetVar, OffsetVar);
        double speed  = RandReal(VelMin,      VelMax);

        Bubble b;
        b.pos = wxPoint2DDouble(origin.m_x + dx * offset,
                                origin.m_y + dy * offset);
        b.vel = wxPoint2DDouble(dx * speed,
                                dy * speed);
        mBubbles.push_back(b);
    }

}

void Bubbles::Update(double dt)
{
    // Advance each bubble
    for(auto &b : mBubbles)
    {
        // gravity
        b.vel.m_y += Gravity * dt;
        // move
        b.pos.m_x += b.vel.m_x * dt;
        b.pos.m_y += b.vel.m_y * dt;
    }

    // Cull any that fall off the bottom of the window
    // Assume window height of 600px (or replace with your actual height)

    mBubbles.erase(
      std::remove_if(
        mBubbles.begin(), mBubbles.end(),
        [&](auto &b) { return b.pos.m_y - BubbleRadius > 800; }
      ),
      mBubbles.end()
    );
}

void Bubbles::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for(auto &b : mBubbles)
    {
        // Draw our single‐bubble polygon at b.pos
        mImage.DrawPolygon(graphics, b.pos.m_x, b.pos.m_y);
    }
}