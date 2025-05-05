/**
 * @file MachineSystem.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef MACHINESYSTEMDERIVED_H
#define MACHINESYSTEMDERIVED_H

#include "IMachineSystem.h"
#include <memory>
#include <wx/graphics.h>
#include <iostream>
#include <string>
#include "Machine.h"
///class machinesystem
class MachineSystem:public IMachineSystem {


public:
    /** Emission & physics constants */
    int mFrame = 0;
    /** Emission & physics constants */
    double mFrameRate = 30;   // Frames per second (choose a default or set via constructor)
    /** Emission & physics constants */
    double mTime = 0.0;       // Elapsed time in seconds
    /** Emission & physics constants */
    std::wstring mResourceDir;

    /**
     * Reset the machine system to its initial state (time zero).
     * This should reset both frame and time, and any components that need resetting.
     */
    void Reset();

    MachineSystem(std::wstring resourcesDir);

    virtual ~MachineSystem() = default;

    /** Emission & physics constants */
    virtual void SetLocation(wxPoint location) override;
    /** Emission & physics constants */
    virtual wxPoint GetLocation() override;
    /** Emission & physics constants */
    virtual void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
    virtual void SetMachineFrame(int frame) override;
    virtual void SetFrameRate(double rate) override;
    /** Emission & physics constants */
    virtual void ChooseMachine(int machine) override;
    virtual int GetMachineNumber() override;
    /** Emission & physics constants */
    virtual double GetMachineTime() override;
    virtual void SetFlag(int flag) override;

    /**
     * Set the machine number, creating the appropriate machine
     * @param machine Machine number
     */
    virtual void SetMachineNumber(int machine);


private:
    /** Emission & physics constants */
    std::wstring mResourcesDir;
    /** Emission & physics constants */
    std::shared_ptr<Machine> mMachine;
    /** Emission & physics constants */
    wxPoint mLocation;
};



#endif //MACHINESYSTEMDERIVED_H
