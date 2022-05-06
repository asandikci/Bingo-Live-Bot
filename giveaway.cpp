/*

Writed by Aliberk Sandıkçı (asandikci#0001)
May2022

How to use:
1) Save this file to your computer as 'giveaway.cpp'
2) open a terminal in same folder with code
3) Run this commands:
	3.1) $ g++ -fsanitize=address -fsanitize=undefined -fstack-protector -Wall -Wshadow -std=c++17 main.cpp
	3.2) $ ./a.out

Tested on Ubuntu 22.04 with gcc "11.2.0"
*/

#include"bits/stdc++.h"
using namespace std;  

#define int long long
// Just for prevent integer overflow

#define BASE_TIME 300 
// Wait for "BASE_TIME * baseMultiplier" Milliseconds

#define SHUFFLE_NUM 1000


void waitBase(int baseMultiplier){
	this_thread::sleep_for(chrono::milliseconds(BASE_TIME * baseMultiplier));
	return;
}

void printDot(int dotNum, int nl=1){
	for(int i=0;i<dotNum;i++){
		waitBase(1);
		cout << flush << ".";
	}
	if(nl){
		cout << flush << "\n";
	}
	waitBase(2);
	return;
}

string tick(){
	string tick1 = "\u2713";
	return tick1;
}

signed main() {

	system("clear");
	cout << flush << " - - - Giveaway Bot by Aliberk Sandıkçı - - -\n";
	cout << flush << "                    [v0.2]\n";
	cout << flush << "           > Press 'Enter' to start <         ";
	cin.ignore();
	system("clear");

	
	waitBase(2);
	cout << flush << "Initializing 'giveaways.cpp' code";
	printDot(3);
	//just graphical, nothing is loading on the code side :D


	waitBase(1);
	cout << flush << "'Random Seed' is loading";
	waitBase(1);
	printDot(3,0);
	
	srand(unsigned (time(0))); //Seed	

	cout << flush << " [Loaded " << tick() << "] \n";
	waitBase(1);

	
	cout << flush << "> Welcome to Giveaway Bot <\n";
	waitBase(1);
	cout << flush << "-Made by asandikci#0001-\n";
	waitBase(5);
	
	cout << flush << "\n\n\n\n\n";
	system("clear");
	
	//
	// Program Starts:
	//

	int participantNum;
	cout << flush << "Enter the number of participants: ";
	cin >> participantNum;

	cout << flush << "[" << tick() << "] " << participantNum << " is a valid number\n\n";

	waitBase(1);


	cout << flush << "Enter the number of Giveaways: ";
	waitBase(1);
	cout << flush << "1 [Default]\n\n";
	waitBase(2);

	
	vector<string> dataVec;
	string tmp_str;
	int tmp_int;

	cout << flush << "Enter the Data as \" 'DiscordName'  'Invite Number' \"\n\n"; 

	for(int i=0;i<participantNum;i++){
		cin >> tmp_str;
		cin >> tmp_int;
		for(int j=0;j<tmp_int;j++){
			dataVec.push_back(tmp_str);
		}	
	}  
	
	cout << flush << "[" << tick() << "] All Data is a valid \n\n";
	waitBase(2);

	cout << flush << "Shuffling Data as randomized";
	printDot(3);

	for(int i=0;i<SHUFFLE_NUM;i++){
		random_shuffle(dataVec.begin(),dataVec.end());
	}

	cout << flush << "[" << tick() << "] Shuffled all Data " <<  SHUFFLE_NUM << " times \n\n";
	waitBase(1);

	// for(auto it : dataVec){
	// 	cout << it << "\n";
	// }
	// cout << "\n\n";

	cout << flush << "Choosing a random number for winner between '0 and " << participantNum << "' \n";
	printDot(3);

	int winner = rand()%participantNum;
	
	cout << flush << "Winners are";
	printDot(3); 


	cout << "Winner is " << dataVec[winner] << " Congratulations !!! \n";
	cout << "winner_no(zero indexed):" << winner << "\n"; 
	
}


/*
Links:
- - - - 
https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
https://www.cplusplus.com/reference/thread/this_thread/sleep_for/
*/