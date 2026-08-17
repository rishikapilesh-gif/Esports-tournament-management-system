#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class player
{
public:

    string playerID;
    string GamerName;
    string TeamName;
    string PlayerRole;

    int matchesPlayed;
    int wins;
    int losses;
    int kills;
    int assists;

    double matchPoints;
    double totalpoints;
    double averagepoints;
    double winPercentage;
    double performanceScore;

    void matchpoint(int wins)
    {
        matchPoints = 10 * wins;
    }

    void Totalpoints(int kills, int assists)
    {
        totalpoints = matchPoints + kills * 2 + assists;
    }

    void Averagepoints(int matchesPlayed)
    {
        if (matchesPlayed != 0)
            averagepoints = totalpoints / matchesPlayed;
        else
            averagepoints = 0;
    }

    void winpercentage(int wins, int matchesPlayed)
    {
        if (matchesPlayed != 0)
            winPercentage = (double)wins / matchesPlayed * 100;
        else
            winPercentage = 0;
    }

    void performancescore()
    {
        performanceScore = averagepoints + winPercentage / 10;
    }
};

class Attacker : public player
{
public:

    void showRole()
    {
        cout << "Role Type              : Offensive Player" << endl;
    }

    void specialSkill()
    {
        cout << "Role Advantage         : High Kill Impact" << endl;
    }
};

class Defender : public player
{
public:

    void showRole()
    {
        cout << "Role Type              : Defensive Player" << endl;
    }

    void specialSkill()
    {
        cout << "Role Advantage         : Match Stability" << endl;
    }
};

class Support : public player
{
public:

    void showRole()
    {
        cout << "Role Type              : Team Support Player" << endl;
    }

    void specialSkill()
    {
        cout << "Role Advantage         : Team Assistance" << endl;
    }
};

class Captain : public player
{
public:

    void showRole()
    {
        cout << "Role Type              : Team Leader" << endl;
    }

    void specialSkill()
    {
        cout << "Role Advantage         : Leadership Impact" << endl;
    }
};

int numberplayers;
int numberplayers2;

string ID[15];
string Name[15];
string tName[15];
string pRole[15];
string searchname;

int win2[15];
int matchesplayed2[15];
int loss2[15];
int kills2[15];
int assist2[15];

double matchPoints2[15];
double totalpoints2[15];
double averagepoints2[15];
double winPercentage2[15];
double performanceScore2[15];

double MVP;
double sumteam = 0;

int addplayers()
{
    cout << endl;

    cout << "========================================" << endl;
    cout << "        ADD TOURNAMENT PLAYERS          " << endl;
    cout << "========================================" << endl;

    cout << "Enter the number of players: ";
    cin >> numberplayers;

    while (numberplayers <= 0 || numberplayers > 15)
    {
        cout << "Please enter a number between 1 and 15: ";
        cin >> numberplayers;
    }

    for (int i = 0; i < numberplayers; i++)
    {
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter Player " << i + 1 << " Details" << endl;
        cout << "----------------------------------------" << endl;

        cout << "1) Enter Player ID: ";
        cin >> ID[i];

        bool correct = false;

        for (int j = 0; j < i; j++)
        {
            if (ID[i] == ID[j])
            {
                correct = true;
                break;
            }
        }

        if (correct == true)
        {
            cout << "Player ID already exists!" << endl;
            cout << "Please enter another ID." << endl;
            i--;
            continue;
        }

        cout << "2) Enter Player's Game Name: ";
        cin >> Name[i];

        cout << "Enter Player's Team Name: ";
        cin >> tName[i];

        cout << "Enter the Player's Role in the Game: ";
        cin >> pRole[i];

        while (pRole[i] != "Attacker" &&
               pRole[i] != "Defender" &&
               pRole[i] != "Captain" &&
               pRole[i] != "Support")
        {
            cout << "Invalid role!" << endl;
            cout << "Enter Attacker, Defender, Captain, or Support: ";
            cin >> pRole[i];
        }

        cout << "Enter the number of matches the Player played: ";
        cin >> matchesplayed2[i];

        while (matchesplayed2[i] <= 0)
        {
            cout << "Matches must be greater than zero." << endl;
            cout << "Enter matches played again: ";
            cin >> matchesplayed2[i];
        }

        cout << "Enter the Player's number of wins: ";
        cin >> win2[i];

        while (win2[i] < 0 || win2[i] > matchesplayed2[i])
        {
            cout << "Wins must be between 0 and matches played." << endl;
            cout << "Enter wins again: ";
            cin >> win2[i];
        }

        cout << "Enter the Player's number of losses: ";
        cin >> loss2[i];

        while (loss2[i] < 0 ||
               loss2[i] > (matchesplayed2[i] - win2[i]))
        {
            cout << "Losses cannot exceed remaining matches." << endl;
            cout << "Enter losses again: ";
            cin >> loss2[i];
        }

        cout << "Enter the total number of Kills: ";
        cin >> kills2[i];

        while (kills2[i] < 0)
        {
            cout << "Kills cannot be negative." << endl;
            cout << "Enter kills again: ";
            cin >> kills2[i];
        }

        cout << "Enter the number of Assists: ";
        cin >> assist2[i];

        while (assist2[i] < 0)
        {
            cout << "Assists cannot be negative." << endl;
            cout << "Enter assists again: ";
            cin >> assist2[i];
        }

        cout << endl;
        cout << "Player " << i + 1 << " successfully added!" << endl;
    }

    return numberplayers;
}

