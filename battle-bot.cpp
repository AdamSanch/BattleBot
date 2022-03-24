/*  Adam Sanchez
 *  abs15d
 *  2/25/22
 *  All work below was done by Adam Sanchez
 */
#include "battle-bot.h"
#include <iostream>
using namespace std;

//-------RoboLeg Definitions
RoboLeg::RoboLeg() {
    isRaised = false;
    position = 0;
}

void RoboLeg::liftLeg() {
    cout<<"Robot lifts leg.\n";
    isRaised= true;
}

void RoboLeg::lowerLeg() {
    cout<<"Robot lowers leg.\n";
    isRaised= false;
}

void RoboLeg::swing() {
    cout<<"Robot swings leg forward.\n";
    position=1;
}

void RoboLeg::Step() {
    if (!isRaised && position==0){
        liftLeg();
        swing();
        lowerLeg();
        position=0;
    }
    else if(position!=0)
        cout<<"Cannot step, leg is already in front of Bot. Step with other leg first.";
}

void RoboLeg::Kick() {
    if (!isRaised && position==0){
        liftLeg();
        cout<<"Robot swings leg behind.\n";
        position = -1;
        cout<<"Robot kicks leg down.\n";
        position = 0;
        swing();
        cout<<"Robot swings leg back down.\n";
        position = 0;
        lowerLeg();
    }
}

//-------RoboArm Definitions
RoboArm::RoboArm() {
    isDrawnBack= false;
}

void RoboArm::drawBack() {
    cout<<"Robot draws arm back.\n";
    isDrawnBack= true;
}

void RoboArm::thrust() {
    cout<<"Robot thrust arm forward.\n";
    isDrawnBack= false;
}

void RoboArm::Punch() {
        drawBack();
        thrust();
}

//-------ProjectileLauncher Definitions
ProjectileLauncher::ProjectileLauncher() {
    isLoaded= false;
}

bool ProjectileLauncher::checkLoaded() {
    if(isLoaded)
        return true;
    else
        return false;
}

void ProjectileLauncher::Load() {
    if(!isLoaded){
        cout<<"Projectile loaded.\n";
        isLoaded=true;
    }
    else{
        cout<<"Projectile already loaded.\n";
    }
}

bool ProjectileLauncher::Fire() {
    if (checkLoaded()){
        cout<<"Projectile is fired forward.\n";
        isLoaded= false;
        return true;
    }
    else {
        cout << "No projectile loaded, failure to launch.\n";
        return false;
    }
}

//-------BattleBot Definitions
BattleBot::BattleBot() {
    x=0;
    y=0;
    direction='N';
    health=100;
}
BattleBot::BattleBot(int X, int Y, char a) {
    x=X;
    y=Y;
    direction=a;
    health=100;
}

void BattleBot::Move() {
    cout<<"Bot moves forward.\nLeft leg:\n";
    leftLeg.Step();
    cout<<"Right leg:\n";
    rightLeg.Step();
    switch (direction){
        case 'N':
            y=y+1;
            break;
        case 'S':
            y=y-1;
            break;
        case 'E':
            x=x+1;
            break;
        case 'W':
            x=x-1;
            break;
    }
}

void BattleBot::Turn(int d) {
    //Left turn
    if (d>0){
        switch (direction){
            case 'N':
                cout<<"Bot turns left.\n";
                direction='W';
                break;
            case 'S':
                cout<<"Bot turns left.\n";
                direction='E';
                break;
            case 'E':
                cout<<"Bot turns left.\n";
                direction='N';
                break;
            case 'W':
                cout<<"Bot turns left.\n";
                direction='S';
                break;
        }
    }
    //Right turn
    else if (d<0){
        switch (direction){
            case 'N':
                cout<<"Bot turns right.\n";
                direction='E';
                break;
            case 'S':
                cout<<"Bot turns right.\n";
                direction='W';
                break;
            case 'E':
                cout<<"Bot turns right.\n";
                direction='S';
                break;
            case 'W':
                cout<<"Bot turns right.\n";
                direction='N';
                break;
        }
    }
}

void BattleBot::LoadProjectile() {
    cout<<"Bot trys to load projectile.\n";
    launcher.Load();
}

