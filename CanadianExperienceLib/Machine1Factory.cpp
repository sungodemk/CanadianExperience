/**
 * @file Machine1Factory.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Machine1Factory.h"
#include "Actor.h"
#include "MachineDrawable.h"

Machine1Factory::Machine1Factory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    // Since resourcesDir already includes "/images", don't append it again
    mImagesDir = mResourcesDir;
}

std::shared_ptr<Actor> Machine1Factory::Create(std::wstring imagesDir)
{

    std::shared_ptr<Actor> actor = std::make_shared<Actor>(L"Machine 1");

    auto machineDrawable = std::make_shared<MachineDrawable>(imagesDir,1);


    actor->AddDrawable(machineDrawable);

    return actor;

}