void record_match_performance()
{
    player p1;

    numberplayers2 = addplayers();

    for (int i = 0; i < numberplayers2; i++)
    {
        p1.matchpoint(win2[i]);

        p1.Totalpoints(kills2[i], assist2[i]);

        p1.Averagepoints(matchesplayed2[i]);

        p1.winpercentage(win2[i], matchesplayed2[i]);

        p1.performancescore();

        matchPoints2[i] = p1.matchPoints;
        totalpoints2[i] = p1.totalpoints;
        averagepoints2[i] = p1.averagepoints;
        winPercentage2[i] = p1.winPercentage;
        performanceScore2[i] = p1.performanceScore;
    }
}

void Display_player_detail()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        cout << "Please add players first." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "           PLAYER DETAILS               " << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < numberplayers2; i++)
    {
        cout << endl;
        cout << "----------- Player " << i + 1 << " -----------" << endl;

        cout << "Player ID                : " << ID[i] << endl;

        cout << "Player's Name            : " << Name[i] << endl;

        cout << "Player's Team Name       : "<< tName[i] << endl;

        cout << "Player's Role            : " << pRole[i] << endl;

        if (pRole[i] == "Attacker")
        {
            Attacker a;
            a.showRole();
            a.specialSkill();
        }
        else if (pRole[i] == "Defender")
        {
            Defender d;
            d.showRole();
            d.specialSkill();
        }
        else if (pRole[i] == "Support")
        {
            Support s;
            s.showRole();
            s.specialSkill();
        }
        else if (pRole[i] == "Captain")
        {
            Captain c;
            c.showRole();
            c.specialSkill();
        }

        cout << "Number of Matches Played : "
             << matchesplayed2[i] << endl;

        cout << "Number of Wins            : "
             << win2[i] << endl;

        cout << "Number of Losses          : "
             << loss2[i] << endl;

        cout << "Number of Kills           : "
             << kills2[i] << endl;

        cout << "Number of Assists         : "
             << assist2[i] << endl;

        cout << "Performance Score         : "
             << performanceScore2[i] << endl;
    }
}

void SearchPlayer()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "             SEARCH PLAYER              " << endl;
    cout << "========================================" << endl;

    cout << "Enter the Player's ID or Game Name: ";
    cin >> searchname;

    bool found = false;

    for (int i = 0; i < numberplayers2; i++)
    {
        if (searchname == ID[i] ||
            searchname == Name[i])
        {
            cout << endl;
            cout << "Player Found!" << endl;

            cout << "Player ID       : "<< ID[i] << endl;

            cout << "Game Name       : "<< Name[i] << endl;

            cout << "Team Name       : "<< tName[i] << endl;

            cout << "Player Role     : "<< pRole[i] << endl;

            cout << "Performance Score    : "<< performanceScore2[i] << endl;

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << endl;
        cout << "Player not found." << endl;
        cout << "Please re-check the Gamer-ID or Game Name." << endl;
    }
}

