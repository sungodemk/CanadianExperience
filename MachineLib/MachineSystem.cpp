/**
 * @file MachineSystem.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "MachineSystem.h"

#include "Machine2Factory.h"
#include "MachineCFactory.h"
/**
 *
 * @param resourcesDir
 */
MachineSystem::MachineSystem(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{
    SetMachineNumber(1);
    std::cout<<mResourcesDir<<std::endl;
}
/**
 *
 * @param location
 */
void MachineSystem::SetLocation(wxPoint location)
{
    mLocation = location;
    std::cout << "MachineSystem::SetLocation called" << std::endl;
}
/**
 *
 * @return mLocation
 */
wxPoint MachineSystem::GetLocation()
{
    std::cout << "MachineSystem::GetLocation called" << std::endl;
    return mLocation;
}
/**
 *
 * @param graphics
 */
void MachineSystem::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    // This will put the machine where it is supposed to be drawn
    graphics->PushState();
    graphics->Translate(mLocation.x, mLocation.y);

    mMachine->Draw(graphics);

    graphics->PopState();
}
/**
 *
 * @param frame
 */
void MachineSystem::SetMachineFrame(int frame)
{
    if (frame < mFrame)
    {
        mFrame = 0;
        Reset();
    }

    while (mFrame < frame) {
        mFrame++;
        mTime = mFrame / mFrameRate;
        mMachine->SetTime(mTime);
    }
}

/**
 *
 * @param rate
 */
void MachineSystem::SetFrameRate(double rate)
{
    mFrameRate = rate;
    std::cout << "MachineSystem::SetFrameRate called with rate " << rate << std::endl;
}
/**
 *
 * @param machine
 */
void MachineSystem::ChooseMachine(int machine)
{
    std::cout << "MachineSystem::ChooseMachine called with machine " << machine << std::endl;
    // 1) Recreate the selected machine
    SetMachineNumber(machine);

    // 2) Reset timing/state so the new machine starts fresh
    Reset();
}

/**
 *
 * @return
 */
int MachineSystem::GetMachineNumber()
{
    if(mMachine)
    {
        return mMachine->GetMachineNumber();
    }
    return 0;
}
/**
 *
 * @return
 */
double MachineSystem::GetMachineTime()
{
    std::cout << "MachineSystem::GetMachineTime called" << std::endl;
    return mTime;
}
/**
 *
 * @param flag
 */
void MachineSystem::SetFlag(int flag)
{
    std::cout << "MachineSystem::SetFlag called with flag " << flag << std::endl;
}

/**
 * Set the machine number, creating the appropriate machine
 * @param machine Machine number
 */
void MachineSystem::SetMachineNumber(int machine)
{
    if(machine == 1)
    {
        // Use MachineCFactory to create machine 1.
        // mResourcesDir is assumed to be a member variable that stores the resource directory,
        // which should have been passed down via the MachineSystem constructor
        MachineCFactory factory(mResourcesDir);
        mMachine = factory.Create(); //
    }
    else if (machine == 2) {
        Machine2Factory factory(mResourcesDir);
        mMachine = factory.Create();
    }
}
/**
 * reset
 */
void MachineSystem::Reset()
{
    mFrame = 0;
    mTime = 0.0;
    if (mMachine)
    {
        mMachine->Reset();
    }
}