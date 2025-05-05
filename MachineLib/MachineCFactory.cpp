/**
 * @file MachineCFactory.cpp
 *
 * @author Anik Momtaz, Emmaunel Koshy
 */

#include "pch.h"
#include "MachineCFactory.h"

#include "BubbleBlower.h"
#include "Flag.h"
#include "Machine.h"
#include "Motor.h"
#include "Pulley.h"
#include "Shape.h"


/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 */
MachineCFactory::MachineCFactory(std::wstring resourcesDir) :
        mResourcesDir(resourcesDir)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
}

/**
 * Factory method to create machine
 * @return
 */
std::shared_ptr<Machine> MachineCFactory::Create()
{
    // The machine itself
    auto machine = std::make_shared<Machine>(1);

    const int BaseWidth = 325;  // Width of the base
    const int BaseHeight = 40;  // Height of the base
    const int PostWidth = 15;
    const int RightPostHeight = 130; // Normal height for left post
    const int LeftPostHeight = 200; // Taller right post


    const int MotorX = 20;	// Motor X location

    //
    // The base
    //
    auto base = std::make_shared<Shape>();

    base->Rectangle(int(-BaseWidth/2), 0, BaseWidth, BaseHeight);
    base->SetImage(mImagesDir+ L"/base.png");

    machine->AddComponent(base);

    // Add vertical post on the left
    auto post1 = std::make_shared<Shape>();
    post1->BottomCenteredRectangle(PostWidth, LeftPostHeight);
    post1->SetImage(mImagesDir+ L"/post.png");
    post1->SetLocation(wxPoint(-110, -37)); // Adjust X/Y based on position and image size
    machine->AddComponent(post1);

    // Add vertical post on the right
    auto post2 = std::make_shared<Shape>();
    post2->BottomCenteredRectangle(PostWidth, RightPostHeight);
    post2->SetImage(mImagesDir+ L"/post.png");
    post2->SetLocation(wxPoint(110, -37)); // Adjust position for right post
    machine->AddComponent(post2);


    //
    // The platform sits atop post1, behind the pulley
    //
    auto platform = std::make_shared<Shape>();
    // Make a rectangle the same size as your platform.png
    // (or let the image drive the size by passing 0,0)
    platform->Rectangle(-100, 0, 250, 30);
    platform->SetImage(mImagesDir+ L"/platform.png");
    // Position it so its bottom edge sits on top of the post
    // post1 is at (-110,-37) with height = LeftPostHeight
    // so top of post is at y = -37 - LeftPostHeight
    int platformX = -135;                                 // aligned to post
    int platformY = -37 - LeftPostHeight;                 // top of post
    platform->SetLocation(wxPoint(platformX, platformY));
    machine->AddComponent(platform);
    // now add the vertical overlay on top of it:
    auto upright = std::make_shared<Shape>();
    upright->Rectangle(-5, 0, 15, 30);
    upright->SetColor(*wxBLACK);

    // center it on the 250px platform:
    int centerX = platformX + 125;
    upright->SetLocation(wxPoint(centerX, platformY - 27));
    machine->AddComponent(upright);




    //
    // The motor
    //
    auto motor =  std::make_shared<Motor>(mImagesDir);
    motor->SetImage(mImagesDir+ L"/motor3.png");
    motor->SetLocation(wxPoint(20, -80));

    machine->AddComponent(motor);

    //
    // The pulley
    //
    // Create a pulley with a desired radius (e.g., 15)
    auto pulley2 = std::make_shared<Pulley>(15.0, mImagesDir);
    // Set the pulley's location relative to the machine (adjust values as needed)
    pulley2->SetLocation(wxPoint(19, -80));
    machine->AddComponent(pulley2);

    // Small pulley on motor shaft (already exists as pulley2)
    motor->GetSource()->SetSink(pulley2->GetSink());

    //
    // Large pulleys
    //
    auto largePulleyLeft = std::make_shared<Pulley>(40.0, mImagesDir);
    largePulleyLeft->SetLocation(wxPoint(-108, -240));
    machine->AddComponent(largePulleyLeft);

    auto largePulleyRight = std::make_shared<Pulley>(40.0, mImagesDir);
    largePulleyRight->SetLocation(wxPoint(110, -179));
    machine->AddComponent(largePulleyRight);

    //
    // Small pulleys centered in large pulleys
    //
    auto centerPulleyLeft = std::make_shared<Pulley>(15.0, mImagesDir);
    centerPulleyLeft->SetLocation(wxPoint(-108, -240));
    largePulleyLeft->SetChild(centerPulleyLeft);  // attach to large left
    machine->AddComponent(centerPulleyLeft);

    auto centerPulleyRight = std::make_shared<Pulley>(15.0, mImagesDir);
    centerPulleyRight->SetLocation(wxPoint(110, -179));

    machine->AddComponent(centerPulleyRight);

    centerPulleyRight->Drive(largePulleyRight);



    // Create the flag and hook it to the left big pulley
    auto flag = std::make_shared<Flag>(mImagesDir+ L"/flag.png",40,80);
    // **Crucial**: use the exact same location
    flag->SetLocation(centerPulleyRight->GetLocation());
    machine->AddComponent(flag);

    // Hook the flag’s sink to the pulley’s source
    centerPulleyRight->GetSource()->AddSink(flag->GetSink());

    auto blower = std::make_shared<BubbleBlower>(mImagesDir);
    // lift it 20px above the top of your black post:
    blower->SetLocation(wxPoint(-7, -299));

    blower->SetSpawnOffset({ -95, -20 });

    machine->AddComponent(blower);

    // drive the blower off the small right pulley:
    centerPulleyRight->GetSource()->AddSink(blower->GetSink());


    //
    // Connect belts
    //
    // motor small pulley → left large pulley
    // Connect belts: motor small -> large left -> small right
    pulley2->Drive(largePulleyLeft);
    largePulleyLeft->Drive(centerPulleyRight);



    return machine;




}