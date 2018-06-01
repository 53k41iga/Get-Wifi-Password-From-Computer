#include <iostream>
#include <windows.h>

#include "read-file.h"
#include "get-list.h"
#include "profile-class.h"

using namespace std;

int main(void)
{
	system("netsh wlan show profile > users.txt");
	
	vector<string> ProfileLines = readline("users.txt");
	vector<string> users = get_wifi_profiles_name(ProfileLines);

	vector<PROFILE> lst = get_list_users(users);

	for(int i = 0; i < lst.size(); i++)
	{
		cout << "Wifi profile " << i + 1 << " : \n";
		cout << "\tWifi name = " << lst[i].get_user() << "\n";
		cout << "\tPassword = " << lst[i].get_password() << "\n";
		cout << "-----------------------------------------\n\n";
	}
	
	system("rm users.txt");
	system("rm password.txt");
	return 0;
}
