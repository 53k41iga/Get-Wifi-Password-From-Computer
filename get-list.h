#ifndef GET_LIST_H_
	#define GET_LIST_H_

#include "read-file.h"
#include "profile-class.h"

#include <vector>
#include <string>
#include <windows.h>

using namespace std;

bool is_line_security_key(string line);
bool is_line_has_password(string line);

string get_password(string user);
vector<PROFILE> get_list_user(vector<string> users);

bool is_line_security_key(string line)
{
	const string SECURITY_KEY_HEADER = "Security key";
	
	return (line.find(SECURITY_KEY_HEADER) != string::npos);
}

bool is_line_has_password(string line)
{
	const string KEY_CONTENT_HEADER = "Key Content";

	return (line.find(KEY_CONTENT_HEADER) != string::npos);
}

string get_password(string user)
{
	string cmd = "netsh wlan show profile name = ";
	cmd += ("\"" + user + "\" key = clear > password.txt");

	system(cmd.c_str());
	
	const char PASSWORD_FILE[20] = "password.txt";

	vector<string> UserLines = readline(PASSWORD_FILE);
	
	int sz = UserLines.size();

	for(int i = 0; i < sz; i++)
	{
		if(is_line_security_key(UserLines[i]))
		{
			vector<string> state = split(UserLines[i], ':');

			const string NO_PWD = "Absent";

			if(UserLines[i].find(NO_PWD) != string::npos)
			{
				string rsl = "#NULL#";
				return rsl;
			}
		}

		if(is_line_has_password(UserLines[i]))
		{
			vector<string> pwd = split(UserLines[i], ':');

			return pwd[1];
		}
	}

}	

vector<PROFILE> get_list_users(vector<string> users)
{
	int sz = users.size();

	vector<PROFILE> lstProfile;

	for(int i = 0; i < sz; i++)
	{
		string pwd = get_password(users[i]);

		PROFILE prf (users[i], pwd);

		lstProfile.push_back(prf);
	}

	return lstProfile;
}

#endif
