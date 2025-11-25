#include <iostream>
#include <conio.h>
#include <string.h>
#include <vector>
#include <sstream>

//Global Variables
int x = 0; //this will count how many times the game has incremented
bool cmd = false;

//Player class is to go here and to encompass all double variable and cost increments
class player
{
private:
    //class variables
    double points = 100, multiplier = 1, increment = 1, reincarnationMultiplier = 1, accensionMultiplier = 1, reincarnation = 0, accension = 0, multiplierUpgarde = 1.1, upgradeIncrementMulti = 1;
    double incrementUpgrade = 1.1, upgradeIncrementIncre = 1;
    int multiplierCost = 50, incrementCost = 5, reincarnarteCost = 100; //cost for upgrades

public:
    //info function
    void info()
    {
        //Title card
        std::cout <<
            "+----------|Point Incremental|----------+" << std::endl <<
            "|                                       |" << std::endl <<
            "+--------------[By Jack J]--------------+" << std::endl <<
            "\n";

        //print information
        std::cout
            << "+----------|Point Incremental|----------+" << std::endl
            << " - Current Points: " << points << std::endl
            << " - Current Increment Amount: " << increment << std::endl
            << " - Current Multiplier: " << multiplier << std::endl
            << " - Current Rencarnation: " << reincarnation << std::endl
            << " - Current Accension: " << accension << std::endl
            << " - Current Rencarnation Multiplier: " << reincarnationMultiplier << std::endl
            << " - Current Accension Multiplier: " << accensionMultiplier << std::endl;
    }

    //Point Increment
    double pointIncrease()
    {
        points = (((points + increment) * multiplier) * reincarnationMultiplier) * accensionMultiplier;
        return points;
    }

