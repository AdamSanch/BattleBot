/*  Adam Sanchez
 *  abs15d
 *  2/25/22
 *  All work below was done by Adam Sanchez
 */
#include "battle-bot.h"
#include <iostream>
using namespace std;

int main() {
    BattleBot RoboCop;
    BattleBot IronGiant(0,5,'S');
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.Move();
    cout<<"IronGiant:\n";
    IronGiant.Move();
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.Turn(1);
    cout<<"IronGiant:\n";
    IronGiant.LoadProjectile();
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.Move();
    cout<<"IronGiant:\n";
    IronGiant.Turn(-1);
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.LaunchProjectile(IronGiant);
    cout<<"IronGiant:\n";
    IronGiant.Move();
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.Turn(-1);
    cout<<"IronGiant:\n";
    IronGiant.Turn(1);
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.LoadProjectile();
    cout<<"IronGiant:\n";
    IronGiant.Move();
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.LaunchProjectile(IronGiant);
    cout<<"IronGiant:\n";
    IronGiant.LeftPunch(RoboCop);
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.Move();
    cout<<"IronGiant:\n";
    IronGiant.LaunchProjectile(RoboCop);
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.LeftKick(IronGiant);
    cout<<"IronGiant:\n";
    IronGiant.RightPunch(RoboCop);
    cout<<"RoboCop"<<RoboCop<<"IronGiant"<<IronGiant;
    cout<<"RoboCop:\n";
    RoboCop.RightKick(IronGiant);
    cout<<"IronGiant:\n";
    IronGiant.RightPunch(RoboCop);
    if(RoboCop.GetHealth()>IronGiant.GetHealth())
        cout<<"RoboCop wins!\nRobocop"<<RoboCop;
    else
        cout<<"IronGiant wins!\nIronGiant"<<IronGiant;

}
