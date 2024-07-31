#include <iostream>
#include<conio.h>
using namespace std;
void draw(char positions[4][4],int current_position[3],int horizontal_tab=50,int vertical_tab=10,int current_horizontal=1,char player_mark='?'){
int y_component=current_position[1];
int x_component=current_position[2];
if(positions[y_component][x_component]==' '){
    positions[y_component][x_component]=player_mark;
}
for(int k=0;k<vertical_tab;k++){cout<<'\n';}
for(int k=0;k<horizontal_tab;k++)
    cout<<' ';
for(int k=0;k<7;k++)
    cout<<'-';
cout<<'\n';
for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
        if (j==1){
            for(int k=0;k<horizontal_tab;k++){cout<<" ";}
        }
        cout<<'|'<<positions[i][j];
        if(j==3){cout<<'|';}
        }
        cout<<'\n';
        for(int k=0;k<horizontal_tab;k++){
            cout<<" ";
        }
        for(int k=0;k<7;k++){cout<<'-';}
        cout<<'\n';
}
}
void initialize_board(char positions[4][4]){
for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
        positions[i][j]=' ';}
void input(char &current_player,char positions[4][4],int current_position[3]){
int y_component=current_position[1];
int x_component=current_position[2];
char c='t';
c=getch();
switch(c){
case 't':
    break;
case 72:
    if(current_position[1]!=1){current_position[1]-=1;}
    break;

case 'w':
    if(current_position[1]!=1){current_position[1]-=1;}
    break;
case 80:
    if(current_position[1]!=3){current_position[1]+=1;}
    break;
case 's':
    if(current_position[1]!=3){current_position[1]+=1;}
    break;
case 77:
    if(current_position[2]!=3){current_position[2]+=1;}
    break;
case 'd':
    if(current_position[2]!=3){current_position[2]+=1;}
    break;

case 75:
    if(current_position[2]!=1){current_position[2]-=1;}
    break;
case 'a':
    if(current_position[2]!=1){current_position[2]-=1;}
    break;
case 13:
    if(positions[y_component][x_component]=='?'){positions[y_component][x_component]=current_player;
    if(current_player=='x'){current_player='0';}
    else{current_player='x';}
    }
    break;
default:
    break;
}
if(c!='t' && positions[y_component][x_component]=='?'){
    positions[y_component][x_component]=' ';
}
}
bool new_running(char positions[4][4]){

if(positions[3][1]==positions[2][2]&&positions[2][2]==positions[1][3] && positions[3][1]!=' '){return false;}
if(positions[1][1]==positions[2][2]&&positions[2][2]==positions[3][3] && positions[1][1]!=' '){return false;}
for(int i=1;i<=3;i++){
    if(positions[i][1]==positions[i][2]&&positions[i][2]==positions[i][3] && positions[i][1]!=' '){return false;}
    if(positions[1][i]==positions[2][i]&&positions[1][i]==positions[3][i] && positions[1][i]!=' '){return false;}
}
return true;
}
//low is indent
void indent(int n=30){
for(int i=0;i<30;i++){cout<<' ';}
}
void fill_stars(int n=30){
for(int i=0;i<n;i++)
    cout<<"*";
}
void indent_down(int h=10){
for(int i=0;i<h;i++)
    cout<<'\n';
}
//high is indent
void draw_for_set(int horizontal_tab,int vertical_tab){
indent_down(vertical_tab);
string command="\"";
for(int i=0;i<horizontal_tab;i++){command+=' ';}
command+="| | | |";
command=command+"\"";
command="echo "+command;
for(int i=1;i<=3;i++){
system(command.c_str());
}
}

void game(char current_player,int horizontal_tab,int vertical_tab);
void menu(int current_player='x',int horizontal_tab=50,int vertical_tab=10){
int new_current_player=current_player,new_horizontal_tab=horizontal_tab,new_vertical_tab=vertical_tab;
system("cls");
system("color 0b");
indent_down();
indent(20);
cout<<"Press :";indent_down(3);
indent();cout<<"1.To start game\n\n";
indent();cout<<"2.To exit\n\n";
indent();cout<<"3.To choose the first player[x or 0] (to move)\n\n";
indent();cout<<"4.To move the board  (still working at this)\n\n";
int option;
cout<<"option :\t";
cin>>option;
switch (option){
case 1:
    game(new_current_player,new_horizontal_tab,new_vertical_tab);
    break;
case 2:
    system("exit");
    break;
case 3:
    system("cls");
    system("color 0b");
    indent_down();
    indent(20);cout<<"Press :";indent_down(3);
    indent();cout<<"1.For x\n\n";
    indent();cout<<"2.For 0\n\n";
    cout<<"option :\t";
    int op;
    cin>>op;
    switch(op){
    case 1:
        new_current_player='x';
        break;
    case 2:
        new_current_player='0';
            break;
    default:
        break;
    }
    menu(new_current_player,new_horizontal_tab,new_vertical_tab);
    break;
    case 4:
        bool running=true;
        while(running){
        system("cls");
        system("color 0b");
            indent_down(2);
            indent(20);cout<<"Press s to save.\n";
            indent(20);
            cout<<"Use arrows to move the board.\n";
            draw_for_set(new_horizontal_tab,new_vertical_tab);
            char c='t';
            c=getch();
            switch(c){
        case 72:
            if(new_vertical_tab!=0){
            new_vertical_tab-=1;}
            break;
        case 80:
            if(new_vertical_tab!=28){new_vertical_tab+=1;}
            break;
        case 75:
            if(new_horizontal_tab!=0){new_horizontal_tab-=10;}
            break;
        case 77:
            if(new_horizontal_tab!=500){new_horizontal_tab+=10;}
            break;
        case 's':
            menu(new_current_player,new_horizontal_tab,new_vertical_tab);
            break;
        default:
            break;
            }

        }
}

}
void congrulate_winner(char winner,char current_player='x'){
system("cls");
system("color 0b");
indent_down();
indent();cout<<"The winner is "<<winner<<" !";
cout<<'\n';
indent();cout<<"************************************\n";
indent();cout<<"Press 1 to play again or 0 to go to menu:"<<"\n";
int choice;
        indent();cout<<"***********************************"<<"\n";
indent();cout<<"your choice :\t";cin>>choice;
if(choice==1){game(current_player,50,10);}
else{menu();}
}
void game(char current_player,int horizontal_tab,int vertical_tab){
char winner='1';
char setted_current_player=current_player;
int current_position[3];
//char current_player='x';
current_position[1]=1;
current_position[2]=1;
char positions[4][4];
initialize_board(positions);
//int horizontal_tab=50;
//int vertical_tab=10;
bool running=true;
while(running){
    system("cls");
    system("color f0");
    draw(positions,current_position);
    input(current_player,positions,current_position);
    running=new_running(positions);
    if(running==false){
            system("cls");
            system("color f0");
            if(current_player=='x'){current_player='0';}else{current_player='x';}
            positions[current_position[1]][current_position[2]]=current_player;

    draw(positions,current_position);
    }}
congrulate_winner(current_player,setted_current_player);
return;}
int main(){menu();}
