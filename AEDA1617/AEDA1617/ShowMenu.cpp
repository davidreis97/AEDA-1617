#include "ShowMenu.h"

using namespace std;

/* showMenu
função que mostra o menu */
void showMenu(string menuList) {
	cout << endl << "------" << endl;
	int optionNum = 1;
	int findPos = menuList.find(',', 0);
	while (findPos != -1 && optionNum < 10) {
		cout << optionNum << ". " << menuList.substr(0, findPos) << endl;
		menuList = menuList.substr(findPos + 1, 1000);
		findPos = menuList.find(',', 0);
		optionNum++;
	}
	cout << optionNum << ". " << menuList << endl;
	cout << "------" << endl;
}

int getInt(int min, int max) {
	int ret = min;
	do {
		if (cin.fail() || ret < min || ret > max) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl << "[ERROR] Invalid number!";
		}
		cout << endl << "Please input a valid number between " << min << " and " << max << ":" << endl << "> ";
	} while (!(cin >> ret) || ret < min || ret > max);
	cout << endl;
	return ret;
}

int getMenu(string menuList, int min, int max) {
	showMenu(menuList);
	return getInt(min, max);
}

