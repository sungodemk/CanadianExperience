/**
 * @file Machine1Factory.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef MACHINE1FACTORY_H
#define MACHINE1FACTORY_H


class Actor;
/**
 * Machine1Factory
 *
 * An ActorFactory that builds “Machine 1 for the CE system.
 * It simply wraps your MachineDrawable, telling it to use
 * machine #1 under the hood.
 */
class Machine1Factory {
private:
    ///imGES DIR
    std::wstring mImagesDir;
    /**
     * Root resources directory passed in
     */
    std::wstring mResourcesDir;

public:
    /**
     * defult onstrucor
     */
    Machine1Factory() = default;
    /**
     *
     * @param resourcesDir
     */
    Machine1Factory(std::wstring resourcesDir);
    /**
     *
     * @param imagesDir
     * @return
     */
    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};



#endif //MACHINE1FACTORY_H
