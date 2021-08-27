//Svetlana Gulotta
//Soccer Scores
//11/26/2014

#include<iostream>
#include <string>
#include<iomanip>

using namespace std;



struct PLAYERS_INFO
{
	char name[20];
	int number;
	int points;
};

int getTotalPoints(PLAYERS_INFO[], int);
int showHighest(PLAYERS_INFO[], int);
void table(PLAYERS_INFO[], int);
//argument passed by reference
void getPlayerInfo(PLAYERS_INFO &);
void showInfo(PLAYERS_INFO p);

const int NUM_OF_PLAYERS = 12;

int main()
{

	PLAYERS_INFO players[NUM_OF_PLAYERS];
	for( int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		cout<<"Enter player's #"<<i+1<<" name, number and points:";
		cin>>players[i].name;
		cin>>players[i].number;
		cin>>players[i].points;
	}//for

	cout<<"\nTable of Players\n"<<endl;
	cout<<"------------------------------\n";
	cout<<"Name          #       Points\n";
	table(players, NUM_OF_PLAYERS);
	cout<<"------------------------------\n";

	//Show total points, call getTotalPoints function
	cout<<"Total points: "<<getTotalPoints(players, NUM_OF_PLAYERS);
	cout<<endl;

	//Show highest point, call showHighest function
	cout<<"The highest point is "<<showHighest(players, NUM_OF_PLAYERS);
	cout<<endl<<endl;

	PLAYERS_INFO players_name;//new player
	//this function prompts for and stores name, number and points for a new player
	getPlayerInfo(players_name);
	//this function outputs the name, number and points for that player
	showInfo(players_name);
	
}//main

/***************************************************
Function getTotalPoints uses for loop to access 
the players points array; variable total stores 
the sum of all the palyers[i].points
total is returned

****************************************************/

int getTotalPoints(PLAYERS_INFO players[], int n)
{
	int total =0;
	for(int i = 0; i < n; i++)
	{
		total +=players[i].points ;
	}//for
	return total;
}//int getTotalPoints

/******************************************************
Function showHighest uses for loop to access 
the players points array;
variable highest stores the highest number int he array;
the function returns highest number 

*******************************************************/

int showHighest(PLAYERS_INFO players[], int n)
{
	int highest = 0;
	
	for(int i = 0; i < n; i++)
	{
		 highest = players[i].points ;
		 if(players[i].points > highest)
			 players[i].points = highest;

	}//for
	return highest;

}//int showHighest

/****************************************
Function table displays the table 
of all of the players info entered;
the information of all the players 
is accessed with the for loop;
the table is formatted
*****************************************/

void table(PLAYERS_INFO players[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<left<<setw(11)<<players[i].name<<right<<setw(4)<<players[i].number<<right<<setw(8)<<players[i].points<<endl;
		
	}//for

}//void table

/*******************************************
Function getPlayerInfo uses 
a structure reference as a parameter.
It asks the user for the information 
to store in the structure.
*******************************************/

void getPlayerInfo(PLAYERS_INFO &p)
{
	//get the players name
	cout<<"Enter the player's name: ";
	cin>>p.name;

	//get the players number
	cout<<"Enter the player's number: ";
	cin>>p.number;

	//get the players points
	cout<<"Enter the player's points: ";
	cin>>p.points;
}//void getPlayersINfo

/***********************************************
The function showInfo accepts the argumet of the
PLAYERS_INFO structure type. The contents of the
structure are displayed.

***********************************************/

void showInfo(PLAYERS_INFO p)
{
	cout<<"The player's name is "<<p.name<<endl;
	cout<<"The player's number is "<<p.number<<endl;
	cout<<"The player's points are "<<p.points<<endl;
}//void showInfo