    //Upgrade Function
    void upgrade()
    {
        //Variable
        std::string input, confirmation;

        while (true)
        {
            //player choice
            std::cout << "Which aspect would you like to upgrade - Increment or Multiplier: ";
            std::cin >> input;

            //error checking
            if (!std::cin)
            {
                std::cerr << "\n!ERROR! - !UNEXPECTED INPUT RECIEVED! !PRESS ENTER TO CONINUE!\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            else
            {
                break;
            }
        }

        //Turn input to lower case
        int i = 0;
        for (char c : input)
        {
            input[i] = tolower(c);
            i++;
        }

        //upgrade logic
        if (input == "multiplier")
        {
            //upgrade price and confirmation
            std::cout << "Upgrade the multiplier from " << multiplier << " to " << multiplier * multiplierUpgarde << "." << std::endl;
            std::cout << "To upgrade the multiplier. You need " << multiplierCost << " points. Buy?: Yes or No\n";
            std::cin >> confirmation;

            //lower case 
            i = 0;
            for (char c : confirmation)
            {
                confirmation[i] = tolower(c);
                i++;
            }

            //does player have enough points
            if (points >= multiplierCost)
            {
                if (confirmation == "yes" || confirmation == "y")
                {
                    points = points - multiplierCost; //payment
                    multiplier = multiplier * multiplierUpgarde; //upgrade multiplier
                    multiplierUpgarde = multiplierUpgarde + (0.5 * upgradeIncrementMulti); //increase multiplier upgrade
                    multiplierCost = multiplierCost * 1.5; //increase multiplier cost
                    upgradeIncrementMulti++; //increase upgrade increment amount

                    std::cout << "Upgrade success...\n";
                }
                else
                {
                    std::cout << "Upgrade Failed...\n";
                }
            }
            else //they dont have enough points
            {
                std::cout << "You dont have the points availabe..." << std::endl <<
                    "Your points: " << points << std::endl <<
                    "Multiplier Cost: " << multiplierCost << std::endl;
            }
        }
        else if (input == "increment")
        {
            //upgrade price and confirmation
            std::cout << "Upgrade the increment from " << increment << " to " << increment * incrementUpgrade << "." << std::endl;
            std::cout << "To upgrade the multiplier. You need " << incrementCost << " points. Buy?: Yes or No\n";
            std::cin >> confirmation;

            //lower case 
            i = 0;
            for (char c : confirmation)
            {
                confirmation[i] = tolower(c);
                i++;
            }

            if (points >= incrementCost)
            {
                if (confirmation == "yes" || confirmation == "y")
                {
                    points = points - incrementCost; //payment
                    increment = increment * incrementUpgrade; //Increment Upgrade
                    incrementUpgrade = incrementUpgrade + (0.5 * upgradeIncrementIncre); //increase increment upgrade
                    incrementCost = incrementCost * 1.5; // increase increment cost
                    upgradeIncrementIncre++; //increase upgrade increment amount

                    std::cout << "Upgrade success...\n";
                }
                else
                {
                    std::cout << "Upgrade Failed...\n";
                }
            }
            else
            {
                std::cout << "You dont have the points availabe..." << std::endl <<
                    "Your points: " << points << std::endl <<
                    "Increment Cost: " << incrementCost << std::endl;
            }
        }
    }

    //Reincarnate function
    void reincarnate()
    {
        //Variable
        std::string  confirmation;

        while (true)
        {
            //player choice
            std::cout << "Would you like to reincarnate for " << reincarnarteCost << " points? Yes or No" << std::endl;
            std::cin >> confirmation;

            //error checking
            if (!std::cin)
            {
                std::cerr << "\n!ERROR! - !UNEXPECTED INPUT RECIEVED! !PRESS ENTER TO CONINUE!\n" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            else
            {
                break;
            }
        }

        if (reincarnarteCost >= 100)
        {
            if (confirmation == "yes" || confirmation == "y")
            {
                points = 50, multiplier = 1, increment = 1; //reset points and multiplier and increment
                reincarnationMultiplier = reincarnationMultiplier * 1.5; //set reincarnation multiplier
                reincarnation++;

                //print results
                std::cout <<
                    "You have successfully reincarnated. Multiplier and Increment amount reset and Reincarnation multiplier has been set to " << reincarnationMultiplier << std::endl <<
                    "You have Reincarnated " << reincarnation << " times." << std::endl;
            }
        }

        else
        {
            std::cout << "You do not have the points for this. You need " << reincarnarteCost << " amount of points" << std::endl;
        }
    }
};

//Function - Command help
void help()
{
    std::cout <<
        "Commands: " << std::endl <<
        " - Help: Shows all commands" << std::endl <<
        " - Upgrade: allows the player to upgrade thier ponit increment or multiplier for a cost" << std::endl <<
        " - Continue/C: Continues the experince" << std::endl <<
        " - Reincarnate: Reset multiplier and increment amount. Reincarnation multiplier added on" << std::endl;;
}

int main()
{
    //class object
    player playerObj;

    //game while loop
    while (true)
    {
        //info print and increment
        playerObj.info();
        playerObj.pointIncrease();

        //Unlock Commands
        if (x >= 10 && x <= 50)
        {
            std::cout << "You can now use commands to interact with the systems. Type \"Help\" to see all commands available" << std::endl;
            cmd = true;
        }

        while (cmd)
        {
            std::string line = "";
            std::vector<std::string> substrings;

            while (line == "")
            {
                std::getline(std::cin, line);
            }

            int i = 0;
            int start = 0;
            int end = 0;

            //get each word in the command include numbers and add to a vector
            while (i < line.length())
            {
                if (line[i] == ' ' || i == line.length() - 1)
                {
                    end = i;

                    if (i != line.length() - 1)
                    {
                        substrings.push_back(line.substr(start, end - start));
                    }
                    else
                    {
                        substrings.push_back(line.substr(start, end - start + 1));
                    }
                    start = i + 1;
                }
                i++;
            }

            //command words
            std::vector<std::string> keywords = { "help", "continue", "upgrade", "c", "reincarnate" };
            std::vector<std::string>* pKeywords = &keywords;

            //Command 
            for (std::string s : *pKeywords)
            {
                if (s == substrings[0])
                {
                    if (s == "help")
                    {
                        help();
                    }
                    else if (s == "continue" || s == "c")
                    {
                        cmd = false;
                    }
                    else if (s == "upgrade")
                    {
                        playerObj.upgrade();
                    }
                    else if (s == "reincarnate")
                    {
                        playerObj.reincarnate();
                    }
                }
            }
        }

        //Continue
        std::cout << "Press \"Enter\" to continue and increment your points... " << std::endl;
        std::cin.get();
        system("cls");
        x++;
    }
}

