/**
 * @file PictureFactory.cpp
 *
 * @author Charles Owen
 * @author Anik Momtaz
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "Machine1Factory.h"
#include "Machine2CEfactory.h"
#include "MachineDrawable.h"

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";


/**
 * Factory method to create a new picture.
 * @param resourcesDir Directory that contains the resources for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring resourcesDir)
{
    auto imagesDir = resourcesDir + ImagesDirectory;

    auto picture = std::make_shared<Picture>();

    // Create the background and add it
    auto background = std::make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            std::make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background2.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    //mqchines
    // 1) Create the actor (give it a name, but you don't have to position it)
    auto actor1 = std::make_shared<Actor>(L"Machine 1");

    // 2) Create and position the drawable _inside_ that actor:
    auto machine1 = std::make_shared<MachineDrawable>(resourcesDir, 1);
    machine1->SetLocation(wxPoint(300-100,300+200));   // <- this moves the machine
    actor1->AddDrawable(machine1);

    // 3) Add the actor to the picture
    picture->AddActor(actor1);

    auto actor2 = std::make_shared<Actor>(L"Machine 2");
    auto machine2 = std::make_shared<MachineDrawable>(resourcesDir, 2);
    machine2->SetLocation(wxPoint(600+200,320+200));   // <- this moves machine 2
    actor2->AddDrawable(machine2);
    picture->AddActor(actor2);

    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(150, 600));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(650, 620));
    picture->AddActor(sparty);




     return picture;
}