void calculate_statistics()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "          PLAYER STATISTICS             " << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < numberplayers2; i++)
    {
        cout << endl;

        cout << "----------- Player " << i + 1<< " -----------" << endl;

        cout << "MATCH POINTS       : "<< matchPoints2[i] << endl;

        cout << "TOTAL POINTS       : "<< totalpoints2[i] << endl;

        cout << "AVERAGE POINTS     : " << averagepoints2[i] << endl;

        cout << "WIN PERCENTAGE     : "<< winPercentage2[i] << "%" << endl;

        cout << "PERFORMANCE SCORE  : "<< performanceScore2[i] << endl;

        if (winPercentage2[i] >= 80)
        {
            cout << "Player Level       : ELITE" << endl;
        }
        else if (winPercentage2[i] >= 60)
        {
            cout << "Player Level       : PRO" << endl;
        }
        else if (winPercentage2[i] >= 40)
        {
            cout << "Player Level       : INTERMEDIATE" << endl;
        }
        else
        {
            cout << "Player Level       : BEGINNER" << endl;
        }

        cout << endl;

        if (kills2[i] > assist2[i] * 2)
        {
            cout << "Player Insight     : Excellent offensive impact!"<< endl;
        }
        else if (assist2[i] > kills2[i])
        {
            cout << "Player Insight     : Strong team-oriented player!"<< endl;
        }
        else if (winPercentage2[i] >= 70)
        {
            cout << "Player Insight     : Highly consistent performer!"<< endl;
        }
        else
        {
            cout << "Player Insight     : Potential for improvement!"<< endl;
        }
    }
}

void leaderboard()
{
    if (numberplayers2 == 0)//to confirm that a player is presnt
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "              LEADERBOARD               " << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < numberplayers2; i++)
    {
        for (int j = i + 1; j < numberplayers2; j++)
        {
            if (performanceScore2[i] < performanceScore2[j])
            {
                swap(performanceScore2[i],//to re sort the values for leaderboard or further cal
                     performanceScore2[j]);

                swap(Name[i], Name[j]);
                swap(ID[i], ID[j]);
                swap(tName[i], tName[j]);
                swap(pRole[i], pRole[j]);

                swap(win2[i], win2[j]);
                swap(matchesplayed2[i],matchesplayed2[j]);
                swap(loss2[i], loss2[j]);
                swap(kills2[i], kills2[j]);
                swap(assist2[i], assist2[j]);

                swap(matchPoints2[i],matchPoints2[j]);

                swap(totalpoints2[i],totalpoints2[j]);

                swap(averagepoints2[i],averagepoints2[j]);

                swap(winPercentage2[i], winPercentage2[j]);
            }
        }
    }

    for (int i = 0; i < numberplayers2; i++)
    {
        cout << i + 1 << ") "
             << Name[i]
             << " - "
             << ID[i]
             << " - "
             << performanceScore2[i];

        if (i == 0)
            cout << "  <-- TOP PLAYER";

        cout << endl;
    }
}

void MVPtop()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "          TOURNAMENT MVP                " << endl;
    cout << "========================================" << endl;

    MVP = performanceScore2[0];

    for (int j = 1; j < numberplayers2; j++)
    {
        MVP = max(MVP, performanceScore2[j]);
    }

    for (int i = 0; i < numberplayers2; i++)
    {
        if (MVP == performanceScore2[i])
        {
            cout << endl;
            cout << "***** CONGRATULATIONS *****" << endl;

            cout << "Tournament MVP:" << endl;

            cout << "ID                : "
                 << ID[i] << endl;

            cout << "Gamer Name        : "
                 << Name[i] << endl;

            cout << "Team              : "
                 << tName[i] << endl;

            cout << "Role              : "
                 << pRole[i] << endl;

            cout << "Performance Score : "
                 << performanceScore2[i] << endl;

            cout << "Win Percentage    : "
                 << winPercentage2[i] << "%" << endl;
        }
    }
}

