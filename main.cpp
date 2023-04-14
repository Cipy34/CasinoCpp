#include <iostream>
#include <string>
#include <vector>
#include<cstdlib>
#include <chrono>

#include "player.h"
#include "player.cpp"

#include "slot.h"
#include "slot.cpp"

#include "game.h"
#include "game.cpp"

#include "casino.h"
#include "casino.cpp"

#include "drink.h"
#include "drink.cpp"

void initial(Casino *c, Drink *d, Game *g){
    ///Casino initializer;
    c[0].setName("CipriBet");
    c[1].setName("JavaBet");
    c[2].setName("oopBet");

    c[0].setLocation("Strada Fericirii nr 32");
    c[1].setLocation("Strada Script nr 1");
    c[2].setLocation("Strada Clasei nr 5");

    c[0].setNrseats(5);
    c[1].setNrseats(0);
    c[2].setNrseats(1);
    

    ///Drink initializer
    d[0].setName("Water");
    d[1].setName("Whisky");
    d[2].setName("Vodka");
    d[3].setName("Coke");
    
    d[0].setThirsty(10);
    d[1].setThirsty(5);
    d[2].setThirsty(3);
    d[3].setThirsty(6);
    
    d[0].setAlcohol(0);
    d[1].setAlcohol(3);
    d[2].setAlcohol(2);
    d[3].setAlcohol(0);
    
    d[0].setPrice(3);
    d[1].setPrice(10);
    d[2].setPrice(8);
    d[3].setPrice(5);
    
    ///Game initalizer
    g[0].setName("Crowns");
    g[1].setName("Fortuna");
    g[2].setName("Lucky");
    
    g[0].setWin(2);
    g[1].setWin(3);
    g[2].setWin(4);
    
    g[0].setChance(3);
    g[1].setChance(5);
    g[2].setChance(7);
    
}
void player(Player &me){
    cin>>me;
    me.setAlcohol(0);
    me.setThirsty(0);
}
int drinksys(Player &me, Drink *d, int nrdrinks){
    int choose;
    cout<< string (10, '\n');
    cout<<"Your stats: Sold : "<<me.getMoney()<<" Thirsty : "<<me.getThirsty()<<" Alcohol : "<<me.getAlcohol()<<"\n";
    cout<<"0 - Nothing"<<"\n";
    for(int i = 1; i <= nrdrinks; i++)
        cout<<i<<" - "<<d[i-1].getName()<<" $"<<d[i-1].getPrice()<<"\n";
    cin>>choose;
    if(choose == 0)
        return 0;
    else{
        me.setThirsty(me.getThirsty() - d[choose-1].getThirsty());
        me.setMoney(me.getMoney() - d[choose-1].getPrice());
        me.setAlcohol(me.getAlcohol() + d[choose-1].getAlcohol());
        if(d[choose-1].getAlcohol() == 0)
            me.setAlcohol(me.getAlcohol() - 2);
        if(me.getThirsty() < 0)
            me.setThirsty(0);
        if(me.getAlcohol() < 0)
            me.setAlcohol(0);
    }
    return drinksys(me, d, nrdrinks);
}

