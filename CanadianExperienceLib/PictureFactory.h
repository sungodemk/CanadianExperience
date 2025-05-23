/**
 * @file PictureFactory.h
 * @author Charles Owen
 *
 * A factory class that builds our picture.
 */

#ifndef CANADIANEXPERIENCE_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_PICTUREFACTORY_H

class Picture;

/**
 * A factory class that builds our picture.
 */
class PictureFactory {
private:
    ///mposition
    wxPoint  mPosition{0,0};
public:
    std::shared_ptr<Picture> Create(std::wstring resourcesDir);
};

#endif //CANADIANEXPERIENCE_PICTUREFACTORY_H