void bestRolePlayers()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "             ROLE CHAMPIONS             " << endl;
    cout << "========================================" << endl;

    string roles[4] =
    {
        "Attacker",
        "Defender",
        "Support",
        "Captain"
    };

    for (int r = 0; r < 4; r++)
    {
        int best = -1;
        double bestScore = -1;

        for (int i = 0; i < numberplayers2; i++)
        {
            if (pRole[i] == roles[r])
            {
                if (performanceScore2[i] > bestScore)
                {
                    bestScore = performanceScore2[i];
                    best = i;
                }
            }
        }

        if (best != -1)
        {
            cout << endl;
            cout << roles[r] << " Champion" << endl;
            cout << "Player       : "<< Name[best] << endl;
            cout << "Team         : "<< tName[best] << endl;
            cout << "Score        : "<< performanceScore2[best] << endl;
        }
        else
        {
            cout << endl;
            cout << roles[r]<< " Champion : No player available"<< endl;
        }
    }
}

void teamperformance()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "          TEAM PERFORMANCE              " << endl;
    cout << "========================================" << endl;

    string teamNames[15];
    double teamScores[15];
    int teamCount = 0;

    for (int i = 0; i < numberplayers2; i++)
    {
        bool found = false;

        for (int j = 0; j < teamCount; j++)
        {
            if (teamNames[j] == tName[i])
            {
                teamScores[j] =
                    teamScores[j] + performanceScore2[i];

                found = true;
                break;
            }
        }

        if (found == false)
        {
            teamNames[teamCount] = tName[i];
            teamScores[teamCount] = performanceScore2[i];
            teamCount++;
        }
    }

    int bestTeam = 0;

    for (int i = 0; i < teamCount; i++)
    {
        cout << endl;

        cout << "Team " << teamNames[i]
             << " Performance" << endl;

        cout << "----------------------------------------"
             << endl;

        cout << "Total Performance Score : "
             << teamScores[i] << endl;

        if (teamScores[i] > teamScores[bestTeam])
            bestTeam = i;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "STRONGEST TEAM : "
         << teamNames[bestTeam] << endl;
    cout << "TEAM SCORE     : "
         << teamScores[bestTeam] << endl;
    cout << "========================================" << endl;
}

void tournamentSummary()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No tournament data available." << endl;
        return;
    }

    int totalKills = 0;
    int totalAssists = 0;
    int totalWins = 0;
    int totalMatches = 0;

    int bestPlayer = 0;

    for (int i = 0; i < numberplayers2; i++)
    {
        totalKills += kills2[i];
        totalAssists += assist2[i];
        totalWins += win2[i];
        totalMatches += matchesplayed2[i];

        if (performanceScore2[i] >
            performanceScore2[bestPlayer])
        {
            bestPlayer = i;
        }
    }

    double tournamentWinRate =
        (double)totalWins / totalMatches * 100;

    cout << endl;
    cout << "========================================" << endl;
    cout << "         TOURNAMENT SUMMARY             " << endl;
    cout << "========================================" << endl;

    cout << "Players Registered : "<< numberplayers2 << endl;

    cout << "Total Matches      : "<< totalMatches << endl;

    cout << "Total Wins         : "<< totalWins << endl;

    cout << "Total Kills        : "<< totalKills << endl;

    cout << "Total Assists      : "<< totalAssists << endl;

    cout << "Tournament Win Rate: "<< tournamentWinRate << "%" << endl;

    cout << endl;

    cout << "Current Top Player : "<< Name[bestPlayer] << endl;

    cout << "Best Performance   : "<< performanceScore2[bestPlayer] << endl;

    cout << endl;

    if (tournamentWinRate >= 70)
    {
        cout << "Tournament Status  : DOMINANT" << endl;
    }
    else if (tournamentWinRate >= 50)
    {
        cout << "Tournament Status  : COMPETITIVE" << endl;
    }
    else
    {
        cout << "Tournament Status  : DEVELOPING" << endl;
    }
}