int start(const Casino *c, const Player me, int nrcasinos){
    int choose, i;
    cout<<"Hello "<<me.getName()<<"! Where do you want to go?"<<"\n";
    cout<<"0 - Go home"<<"\n";
    for(i = 1; i <= nrcasinos; i++)
        cout<<i<<" - "<<c[i-1].getName()<<" on "<<c[i-1].getLocation()<<"\n";
    cin>>choose;
    return choose;
}
int choosecasino(Player me, const Casino *c, int &place, int nrcasinos){
    place = start(c, me, nrcasinos);
    if(me.getAge() < 18){
        cout<<"You are too young!";
        return 0;
    }
    if(place != 0 && me.getAge() >= 18){
        cout << string( 10, '\n' );
        cout<<"Welcome to "<<c[place-1].getName()<<"!"<<"\n";
        cout << string( 3, '\n' );
    }
}
int games(const Game *g, int nrgames){
    int choose;
    cout<<"Choose the game you like "<<"\n";
    for(int i = 0; i < nrgames; i++)
        cout<<i<<" - "<<g[i].getName()<<"\n";
    cin>>choose;
    return choose;
}
void choosegame(const Game *g, int &game, int nrgames){
    Player me;
    game = games(g, nrgames);
    cout<<"The rules are the following : "<<"\n";
    cout<<"- If you will get three same numbers, you will win : "<<g[game].getWin()<<" multiplied by your bet $"<<"\n";
    cout<<"- In this game are "<<g[game].getChance()<<" numbers"<<"\n";
    cout<<"- If you win a round you can try to double the win"<<"\n";
    cout<<"- If your alcohol is equal or more than 10 you are kicked out the casino!"<<"\n";
    cout<<"- You can't play if your thirsty level is 10"<<"\n";
    cout<<"- When you play the slots your thirsty level will increase by 1"<<"\n";
    cout<<"- Have fun!"<<"\n";
}

void random(Game *g, vector <int> &slot, int game){
    cout << string( 10, '\n' );
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(seed);
    for (int i=0; i<g[game].getChance(); i++)
        slot[i] = rand()%g[game].getChance()+1;
    g->setLine(slot);
    cout<<g->getLine()<<"\n";
}
bool validator(Game *g){
    if(g->getLine()/100 == g->getLine()/10%10 && g->getLine()/10%10 == g->getLine()%10)
        return true;
    else
        return false;
}
int gamble(Game *g, int &money){
    int choose;
    cout<<"Choose a color!"<<"\n"<<"0 - Red"<<"\n"<<"1 - Black"<<"\n"<<"2 - Cashout"<<"\n";

    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    srand(seed);
    g->setGamble(rand()%2);

    cin>>choose;
    if(choose == g->getGamble()){
        cout<<"You won : $"<<money*2<<"\n";
        money = money*2;
        gamble(g, money);
    }
    else{
        if(choose != 2){
            cout<<"Wrong color!"<<"\n";
            money = 0;
        }
    }
    return money;
}
int winner(Player &me, Game *g, int bet, int game){
    int choose, money;
    cout<<"You won : $"<<bet*g[game].getWin()<<"\n";
    money = bet*g[game].getWin();
    cout<<"0 - Cashout"<<"\n"<<"1 - Gamble"<<"\n";
    cin>>choose;
    cout << string( 10, '\n' );
    if(choose == 1)
        me.setMoney(me.getMoney() + gamble(g, money));
    else
        me.setMoney(me.getMoney() + money);

}

int changebet(int money, int bet){
    cout<<"Place the bet : $";
    cin>>bet;

    if(bet > money){
        cout<<"The bet is to high! Please change the bet"<<"\n";
        return changebet(money, 0);
    }
    return bet;
}
int ingame(Player &me, Game *g, int game, Drink *d, int nrdrinks)
{
    int choose = 1, bet = 0;
    vector <int> slot(3);
    bet = changebet(me.getMoney(), bet);
    cout << string( 10, '\n' );

    while(choose > 0)
    {
        cout<<"0 - Cashout"<<"\n"<<"1 - Start"<<"\n"<<"2 - Change the bet"<<"\n"<<"3 - Menu"<<"\n";
        cout<<"Your sold : $"<<me.getMoney()<<"            Bet : $"<<bet<<"\n";
        cout<<"Thirsty lvl : "<<me.getThirsty()<<"            Alcohol lvl : "<<me.getAlcohol()<<"\n";
        cin>>choose;

        if(me.getThirsty() == 10)
            if(drinksys(me, d, nrdrinks) == 0 && me.getThirsty() == 10){
                cout<<"Game over!";
                return 0;
            }

        if(me.getAlcohol() >= 10){
            cout<<"You are too drunk to play!";
            return 0;
        }


        switch (choose) {
            case 0: {
                cout << string( 10, '\n' );
                cout<<"0 - Go home"<<"\n"<<"1 - Try another casino"<<"\n";
                cin>>choose;
                return choose;
            }

            case 1:{
                me.setThirsty(me.getThirsty()+1);
                if(me.getMoney()>0){
                    me.setMoney(me.getMoney() - bet);
                    random(g, slot, game);
                    if(validator(g)){
                        winner(me, g, bet, game);
                    }
                }
                else{
                    cout<<"Your sold is empty"<<"\n";
                    return 0;
                }
                break;
            }

            case 2:{
                bet = changebet(me.getMoney(), bet);
                cout << string( 10, '\n' );
                break;
            }
            case 3:{
                drinksys(me, d, nrdrinks);
            }
        }
    }
    return 0;
}

