#ifndef READ_FILE_H_
	#define READ_FILE_H_

#include <string>
#include <fstream>
#include <vector>

using namespace std;

string remove_space(string str);

vector<string> readline(const char * path);

vector<string> split(string line, const char c);

bool is_line_has_profile_name(string line);
vector<string> get_wifi_profiles_name(vector<string> ProfileLines);

string remove_space(string str)
{
	string rsl = str;
	
	while(true)
	{
		if(rsl[0] != ' ')
			break;

		rsl.erase(0, 1);
	}

	while(true)
	{
		if(rsl[rsl.size() - 1] != ' ')
			break;

		rsl.erase(rsl.size() - 1, 1);
	}

	return rsl;
}

vector<std::string> readline(const char * path)
{
	
	//list DataLine
        vector<string> lstDataLine;

        //Read data in *.inp file
        ifstream inputFile;
        inputFile.open(path);

        if(inputFile.fail())
        {
                cout << "Something went wrong or file not exist";
                return lstDataLine;
        }


        while(true)
        {

                char temp[100] = "";

                inputFile.getline(temp, 100, '\n');

                if(!inputFile.good())
                        break;

                string data = temp;


                lstDataLine.push_back(data);

        }

        inputFile.close();	

	return lstDataLine;
}

vector<string> split(string line, const char c)
{
 string temp = "";
        vector<string> rsl; // result

        int length = line.size();

        for(int i = 0; i < length; i++)
        {
                if(line[i] != c)
                        temp+=line[i];
                else if(line[i] == c && temp != "")
                {
                        rsl.push_back(temp);
                        temp = "";
                }
        }

        if(temp != "")
                rsl.push_back(temp);

        return rsl;	
}

bool is_line_has_profile_name(string line)
{
	const string PROFILE_HEADER = "All User Profile";

	return (line.find(PROFILE_HEADER) != string::npos);
}


vector<string> get_wifi_profiles_name(vector<string> ProfileLines)
{
	vector<string> profileName;

	int sz = ProfileLines.size();

	for(int i = 0; i < sz; i++)
		if(is_line_has_profile_name(ProfileLines[i]))
		{
			vector<string> raw = split(ProfileLines[i], ':');
			profileName.push_back(remove_space(raw[1]));			
		}

	return profileName;
}



#endif
