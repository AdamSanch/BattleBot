/*  Adam Sanchez
 *  abs15d
 *  2/25/22
 *  All work below was done by Adam Sanchez
 */
#include <iostream>
using namespace std;

class RoboLeg {

private:
    bool isRaised;
    int position;
    void liftLeg();
    void swing();
    void lowerLeg();

public:
    RoboLeg();
    void Step();
    void Kick();
};

class RoboArm {

private:
    bool isDrawnBack;
    void drawBack();
    void thrust();

public:
    RoboArm();
    void Punch();
};

class ProjectileLauncher {

private:
    bool isLoaded;
    bool checkLoaded();

public:
    ProjectileLauncher();
    void Load();
    bool Fire();
};

class BattleBot {

    friend ostream& operator<<(ostream& s, BattleBot a);

private:
    RoboArm leftArm;
    RoboArm rightArm;
    RoboLeg leftLeg;
    RoboLeg rightLeg;
    ProjectileLauncher launcher;
    int x;
    int y;
    char direction;
    int health;

public:
    BattleBot();
    BattleBot(int X, int Y, char a);
    void Move();
    void Turn(int d);
    void LoadProjectile();
    void LaunchProjectile(BattleBot& a);
    void RightPunch(BattleBot& a);
    void LeftPunch(BattleBot& a);
    void RightKick(BattleBot& a);
    void LeftKick(BattleBot& a);
    int GetHealth();
    void Hit(int d);
    char GetDirection();
    int GetX();
    int GetY();
};