void BattleBot::LaunchProjectile(BattleBot& a) {
    cout<<"Bot tries to launch projectile.\n";
    if (launcher.Fire()) {
        switch (direction) {
            case 'N':
                if (a.y == y + 1){
                    a.Hit(10);
                    cout<<"Projectile does 10 damage.\n";
                    break;
                }
                else if (a.y == y + 2){
                    a.Hit(5);
                    cout<<"Projectile does 5 damage.\n";
                    break;
                }
                else if (a.y == y + 3){
                    a.Hit(4);
                    cout<<"Projectile does 4 damage.\n";
                    break;
                }
                else if (a.y == y + 4){
                    a.Hit(3);
                    cout<<"Projectile does 3 damage.\n";
                    break;
                }
            case 'S':
                if (a.y == y - 1){
                    a.Hit(10);
                    cout<<"Projectile does 10 damage.\n";
                    break;
                }
                else if (a.y == y - 2){
                    a.Hit(5);
                    cout<<"Projectile does 5 damage.\n";
                    break;
                }
                else if (a.y == y - 3){
                    a.Hit(4);
                    cout<<"Projectile does 4 damage.\n";
                    break;
                }
                else if (a.y == y - 4){
                    a.Hit(3);
                    cout<<"Projectile does 3 damage.\n";
                    break;
                }
            case 'E':
                if (a.x == x + 1){
                    a.Hit(10);
                    cout<<"Projectile does 10 damage.\n";
                    break;
                }
                else if (a.x == x + 2){
                    a.Hit(5);
                    cout<<"Projectile does 5 damage.\n";
                    break;
                }
                else if (a.x == x + 3){
                    a.Hit(4);
                    cout<<"Projectile does 4 damage.\n";
                    break;
                }
                else if (a.x == x + 4){
                    a.Hit(3);
                    cout<<"Projectile does 3 damage.\n";
                    break;
                }
            case 'W':
                if (a.x == x - 1){
                    a.Hit(10);
                    cout<<"Projectile does 10 damage.\n";
                    break;
                }
                else if (a.x == x - 2){
                    a.Hit(5);
                    cout<<"Projectile does 5 damage.\n";
                    break;
                }
                else if (a.x == x - 3){
                    a.Hit(4);
                    cout<<"Projectile does 4 damage.\n";
                    break;
                }
                else if (a.x == x - 4){
                    a.Hit(3);
                    cout<<"Projectile does 3 damage.\n";
                    break;
                }
            default:
                cout<<"Failure to hit target.\n";
        }
    }
}

void BattleBot::RightKick(BattleBot& a) {
    cout<<"Bot kicks with right foot.\n";
    rightLeg.Kick();
    switch (direction) {
            case 'N':
                if (a.y == y + 1){
                    a.Hit(3);
                    cout<<"Kick does 3 damage.\n";
                    break;
                }
            case 'S':
                if (a.y == y - 1) {
                    a.Hit(3);
                    cout << "Kick does 3 damage.\n";
                    break;
                }
            case 'E':
                if (a.x == x + 1){
                    a.Hit(3);
                    cout << "Kick does 3 damage.\n";
                    break;
                }
            case 'W':
                if (a.x == x - 1){
                    a.Hit(3);
                    cout << "Kick does 3 damage.\n";
                    break;
                }
            default:
                cout<<"Kick did not connect.\n";
    }
}


void BattleBot::LeftKick(BattleBot& a) {
    cout<<"Bot kicks with left foot.\n";
    leftLeg.Kick();
        switch (direction) {
            case 'N':
                if (a.y == y + 1){
                    a.Hit(3);
                    cout<<"Kick does 3 damage.\n";
                    break;
                }
            case 'S':
                if (a.y == y - 1) {
                    a.Hit(3);
                    cout << "Kick does 3 damage.\n";
                    break;
                }
            case 'E':
                if (a.x == x + 1){
                    a.Hit(3);
                    cout << "Kick does 3 damage.\n";
                    break;
                }
            case 'W':
                if (a.x == x - 1){
                    a.Hit(3);
                    cout << "Kick does 3 damage.\n";
                    break;
                }
            default:
                cout<<"Kick did not connect.\n";
        }
}


void BattleBot::RightPunch(BattleBot& a) {
    cout<<"Bot punches with right arm.\n";
    rightArm.Punch();
    switch (direction) {
            case 'N':
                if (a.y == y + 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.y == y + 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
            case 'S':
                if (a.y == y - 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.y == y - 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
            case 'E':
                if (a.x == x + 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.x == x + 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
            case 'W':
                if (a.x == x - 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.x == x - 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
        default:
            cout<<"Punch did not connect.\n";
        }
}

void BattleBot::LeftPunch(BattleBot& a) {
    cout<<"Bot punches with left arm.\n";
    leftArm.Punch();
    switch (direction) {
            case 'N':
                if (a.y == y + 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.y == y + 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
            case 'S':
                if (a.y == y - 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.y == y - 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
            case 'E':
                if (a.x == x + 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.x == x + 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
            case 'W':
                if (a.x == x - 1){
                    a.Hit(5);
                    cout << "Punch does 5 damage.\n";
                    break;
                }
                else if (a.x == x - 2){
                    a.Hit(3);
                    cout << "Punch does 3 damage.\n";
                    break;
                }
        default:
            cout<<"Punch did not connect.\n";
        }
}

void BattleBot::Hit(int d) {
    health = health - d;
}

char BattleBot::GetDirection() {
    return direction;
}

int BattleBot::GetX() {
    return x;
}

int BattleBot::GetY() {
    return y;
}

int BattleBot::GetHealth() {
    return health;
}

ostream& operator<<(ostream& s, BattleBot a){
    s << " is sitting on the space (" << a.GetX() <<","<<a.GetY()<<"), facing "<<a.GetDirection()<<". Its health is "<<a.GetHealth()<<".\n";
    return s;
}