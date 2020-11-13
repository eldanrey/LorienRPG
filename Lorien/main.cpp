/*
Name: Eldan Rey V. Dofredo
Date Created:12/11/20 11:06
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <random>
#include <cstdlib>
using namespace std;
ifstream inFile;
ofstream outFile;
void menu(string);



void heal(){
	
}
void huntMonsters(){
	string s,user,pass;
	int mattack,level,xp,coins,attack,defense,life;
	inFile.open("user.dat");
	while(getline(inFile,s)){
		stringstream ss(s);
		ss>>user>>pass>>level>>xp>>coins>>attack>>defense>>life;
	}
	default_random_engine rd(time(0));
	mattack=(rd()%35)+25;
	

}
void shop(){
	
}


void update(string user){
	string s,username,password;
	int level,xp,coins,attack,defense,life;
	inFile.open("user.dat");
	while(getline(inFile,s)){
		stringstream ss(s);
		ss>>username>>password>>level>>xp>>coins>>attack>>defense>>life;
		if(username==user){
		
			cout<<"User: "<<username;
			cout<<"\nLevel: "<<level;
			cout<<"\nXP: "<<xp;
			cout<<"\nCoins: "<<coins;
			cout<<"\nAttack: "<<attack;
			cout<<"\nDefense: "<<defense;
			cout<<"\nLife: "<<life;
			inFile.close();
		}
	}
}
void menu(string user){
	char choice;
	update(user);
	cout<<"\n\n[1]Hunt Monsters\n[2]Go To Shop\n[3]Inventory\nPick(1-3): ";
	cin>>choice;
	switch(choice){
		case '1':{
			huntMonsters();
			break;
		}
		case '2':{
			shop();
			break;
		}
		case '3':{
			heal();
			break;
		}
		

	}
	
}


//******************************************************************************************************
//*								START OF LOGIN
//******************************************************************************************************
string login(){
	login:
	bool isLogin=false;
	string username, password,user,pass,s;
	inFile.open("user.dat");
	cout<<"Username: ";
	cin>>username;
	cout<<"Password: ";
	cin>>password;
	system("cls");
	while(getline(inFile,s)){
		stringstream ss(s);
		ss>>user>>pass;
		if(username==user && password==pass){inFile.close();
		menu(username);isLogin=true;
	}
	}
	if(!isLogin){
		cout<<"Wrong Username and Password\n\n";
		
		goto login;
	}
}
//******************************************************************************************************
//*									END OF LOGIN
//******************************************************************************************************


//******************************************************************************************************
//*								START OF SIGN UP
//******************************************************************************************************
void signup(){
	signup:
	string username,pass,s,useduser;
	int attack=1,defense=1,life=100,coins=300,xp=0,level=1;
	
	cout<<"Please Enter your username: ";
	cin>>username;
	outFile.open(username".dat",ios::app);
	cout<<"Please Enter your password: ";
	cin>>pass;
	inFile.open(username".dat");
	while(getline(inFile,s)){
		stringstream ss(s);
		ss>>useduser;
	}
	if(useduser==username){
		cout<<"\nUsed Username Please choose another username;\n\n";
		system("cls");
		goto signup;
	}
	else outFile<<username<<" "<<pass<<" "<<level<<" "<<xp<<" "<<coins<<" "<<attack<<" "<<defense<<" "<<life;
	outFile.close();
}
//******************************************************************************************************
//*								END OF SIGN UP
//******************************************************************************************************


//******************************************************************************************************
//*								START OF INTRO
//******************************************************************************************************
void intro(){
	char choice;
	intro_menu:
	cout<<"WELCOME TO LORIEN A TEXT BASE RPG FOR C++\n\n";
	cout<<"[1]Login\n[2]Signup\nEnter(1-2)";
	cin>>choice;
	system("cls");
	switch(choice){
		case '1':{
			login();
			break;
		}
		case '2':{
			signup();
			break;
		}
		default:{
			goto intro_menu;
			break;
		}
	}
}
//******************************************************************************************************
//*								END OF INTRO
//******************************************************************************************************


int main(){
intro();

}

