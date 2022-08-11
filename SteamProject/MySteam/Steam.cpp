#include "Steam.h"
#include <iostream>

FSteam::FSteam()
{
	MenuActive = MainMenu;
}

void FSteam::RunApp()
{
	FCategory testCategory = FCategory("Test");
	MainHandler.AddCategory(testCategory);

	while (true)
	{
		int UserOption;
		std::cout << "------ Welcome to Steam! ------" << std::endl;
		std::cout << "\t1 - Add New game \n\t2 - Working on... \n\t3 - Working on... \n\t4 - Exit \n" << ">>";
		std::cin >> UserOption;

		switch (UserOption)
		{
		case AddGame:
			OpenAddGameMenu();
			break;

		case ShowCategories:
			break;

		case ShowGames:
			break;

		case Exit:
			//MenuActive = Exit;
			exit(1);
			break;

		default:
			std::cin.clear();
			std::cin.ignore(100, '\n');
			break;
		}

		system("cls");
	}
}


int FSteam::ValidateInput(const std::string Question)
{
	bool bRepeat;
	do
	{
		std::cout << Question << " >>";
		int Input;
		std::cin >> Input;

		if (std::cin.fail())
		{
			bRepeat = true;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			system("cls");
		}
		else
		{
			bRepeat = false;
			return Input;
		}

	} while (bRepeat);
}

FGame FSteam::AskForNewGame()
{
	bool bRepeat;
	do
	{
		system("cls");

		std::cout << "Enter the game name >>";
		std::string NewGameName;
		std::cin >> NewGameName;

		std::cout << "Enter the name of the studio that develop the game >>";
		std::string NewStudioName;
		std::cin >> NewStudioName;

		int GameDay = ValidateInput("Enter the release day");
		int GameMonth = ValidateInput("Enter the release month");
		int GameYear = ValidateInput("Enter the release year");

		FGame NewGame = FGame(NewGameName, NewStudioName, GameDay, GameMonth, GameYear);

		if (NewGame.IsValid())
		{
			bRepeat = false;
			return NewGame;
		}
		else
		{
			bRepeat = true;
		}

	} while (bRepeat);
}

void FSteam::OpenAddGameMenu()
{
	FGame NewGame = AskForNewGame();

	bool bGameAdded;
	char UserChoice;
	do
	{
		system("cls");
		std::cout << "Do you want to add the game to an existing category?(y/n)\n" << ">>";
		std::cin >> UserChoice;

		if (MainHandler.GetCategoriesAmount() <= 0)
		{
			UserChoice = 'n';
		}

		if (UserChoice == 'y')
		{
			system("cls");
			MainHandler.ShowCategories();
			std::cout << "\nSelect a category >>";
			int CategoryIndex;
			std::cin >> CategoryIndex;

			if (CategoryIndex >= 0 && CategoryIndex < MainHandler.GetCategoriesAmount() && !std::cin.fail())
			{
				bGameAdded = MainHandler.AddGameToCategory(CategoryIndex, NewGame);
				std::cout << "Adding game to " << MainHandler.GetCategory(CategoryIndex).GetCategoryName() << std::endl;
			}
			else
			{
				//repeat loop
				UserChoice = 'r';
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}

		}
		else if (UserChoice == 'n')
		{
			std::cout << "Adding game to Uncategorized" << std::endl;
			bGameAdded =  Uncategorized.AddGame(NewGame);
			break;
		}
		else
		{
			//repeat loop
			UserChoice = 'r';
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	} while (UserChoice == 'r');

	if (bGameAdded)
	{
		std::cout << "Game added!" << std::endl;
	}
	else
	{
		std::cout << "Fail to add game!" << std::endl;
	}

}

void FSteam::OpenCategoriesMenu()
{

}