int createworld(Casino *c, Game *g, Drink *d, int &nrcasinos, int &nrgames, int &nrdrinks){
    int choose = 1;
    while(choose != 0 && choose != 7){
        cout<<"\n0 - Exit\n\n1 - Add new casino\n2 - Add new game\n3 - Add drinks\n\n";
        cout<<"4 - Display the casinos\n5 - Display the games\n6 - Display the drinks\n7 - Start the game\n";
        cin>>choose;
        switch (choose) {
            case 0: return 0;
            case 1:{
                cout<<"These are the casinos :"<<"\n";
                for(int i = 0; i < nrcasinos; i++)
                    cout<<c[i];
                cout<<"Adding new casino"<<"\n";
                cin>>c[nrcasinos];
                nrcasinos++;
                break;
            }
            case 2:{
                cout<<"These are the games :"<<"\n";
                for(int i = 0; i < nrcasinos; i++)
                    cout<<g[i];
                nrgames++;
                cout<<"Adding new game"<<"\n";
                cin>>g[nrgames-1];
                break;
            }
            case 3:{
                cout<<"These are the drinks :"<<"\n";
                for(int i = 0; i < nrdrinks; i++)
                    cout<<d[i];
                nrdrinks++;
                cout<<"Adding new drinks"<<"\n";
                cin>>d[nrdrinks-1];
                break;
            }
            case 4:{
                cout<<"These are the casinos :"<<"\n";
                for(int i = 0; i < nrcasinos; i++)
                    cout<<c[i];
                break;
            }
            case 5:{
                cout<<"These are the games :"<<"\n";
                for(int i = 0; i < nrcasinos; i++)
                    cout<<g[i];
                break;
            }
            case 6:{
                cout<<"These are the drinks :"<<"\n";
                for(int i = 0; i < nrdrinks; i++)
                    cout<<d[i];
                break;
            }
            case 7:{
                cout<<"The game is starting now:\n";
            }
        }
    }
    return 1;
}
int main() {
    Player me;
    Game *g = new Game[20];
    Casino *c = new Casino[20];
    Drink *d = new Drink[20];

    int place, game, choose;
    int nrcasinos = 3, nrgames = 3, nrdrinks = 4;

    initial(c, d, g);

    if(createworld(c, g, d, nrcasinos, nrgames, nrdrinks) == 0)
        return 0;
    player(me);

    start:

    choosecasino(me, c, place, nrcasinos);
    if(place == 0)
        return 0;
    if(me.getAge() >= 18){
        choosegame(g, game, nrgames);

        cout<<"0 - Go home"<<"\n"<<"1 - Play"<<"\n"<<"2 - Change the casino"<<"\n";
        cin>>choose;

        switch (choose) {
            case 0: break;
            case 1:{
                if(ingame(me, g, game, d, nrdrinks) > 0)
                    goto start;
            }
                break;
            case 2: goto start;
        }
    }

    return 0;
}
