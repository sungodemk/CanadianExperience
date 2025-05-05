/**
 * @file Machine.h
 * @author Emmanuel Koshy
 *
 *
 */

#ifndef MACHINE_H
#define MACHINE_H
#include "Component.h"
///class machine
class Machine
{
private:
    /// Machine number
    int mMachineNumber;
    ///Mcomponants
    std::vector<std::shared_ptr<Component>> mComponents;

public:
    /**
     * Constructor
     * @param machineNumber The machine number to set
     */
    Machine(int machineNumber) : mMachineNumber(machineNumber) {}

    /**
    * Get the machine number.
    * @return The machine number.
    */
    int GetMachineNumber() const { return mMachineNumber; }
    /**
     * Add a component to the machine.
     * @param component The component to add.
     */
    void AddComponent(std::shared_ptr<Component> component)
    {
        mComponents.push_back(component);
    }
    /**
     *
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    /**
     *
     * @param time
     */
    void SetTime(double time);
    /**
     *  reset
     */
    void Reset();
};



#endif //MACHINE_H
