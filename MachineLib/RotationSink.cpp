/**
 * @file RotationSink.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "RotationSink.h"
#include "RotationSource.h"

RotationSink::RotationSink(Component* connection)
    : mConnection(connection)
{
}

RotationSink::~RotationSink()
{
}

void RotationSink::SetRotation(double rotation)
{
    if (mConnection)
    {
        mConnection->SetRotation(rotation);
    }
}

void RotationSink::SetDriven(RotationSource* source)
{
    // Connect this sink to the source.
    source->SetSink(this);
}