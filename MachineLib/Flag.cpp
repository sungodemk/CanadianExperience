/**
 * @file Flag.cpp
 * @author Emmanuel Koshy
 */
#include "pch.h"
#include "Flag.h"

Flag::Flag(const std::wstring &file) {
    // Draw a rectangle *centered* at (0,0), width=20, height=40
    // x = –width/2, y = –height/2
    mImage.Rectangle(-10, -20, 20, 40);

    // Then set the texture
    mImage.SetImage(file);
}
/**
 *
 * @param r
 */
void Flag::SetRotation(double r) {
    Component::SetRotation(r);
    mImage.SetRotation(r);
}