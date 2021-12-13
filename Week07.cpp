// Week07.cpp : program to calculate a bowling league's average bowling scores and reads the input data from the file BowlingScores.txt



#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Declaring variables
const int N_players = 10;
const int N_games = 5;

struct bowlerStructure
{
	string bowler_name;
	int scores[N_games];
	double avg_score;
};

// Function prototypes
// get data from file
bool GetBowlingData(char filename[], bowlerStructure arr[]);
// calculate averages for each player
void GetAverageScore(bowlerStructure arr[]);
// Display results
void PrettyPrintResults(bowlerStructure arr[]);



// Display results
void PrettyPrintResults(bowlerStructure arr[])
{
	cout << "\n" << endl;
	cout << setw(42) << setfill('~') << "" << endl;
	cout << setw(30) << setfill('>') << " Bowling Scores " << setw(12) << setfill('<') << "" << endl;
	cout << setw(42) << setfill('~') << "" << endl;
	cout << "\n" << endl;


	cout << "\n" << endl;
	// Prints each player name, scores and average 
	for (int player = 0; player < N_players; player++)
	{
		cout << arr[player].bowler_name << "'s scores are: ";;

		for (int cols = 0; cols < (N_games); cols++)
		{
			cout << arr[player].scores[cols] << " ";
		}


		cout << "  with Avarage of : " << arr[player].avg_score << endl;
	}
}

bool GetBowlingData(char filename[], bowlerStructure arr[])
{
	ifstream inData;
	inData.open(filename);

	if (!inData) //checks to see if file opens if not is an error
	{
		cout << "There is an error\n";
		return -1;
	}

	// for loop to get data for the rows
	for (int rows = 0; rows < N_players; rows++)
	{
		//for loop to get data for scores
		inData >> arr[rows].bowler_name;

		for (int cols = 0; cols < N_games; cols++)
		{
			inData >> arr[rows].scores[cols];
		}
	}


	inData.close();
	return 0;
}
//function to get the average score for each player
void GetAverageScore(bowlerStructure arr[])
{
	double sum = 0;

	for (int bowlers = 0; bowlers < N_players; bowlers++)
	{
		// find the scores for each player
		for (int games = 0; games < N_games; games++)
		{
			sum += arr[bowlers].scores[games];
		}
		// calculate average
		arr[bowlers].avg_score = sum / N_games;
		sum = 0;
	}
}

int main()
{
	// Arrays and variables
	bowlerStructure bowler_arry[N_players];
	
	char file_name[] = "BowlingScores.txt";

	// Function calls
	GetBowlingData(file_name, bowler_arry);
	GetAverageScore(bowler_arry);
	PrettyPrintResults(bowler_arry);
}