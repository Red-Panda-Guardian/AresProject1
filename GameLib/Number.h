/**
 * @file Number.h
 * @author jadec
 *
 *
 */

#ifndef ARES_GAMELIB_NUMBER_H
#define ARES_GAMELIB_NUMBER_H
#include "Item.h"
class Number : public Item
{
protected:
    Number(Game *game, const std::wstring &filename);
private:
    int mValue;
public:
    /// Default constructor (disabled)
    Number() = delete;

    /// Copy constructor (disabled)
    Number(const Number &) = delete;

    /// Assignment operator
    void operator=(const Number &) = delete;

    void SetValue(int i) { mValue = i; }

    /**
     * Return value of this number
     * @return value
     */
    int GetValue() { return mValue; }
};

#endif //ARES_GAMELIB_NUMBER_H