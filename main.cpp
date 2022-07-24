#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <chrono>
#include <ctime>
#pragma warning(suppress : 4996)
using std::cout;
using std::cin;
using std::endl;
//test
//Counting Days
int day[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
std::string month[12] = { "January","February","March","April", "May","June","July","August","September","October","November","December" };
std::string weekday[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int dayInMonth[7][12] = {};

int  y = 0, z = 0, w = 0;



struct Client{
	int ID{}, clientNumber{};
	std::string clientName;
	std::string clientEmail;
	double lessonCost{};
	std::vector<std::tuple<int, std::string, time_t>>lessonDays;
};


void printCalculations(Client calculator) {
	int banana = 0;
	int dayAmount = 0;
	int calc = 0;
	for (int v = 0; v != std::get<0>(calculator.lessonDays[0]); v++) {
		std::string day = std::get<1>(calculator.lessonDays[v]);
		for (int a = 0; a != std::get<0>(calculator.lessonDays[0])+1; a++) {
			int banana = std::distance(std::begin(weekday), std::find(std::begin(weekday), std::end(weekday), day));
			if (a <= std::get<0>(calculator.lessonDays[0])) {
				cout << banana;
			}
		}

		std::time_t t = std::time(nullptr);
		std::tm* now = std::localtime(&t);
		w = (now->tm_mon + 1);
		std::cout << "Next Month: " << month[(now->tm_mon + 1)] << std::endl;
		std::cout << "Next Month's lessons: " << (dayInMonth[banana][w] * std::get<0>(calculator.lessonDays[0])) << std::endl;

	}

	
	cout << endl;
	//cout << "Monthly payment: " << lessonsMonthlyCost << endl;

	cout << "There are " << std::get<0>(calculator.lessonDays[0]) << " lesson(s) on ";

	for (int h = 0; h != std::get<0>(calculator.lessonDays[0]); h++) {
		if (h == 0) {
			cout << std::get<1>(calculator.lessonDays[h]) << " at " << std::get<2>(calculator.lessonDays[h]);
		}
		else if (h < std::get<0>(calculator.lessonDays[0]) - 1) {
			cout << ", " << std::get<1>(calculator.lessonDays[h]) << " at " << std::get<2>(calculator.lessonDays[h]);
		}
		else if (h <= std::get<0>(calculator.lessonDays[0])) {
			cout << " and " << std::get<1>(calculator.lessonDays[h]) << " at " << std::get<2>(calculator.lessonDays[h]) << ".";
		}
	}

}

//time_t lessonTime;

void newClient(Client client) {
	client.ID++;
	cout << "What's the clients name?" << endl;
	cin >> client.clientName;
	cout << "What's the clients number?" << endl;
	cin >> client.clientNumber;
	cout << "What's the clients e-mail?" << endl;
	cin >> client.clientEmail;
	cout << "Confirm client details:/n";
	cout << "ID: " << client.ID << endl;
	cout << "Name: " << client.clientName << endl;
	cout << "Phone Number: " << client.clientNumber << endl;
	cout << "E-mail: " << client.clientEmail << endl;
}
void printClientInfo(Client client) {
	//for (int lessonDays; lessonDays != client.lessonAmount;) {

		//cout << "The day(s) of the lessons: " << weekday[client.lessonDays] << endl;

	//}

	cout << "ID: " << client.ID << endl;
	cout << "Name: " << client.clientName << endl;
	cout << "Phone Number: " << client.clientNumber << endl;
	cout << "E-mail: " << client.clientEmail << endl;
	cout << "Cost: " << client.lessonCost << endl;
	cout << "The amount of lessons per week: " << (std::get<0>(client.lessonDays[0])) << endl;
};

int main() {
	//Counting Days
	for (int b = -1; w < 12; b++) {

		if (weekday[z] == weekday[z]) {
			++dayInMonth[z][w];
		}
		y++;
		z++;
		if (z > 6) {
			z = 0;
		}
		else if (y > daysInMonth[w] - 1) {
			y = 0;
			w++;
		}
		else if (w > 11) {
			break;
		}
	} 

	std::map<std::string, Client> clients{
		{"Osoba Jeden",{
		1, 123456789, "Osoba Jeden", "osobajeden@gmail.com",50.00,{{4, "Tuesday", 1800},{4, "Tuesday", 1915},{4,"Thursday", 1915},{4,"Thursday", 2030}}} },
		{"Osoba Dwa",{
		1, 123456789, "Osoba Dwa", "osobadwa@gmail.com",60.00,{{1, "Wednesday", 1645}}} },
		{"Osoba Trzy",{
		1, 123456789, "Osoba Trzy", "osobatrzy@gmail.com",60.00,{{2, "Tuesday", 1645},{2, "Thursday", 1645}}} },
		{"Osoba Cztery",{
		1, 123456789, "Osoba Cztery", "osobacztery@gmail.com",60.00,{{2,"Wednesday", 1645},{2,"Tuesday", 2030}}} },
	};
	
	std::string clientName;
	while (!clients.contains(clientName)) {
		cout << "You have " << clients.size()<<" client(s)." << endl <<"What's the clients name? \n\n";
		getline(cin, clientName);
		if (clients.contains(clientName)) {
			printClientInfo(clients[clientName]);
			printCalculations(clients[clientName]);
		}
		else {
			cout << endl << "Error: No Client Found." << endl << endl;
		};
	}
	return 0;
}
