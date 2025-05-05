/**
 * @file Machine2CEfactory.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"

#include "Machine2CEfactory.h"
#include "Actor.h"
#include "MachineDrawable.h"
/**
 *
 * @param resourcesDir
 */
Machine2CEFactory::Machine2CEFactory(std::wstring resourcesDir) :
    mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir;
}
/**
 *
 * @param imagesDir
 * @return
 */
std::shared_ptr<Actor> Machine2CEFactory::Create(std::wstring imagesDir)
{
    std:: shared_ptr<Actor> actor = std::make_shared<Actor>(L"Machine 2");

    std::shared_ptr<MachineDrawable> drawable = std::make_shared<MachineDrawable>(imagesDir,2);

    actor->AddDrawable(drawable);

    return actor;

}


