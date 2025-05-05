/**
 * @file MachineDrawable.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef MACHINEDRAWABLE_H
#define MACHINEDRAWABLE_H


// MachineDrawable.h
#pragma once

#include <machine-api.h>    // ONLY MachineLib include
#include "Drawable.h"       // your CE drawable base
///class for mavhine drawable
class MachineDrawable : public Drawable
{
public:

    /**
     *
     */
    virtual ~MachineDrawable() = default;

    MachineDrawable(const std::wstring &resourcesDir, int num);
    /**
     *
     * @param graphics
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    /**
     *
     * @param pt
     * @return
     */
    bool HitTest(wxPoint pt) override;
    /**
     *
     * @param pt
     */
    void OnDoubleClick(wxPoint pt) override;

    /**
     *
     * @param frame
     */
    void SetFrame(int frame) ;
    void SetLocation(wxPoint location);
    void XmlSave(wxXmlNode *node);

    void XmlLoad(wxXmlNode* parent);

private:
    ///resources for rebuild
    std::wstring mResourcesDir;
    /** Emission & physics constants */
    std::shared_ptr<IMachineSystem> mMachine;  // completely hidden
    /** Emission & physics constants */
    wxPoint                         mPosition{0,0};
    /** Emission & physics constants */
    int                             mMachineNumber = 1;
    /** Emission & physics constants */
    int                             mStartFrame    = 0;
    /** Emission & physics constants */
    double                          mFrameRate     = 30.0;
};



#endif //MACHINEDRAWABLE_H
