/**
 * @file Game.cpp
 * @author Daniel Flanagan and Tyler Przybylo
 */

#include "pch.h"
#include "Game.h"
#include "Clock.h"

using namespace std;

/// Path to Background Image
std::string fileName = "images/background.png";

/**
 * Constructor for the game object
 */
Game::Game()
{
    mBackgroundImage = std::make_shared<wxImage>(fileName);
}

/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
    // Code for setting an items location can go here

    mItems.push_back(item);
}

/**
 * Draw the game
 * @param graphics Graphics device to draw on
 * @param width Width of the window
 * @param height Height of the window
 * @param clock Reference to Analog Clock object
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double width, double height, Clock &clock)
{
    //
    // Take Background Bitmap and Load Width & Height
    //
    if (mBackgroundBitmap.IsNull())
    {
        mBackgroundBitmap = graphics->CreateBitmapFromImage(*mBackgroundImage);
    }
    int backgroundWidth = mBackgroundImage->GetWidth();
    int backgroundHeight = mBackgroundImage->GetHeight();

    // Determine the size of the playing area in pixels
    // This is up to you...
    int pixelWidth = backgroundWidth;
    int pixelHeight = backgroundHeight;

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    graphics->PushState();
    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);
    graphics->PopState();

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE

    //
    // Draws Background
    //
    graphics->DrawBitmap(mBackgroundBitmap,
                         mXOffset, mYOffset,
                         backgroundWidth * mScale,
                         backgroundHeight * mScale);

    //
    // Drawing a rectangle that is the playing area size
    // Draw a rectangle
    //
    graphics->PushState();
    graphics->DrawRectangle(0, 0, pixelWidth, pixelHeight);
    graphics->PopState();

    //
    // Drawing Clock on Screen
    // Draws text in corner of Game Rectangle
    //
    wxFont font(wxSize(50 * mScale, 50 * mScale),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(*wxWHITE));

    std::string analog = clock.GetMinutes() + ":" + clock.GetSeconds();

    graphics->DrawText(analog,
                       mXOffset + (50 * mScale),
                       mYOffset + (20 * mScale));
}

/**
 * Updates and refreshes Game
 * @param elapsed Time passed since last refresh
 */
void Game::OnUpdate(double elapsed) // <- Disabled in GameView Currently
{

}

