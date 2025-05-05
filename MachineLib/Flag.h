/**
 * @file Flag.h
 * @author Emmanuel Koshy
 *
 *
 */
 
#ifndef FLAG_H
#define FLAG_H

#pragma once
#include "Component.h"
#include "RotationSink.h"
/**
 * class flag
 */
class Flag : public Component {
public:
    /**
     *
     * @param file
     * @param width
     * @param height
     */
    Flag(const std::wstring &file, double width, double height)
      : Component(), mSink(this)
    {
        // Create a bottom‑centered rectangle of the desired size
        mImage.BottomCenteredRectangle(width, height);
        mImage.SetImage(file);
    }
    /**
     *
     * @param imageFile
     */
    Flag(const std::wstring &imageFile);
    /**
     *
     * @param r
     */
    void SetRotation(double r) override;
    /**
     *
     * @param g
     * @param m
     */
    void Draw(std::shared_ptr<wxGraphicsContext> g, wxPoint m) override {
        Component::Draw(g, m);
    }
    /**
     *
     * @return
     */
    RotationSink *GetSink() { return &mSink; }
private:
    /**
     * roation sink
     */
    RotationSink mSink{this};
};


#endif //FLAG_H
