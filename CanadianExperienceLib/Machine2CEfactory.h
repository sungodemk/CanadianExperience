/**
 * @file Machine2CEfactory.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef MACHINE2CEFACTORY_H
#define MACHINE2CEFACTORY_H


#pragma once

#include "Actor.h"


/**
 * Machine2CEFactory
 *
 * An ActorFactory that builds “Machine 2” for the CE system.
 * It simply wraps your MachineDrawable, telling it to use
 * machine #2 under the hood.
 */
class Machine2CEFactory
{
private:
    /**
     * images dir
     */
    std::wstring mImagesDir;
    /**
     * resouces dir
     */
    std::wstring mResourcesDir;
public:
    // Default constructor (for PictureFactory)
    Machine2CEFactory() {}

    Machine2CEFactory(std::wstring resourcesDir);
    /** Build a new Actor named “Machine 2” */
    std::shared_ptr<Actor> Create(std::wstring imagesDir) ;
};


#endif //MACHINE2CEFACTORY_H
