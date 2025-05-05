/**
 * @file Pulley.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Pulley.h"
#include "RotationSource.h"
#include "RotationSink.h"
/**
 *
 *
 * @param imagesDir
 */
Pulley::Pulley(double radius, std:: wstring imagesDir)
    : mRadius(radius)
    , mSink(this)// Initialize mSink with this Component (Pulley) as the connection.
    ,mImagesDir(imagesDir)
{
    mImage.Circle(mRadius, 42);

    if (radius >= 30.0) {
        mImage.SetImage(mImagesDir+L"/pulley4.png"); // Large
    } else {
        mImage.SetImage(mImagesDir+L"/pulley2.png"); // Small
    }
}

void Pulley::SetRotation(double rotation)
{
    // 1) Spin this pulley
    mRotation = rotation;
    mImage.SetRotation(rotation);
    mSource.Drive(rotation);

    // 2) Now drive every belt child
    for (auto &child : mBeltChildren)
    {
        // If you want speed scaling by radius:
        double ratio = mRadius / child->GetRadius();
        child->SetRotation(rotation * ratio);
    }
}

void Pulley::Draw(std::shared_ptr<wxGraphicsContext> graphics, wxPoint machinePosition)
{
    // 1) Compute this pulley’s center in screen coords
    wxPoint p1 = machinePosition + mLocation;

    // 2) For each belt‐connected child pulley…
    for (auto &child : mBeltChildren)
    {
        // 2a) Get child center and radii (inset by 3 px)
        wxPoint p2 = machinePosition + child->GetLocation();
        double r1 = mRadius - 3.0;
        double r2 = child->GetRadius() - 3.0;

        // 2b) Delta & distance
        double dx   = p2.x - p1.x;
        double dy   = p2.y - p1.y;
        double dist = std::hypot(dx, dy);
        if (dist <= std::abs(r2 - r1))
        {
            // pulleys too close or concentric; skip belt
            continue;
        }

        // 2c) Angles
        double theta = std::atan2(dy, dx);            // center‐to‐center angle
        double phi   = std::asin((r2 - r1) / dist);   // tangent offset

        // two tangent directions
        double beta1 = theta + phi + M_PI/2.0;
        double beta2 = theta - phi - M_PI/2.0;

        // 2d) Compute the four tangent points
        wxPoint s1(int(p1.x + r1 * cos(beta1)),
                   int(p1.y + r1 * sin(beta1)));
        wxPoint e1(int(p2.x + r2 * cos(beta1)),
                   int(p2.y + r2 * sin(beta1)));
        wxPoint s2(int(p1.x + r1 * cos(beta2)),
                   int(p1.y + r1 * sin(beta2)));
        wxPoint e2(int(p2.x + r2 * cos(beta2)),
                   int(p2.y + r2 * sin(beta2)));

        // 2e) Draw the two belt edges behind the pulley
        graphics->PushState();
        wxPen beltPen(*wxBLACK, 2);
        graphics->SetPen(beltPen);
        graphics->StrokeLine(s1.x, s1.y, e1.x, e1.y);
        graphics->StrokeLine(s2.x, s2.y, e2.x, e2.y);
        graphics->PopState();
    }

    // 3) Finally, draw *this* pulley on top of all belts
    Component::Draw(graphics, machinePosition);
}

void Pulley::Drive(std::shared_ptr<Pulley> pulley)
{
    mBeltChildren.push_back(pulley);
}

void Pulley::SetChild(std::shared_ptr<Pulley> child)
{
    mChild = child;

    // Set the child's sink to this pulley’s source so it receives the same rotation
    mSource.SetSink(child->GetSink());
}
