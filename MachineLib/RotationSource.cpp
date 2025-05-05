/**
 * @file RotationSource.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "RotationSource.h"
#include "RotationSink.h"

RotationSource::RotationSource()
{
}

RotationSource::~RotationSource()
{
}

void RotationSource::SetSink(RotationSink* sink)
{
    // Throw away any previous connections
    mSinks.clear();
    if (sink) mSinks.push_back(sink);
}
/**
 *
 * @param sink
 */
void RotationSource::AddSink(RotationSink* sink)
{
    // Append a new connection
    if (sink) mSinks.push_back(sink);
}

void RotationSource::Drive(double rotation)
{
    mRotation = rotation;
    // Push the rotation into every registered sink
    for (auto s : mSinks)
    {
        if (s) s->SetRotation(mRotation);
    }
}

