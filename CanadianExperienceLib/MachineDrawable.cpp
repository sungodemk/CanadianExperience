/**
 * @file MachineDrawable.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "MachineDrawable.h"
#include <machine-api.h>
#include <wx/numdlg.h>
/**
 *
 * @param resourcesDir
 * @param num
 */
MachineDrawable::MachineDrawable(const std::wstring& resourcesDir, int num): Drawable(resourcesDir),mPosition(200, 450)
{
    // keep only the IMachineSystem
    MachineSystemFactory factory(resourcesDir);
    mMachine = factory.CreateMachineSystem();
    mMachine->SetFrameRate(mFrameRate);
    mMachine ->ChooseMachine(num);
}
/**
 *
 * @param graphics
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double scale = 0.75f;

    graphics->PushState();
    graphics->Translate(mPosition.x, mPosition.y);

    // Tell the machine to draw itself at its own origin
    mMachine->SetLocation(wxPoint(0,0));
    mMachine->DrawMachine(graphics);

    graphics->PopState();
}
///hittest
bool MachineDrawable::HitTest(wxPoint pos)
{

    // Transform to local coords
    wxPoint local = pos - mPosition;

    //  (tweak width/height as needed)
    wxRect bounds(-200, -150, 400, 300);
    return bounds.Contains(local);
}
/**
 *
 */
void MachineDrawable::OnDoubleClick(wxPoint)
{
    // 1) Let user pick machine 1 or 2
    MachineDialog dlg(wxTheApp->GetTopWindow(), mMachine);
    if (dlg.ShowModal() != wxID_OK) return;
    mMachineNumber = mMachine->GetMachineNumber();

    // 2) Let user pick start‐frame
    long f = wxGetNumberFromUser(
      L"Start at frame:", L"Frame:", L"Machine Start",
      mStartFrame, 0, 10000, wxTheApp->GetTopWindow());
    if (f != -1) mStartFrame = (int)f;
}
/**
 *
 * @param frame
 */
void MachineDrawable::SetFrame(int frame)
{
    // Idle until start
    if (frame < mStartFrame) return;
    mMachine->SetMachineFrame(frame - mStartFrame);
}
/**
 *
 * @param pos
 */
void MachineDrawable::SetLocation(wxPoint pos)
{
    mPosition = pos;
}
/**
 *
 * @param node
 */
void MachineDrawable::XmlSave(wxXmlNode* node)
{
    node->AddAttribute(L"startframe", std::to_wstring(mStartFrame));
    node->AddAttribute(L"machinenumber", std::to_wstring(mMachineNumber));
}

/**
 *
 * @param node
 */
void MachineDrawable::XmlLoad(wxXmlNode* node)
{
    long startFrame = 0;
    node->GetAttribute(L"startframe", L"0").ToLong(&startFrame);
    mStartFrame = (int)startFrame;

    long machineNumber = 1;
    node->GetAttribute(L"machinenumber", L"1").ToLong(&machineNumber);
    mMachineNumber = (int)machineNumber;

    // Rebuild the machine after loading
    MachineSystemFactory factory(mResourcesDir);
    mMachine = factory.CreateMachineSystem();
    mMachine->SetFrameRate(mFrameRate);
    mMachine->ChooseMachine(mMachineNumber);
}