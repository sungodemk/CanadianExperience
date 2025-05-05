/**
 * @file Machine2Factory.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef MACHINE2FACTORY_H
#define MACHINE2FACTORY_H

#pragma once

#include <memory>
#include <string>
/**
 * class machien
 */
class Machine;
/**
 * class machine
 */
class Machine2Factory
{
public:
    /**
     * Constructor
     * @param resourcesDir Path to the resources directory
     */
    Machine2Factory(std::wstring resourcesDir);
    /**
     * Create machine #2
     * @return shared_ptr to a new Machine instance
     */
    std::shared_ptr<Machine> Create();

private:
    /// Root resources directory passed in
    std::wstring mResourcesDir;

    /// Convenience: resourcesDir + "/images"
    std::wstring mImagesDir;
};



#endif //MACHINE2FACTORY_H
