#ifndef PROFILE_CLASS_H_
	#define PROFILE_CLASS_H_

#include <cstring>

class PROFILE
{
	private:
		std::string _user;
		std::string _password;
	public:

	PROFILE(std::string user, std::string password)
	{
		_user = user;
		_password = password;
	}

	std::string get_user(void)
	{
		return _user;
	}

	std::string get_password(void)
	{
		return _password;
	}

	void get_user(std::string user)
	{
		_user = user;
	}

	void get_password(std::string password)
	{
		_password = password;
	}

};

#endif