void playerInsight()
{
    if (numberplayers2 == 0)
    {
        cout << endl;
        cout << "No players available." << endl;
        return;
    }

    cout << endl;
    cout << "========================================" << endl;
    cout << "          PLAYER INSIGHT                " << endl;
    cout << "========================================" << endl;

    cout << "Enter Player ID or Game Name: ";
    cin >> searchname;

    int index = -1;

    for (int i = 0; i < numberplayers2; i++)
    {
        if (searchname == ID[i] ||
            searchname == Name[i])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Player not found." << endl;
        return;
    }

    cout << endl;
    cout << "Player : " << Name[index] << endl;
    cout << "Team   : " << tName[index] << endl;
    cout << "Role   : " << pRole[index] << endl;

    cout << endl;

    if (kills2[index] >= 10)
    {
        cout << "Strength : High offensive impact" << endl;
    }
    else if (assist2[index] >= 10)
    {
        cout << "Strength : Excellent team contribution" << endl;
    }
    else if (winPercentage2[index] >= 70)
    {
        cout << "Strength : Strong consistency" << endl;
    }
    else
    {
        cout << "Strength : Balanced player" << endl;
    }

    if (winPercentage2[index] < 40)
    {
        cout << "Recommendation : Improve match consistency"
             << endl;
    }
    else if (kills2[index] < 5)
    {
        cout << "Recommendation : Improve offensive impact"
             << endl;
    }
    else if (assist2[index] < 5)
    {
        cout << "Recommendation : Increase team contribution"
             << endl;
    }
    else
    {
        cout << "Recommendation : Maintain current performance"
             << endl;
    }

    cout << endl;

    cout << "Performance Score : "
         << performanceScore2[index] << endl;
}

void comeon()
{
    char choice;

    while (true)
    {
        cout << endl;

        cout << "========================================" << endl;
        cout << "     ESPORTS TOURNAMENT MANAGEMENT      " << endl;
        cout << "========================================" << endl;

        cout << "     Manage Players. Track Performance." << endl;
        cout << "       Compete. Perform. Dominate!      " << endl;

        cout << "========================================" << endl;

        cout << "1) Add Players" << endl;
        cout << "2) Display Player Details" << endl;
        cout << "3) Search Player" << endl;
        cout << "4) Calculate Statistics" << endl;
        cout << "5) Display Leaderboard" << endl;
        cout << "6) Tournament MVP" << endl;
        cout << "7) Team Performance" << endl;
        cout << "8) Role Champions" << endl;
        cout << "9) Tournament Summary" << endl;
        cout << "A) Player Insight" << endl;
        cout << "0) Exit" << endl;

        cout << "========================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case '1':
                record_match_performance();
                break;

            case '2':
                Display_player_detail();
                break;

            case '3':
                SearchPlayer();
                break;

            case '4':
                calculate_statistics();
                break;

            case '5':
                leaderboard();
                break;

            case '6':
                MVPtop();
                break;

            case '7':
                teamperformance();
                break;

            case '8':
                bestRolePlayers();
                break;

            case '9':
                tournamentSummary();
                break;

            case 'A':
            case 'a':
                playerInsight();
                break;

            case '0':

                cout << endl;

                cout << "========================================"
                     << endl;

                cout << " Thank you for using the Esports System!"
                     << endl;

                cout << "      Keep playing. Keep improving!     "
                     << endl;

                cout << "========================================"
                     << endl;

                return;

            default:

                cout << endl;

                cout << "Invalid choice!" << endl;

                cout << "Please select a valid menu option."
                     << endl;
        }
    }
}

int main()
{
    cout << "===================================================="
         << endl;

    cout << " WELCOME TO THE ESPORTS TOURNAMENT MANAGEMENT SYSTEM"
         << endl;

    cout << "===================================================="
         << endl;

    cout << " From the battlefield to the leaderboard - "
         << "track, analyze, and crown the best"
         << endl;

    cout << " The arena decides the winner, "
         << "but the numbers reveal the champion"
         << endl;

    cout << "===================================================="
         << endl;

    comeon();

    return 0;
}