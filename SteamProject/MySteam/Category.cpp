#include "Category.h"
#include <iostream>

FCategory::FCategory()
{
    GamesAmount = 0;
}

//-------------------------------------------------------------------------------------------------------------

FCategory::FCategory(const std::string& NewCategoryName)
{
    CategoryName = NewCategoryName;
    GamesAmount = 0;
}

FCategory::FCategory(const FCategory &InCategory)
{
    CategoryName = InCategory.CategoryName;
    GamesAmount = InCategory.GamesAmount;

    //is this necessary?
    //is there any other way to do this?
    for (int i=0; i < GamesAmount; i++)
    {
        GameArray[i] = InCategory.GameArray[i];
    }

}

FCategory::~FCategory()
{
    //the destructor
}
    
//-------------------------------------------------------------------------------------------------------------

const std::string& FCategory::GetCategoryName() const
{
    return CategoryName;
}

//-------------------------------------------------------------------------------------------------------------

void FCategory::SetCategoryName(const std::string& NewCategoryName)
{
    CategoryName = NewCategoryName;
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::AddGame(const FGame& NewGame)
{
    if(HasSpaceForGames())
    {
        GameArray[GamesAmount] = NewGame;
        GamesAmount++;
        return true;
    }
    return false;
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::HasSpaceForGames() const
{
    return GamesAmount < MaxGamesAmount;
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::IsValid() const
{
    return !CategoryName.empty();
}

//-------------------------------------------------------------------------------------------------------------

void FCategory::ShowAllGames() const
{
    for (FGame LoopGame : GameArray)
    {
        if (LoopGame.IsValid())
        {
            std::cout << LoopGame.GetGameName() << "\t" << LoopGame.GetStudioName() << "\t" << LoopGame.GetReleaseDate() << std::endl;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------

bool FCategory::GetGameAt(const int& Index, FGame& OutGame) const
{
    if (Index >= 0 && Index < GamesAmount)
    {
        OutGame = GameArray[Index];
        return true;
    }
    return false;
}


