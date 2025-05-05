/**
 * @file Machine.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Machine.h"

void Machine::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    for (auto& component : mComponents)
    {
        component->Draw(graphics, wxPoint(0, 0));
    }
}
void Machine::SetTime(double time)
{
    // Pass time to each component
    for (auto& component : mComponents)
    {
        component->SetTime(time);
    }
}

void Machine::Reset()
{
    // Reset each component
    for (auto& component : mComponents)
    {
        component->Reset();
    }
}