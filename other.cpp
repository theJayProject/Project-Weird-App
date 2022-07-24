/*
#include <iostream>
#include <ctime>
#include <string>
using std::cout;
using std::cin;
using std::endl;

int day[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
std::string month[12] = { "January","February","March","April", "May","June","July","August","September","October","November","December" };
std::string weekday[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int dayInMonth[7][12] = {};

int  y = 0, z = 0, w = 0, f = 0;


int main() {
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
	int j, k;
	cout << "What day do you want to check?\n";
	cin >> j;
	cout << "What month do you want to check?\n";
	cin >> k;
	cout << "There are " << dayInMonth[j][k] << " " << weekday[j] << "'s in " << month[k] << "\n";
}*/