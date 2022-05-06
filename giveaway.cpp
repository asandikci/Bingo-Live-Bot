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

#define VERSION "v0.3.6"
//Version

#define int long long
// Just for prevent integer overflow

#define BASE_TIME 300 
// Wait for "BASE_TIME * baseMultiplier" Milliseconds (Default is 300)

#define SHUFFLE_NUM 1000
// Shuffle array SHUFFLE_NUM time (Default is 1000)

#define NEGATIVE_FLAG -98749891
// a random negative flag for errors (Default is -98749891)

#define CONG_LENG 2
// Congratulations Party Length (Default is 2)

#define ANIMATION_SPEED 50
// Modify Animation Speed (Default is 50)


void waitBase(int baseMultiplier){
	this_thread::sleep_for(chrono::milliseconds(BASE_TIME * baseMultiplier));
	return;
}
void waitMilli(int millisecond){
	this_thread::sleep_for(chrono::milliseconds(millisecond));
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

string symbol(int kind){
	string res="\u29BE";
	switch(kind){
		case 1: res="\u2713"; break;
		case 2: res="\u2A2F"; break;
		case 3: res="\u229A"; break;
		default : res="\u29BE"; //unnecessary line
	}
	return res;
}

string upperString(string str){
	string res_str="";
	int len = str.length();
	for(int i=0;i<len;i++){
		res_str +=toupper(str[i]);
	}
	return res_str;
}

int numControl(string str){
	int len = str.length();
	for(int i=0;i<len;i++){
		if(!(isdigit(str[i]))){
			return NEGATIVE_FLAG;
		}
	}
	return stoll(str);
}

signed main() {

	{
		system("clear");
		cout << flush << " - - - Bing"<<symbol(3)<<" - Live Bot by Aliberk Sandıkçı - - -\n";
		cout << flush << "                    [" << VERSION << "]\n";
		cout << flush << "           > Press 'Enter' to start <         ";
		cin.ignore();
		system("clear");
	}
	
	waitBase(2);
	cout << flush << "Initializing 'giveaway.cpp' code";
	printDot(3);
	//just graphical, nothing is loading on the code side :D


	waitBase(1);
	cout << flush << "'Random Seed' is loading";
	waitBase(1);
	printDot(3,0);
	
	srand(unsigned (time(0))); //Seed	

	cout << flush << " [Loaded " << symbol(1) << "] \n";
	waitBase(1);

	
	cout << flush << "> Welcome to Bingo-Live Bot <\n";
	waitBase(1);
	cout << flush << "-Made by asandikci#0001-\n";
	waitBase(5);
	
	cout << flush << "\n\n\n\n\n";
	system("clear");
	
	//
	// Program Starts:
	//

	string participantNum_str_;
	int participantNum=0;
	cout << flush << "Enter the number of participants: ";
		
	while(participantNum<=0){
		cin >> participantNum_str_;
		if(numControl(participantNum_str_)==NEGATIVE_FLAG){
			cout << flush << "Please enter a 'Positive Number' !!!\n";
			cout << flush << "Enter the number of participants: ";
		}
		else{
			participantNum = numControl(participantNum_str_);
			if(participantNum==0){
				cout << flush << "Please enter a number 'greater' than '0' !!!\n";
				cout << flush << "Enter the number of participants: ";
			}
		}
	}

	cout << flush << "[" << symbol(1) << "] " << participantNum << " is a valid number\n\n";

	waitBase(1);


	cout << flush << "Enter the number of Giveaways: ";
	waitBase(1);
	cout << flush << "1 [Default]\n\n";
	waitBase(2);

	
	vector<string> dataVec;
	string nameInput;
	string inviteNumberInput_str_;
	int inviteNumberInput;

	cout << flush << "Enter the Data as \" 'DiscordName'  'Invite Number' \"\n\n"; 

	int totalDraw=0;

	map<string,int> participantMap;
	int maxDraw=1;
	int minDraw=10000;
	bool dataValid=1;

	while(1){
		participantMap.clear();
		dataValid=1;
		totalDraw=0;
		dataVec.clear();

		maxDraw=1;
		minDraw=10000;

		for(int i=0;i<participantNum;i++){
			cin >> nameInput;
			cin >> inviteNumberInput_str_;

			if(numControl(inviteNumberInput_str_)==NEGATIVE_FLAG || numControl(inviteNumberInput_str_)==0){
				dataValid=0;
				break;
			}
			else{
				inviteNumberInput = numControl(inviteNumberInput_str_);
			}

			maxDraw = max(maxDraw,inviteNumberInput);
			minDraw = min(minDraw,inviteNumberInput);

			participantMap[nameInput] = inviteNumberInput;
			totalDraw+=inviteNumberInput;

			for(int j=0;j<inviteNumberInput;j++){
				dataVec.push_back(nameInput);
			}	
		}
		if(totalDraw > 32767){
			cout << flush << " - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
			cout << flush << "WARNING: Total invited person limit (32767) exceeded !!!\n";
			cout << flush << "> Contact with Developers if this problem is not fixed <\n";
			cout << flush << " - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		}
		else if(totalDraw <= 0){
			cout << flush << " - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
			cout << flush << "[" << symbol(2) << "]";
			cout << flush << " WARNING: Please enter a number greater than '0' !!! \n";
			cout << flush << " - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		}
		else if(!dataValid){
			cout << flush << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
			cout << flush << "[" << symbol(2) << "]";
			cout << flush << "    WARNING: You entered a wrong type of data or non-positive number!!! \n";
			cout << flush << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		}
		else{
			cout << flush << "[" << symbol(1) << "] All Data is valid \n\n";
			waitBase(2);
			break;
		}
	}
	
	

	cout << flush << "Shuffling Data as randomized";
	printDot(3);

	for(int i=0;i<SHUFFLE_NUM;i++){
		random_shuffle(dataVec.begin(),dataVec.end());
	}

	cout << flush << "[" << symbol(1) << "] Shuffled all Data " <<  SHUFFLE_NUM << " times \n\n";
	waitBase(1);

	// --DEBUG--
	// for(auto it : dataVec){
	// 	cout << it << "\n";
	// }
	// cout << "\n\n";

	cout << flush << "Choosing a random number for winner between '1 and " << totalDraw << "' \n";
	printDot(3);

	int winner = rand()%totalDraw;
	
	cout << flush << "Winners are";
	printDot(3); 

	string winnerStr = dataVec[winner];
	string winnerStrUpper = upperString(dataVec[winner]);

	cout << flush << "Winner is ";
	int winnerLen = winnerStrUpper.length();
	for(int i=0;i<min(winnerLen,1ll);i++){
		cout << flush << winnerStrUpper[i];
		waitMilli(ANIMATION_SPEED*100);
	}
	for(int i=1;i<min(winnerLen,2ll);i++){
		cout << flush << winnerStrUpper[i];
		waitMilli(ANIMATION_SPEED*50);
	}
	for(int i=2;i<min(winnerLen,3ll);i++){
		cout << flush << winnerStrUpper[i];
		waitMilli(ANIMATION_SPEED*10);
	}
	for(int i=3;i<winnerLen;i++){
		cout << flush << winnerStrUpper[i];
		waitMilli(ANIMATION_SPEED);	
	}

	cout << flush << " Congratulations !!! \n";
	cout << flush << setprecision(3) <<  "Your win rate was " << ((participantMap[dataVec[winner]])/(double)totalDraw) << "\n\n";
	waitBase(20);


	// Congratulations Message 1:
	for(int i=0;i<CONG_LENG;i++){
		system("clear");
		string message = "Winner is " + winnerStrUpper + " Congratulations !!!";
		int messageLen = message.length();
		for(int j=0;j<messageLen;j++){
			cout << flush << message[j];
			waitMilli(ANIMATION_SPEED);
		}
		waitBase(2);
	}


	// Congratulations Message 2:
	for(int g=0;g<CONG_LENG;g++){
		string message2 = winnerStrUpper;
		string spaces = " ";
		for(int i=0;i<120;i++){
			system("clear");
			cout << flush << spaces << message2;
			waitMilli(ANIMATION_SPEED);
			spaces+=" ";
		}
		//back
		for(int i=0;i<120;i++){
			system("clear");
			cout << flush << spaces << message2;
			waitMilli(ANIMATION_SPEED);
			spaces=spaces.substr(0,spaces.size()-1);
		}
	}
	cout << flush << "\n\n";
	system("clear");

	cout << flush << "/*Session End Log:\n";
	cout << flush << " * There were '"<< participantNum <<"' people in total\n";
	cout << flush << " * There were '"<< totalDraw <<"' invites in total \n";
	cout << flush << setprecision(2) << " * Average number of invites was '" << (double)totalDraw/participantNum <<"'\n";
	cout << flush << " * Maximum number of invites was '"<< maxDraw <<"'\n";
	cout << flush << " * Minimum number of invites was '"<< minDraw <<"'\n";
	cout << flush << " * * * * * * * * * * * * * * * * * * * * * * * * * * \n";
	cout << flush << " * Winner of this Giveaway is '" << winnerStrUpper <<"'\n";
	cout << flush << " * " << winnerStrUpper << " had '" << participantMap[winnerStr] << "' total invites\n";
	cout << flush <<  setprecision(2) << " * " << winnerStrUpper << " had a '"<< ((participantMap[dataVec[winner]])/(double)totalDraw) <<"' percent chance of winning \n";
	cout << flush << " */\n\n\n\n";
	cout << flush << "Bingo-Live Bot just Ended\n";
	cout << flush << "- - - - - - - - - - - - - -\n";

	// DEBUG 
	// cout << "winner_no(zero indexed):" << winner << "\n"; 
	
}


/*
Links:
- - - - 
https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
https://www.cplusplus.com/reference/thread/this_thread/sleep_for/
*/
