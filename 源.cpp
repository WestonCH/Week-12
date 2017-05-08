#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
using namespace std;

int main()
{
	ifstream file;
	string line;
	set <string> dic;
	unordered_set <string, string> last;
	map <int, string> output;
	stack<string> finally;
	int n;
	int j = 0;

	while (true)
	{
		int thing;
		cout << "input 0 to input 'n',otherwise to input 'str':";
		cin >> thing;

		if (thing == 0) {
			cout << "please input the number 'n': ";
			cin >> n;

			file.open("dictionary.txt");
			while (getline(file, line))
			{
				dic.insert(line.substr(line.length() - 1 - n));
				if (line.length() >= n)
				{
					last.insert(line.substr(line.length() - 1 - n));
				}
			}

			for (int i = 0; i < dic.size(); i++)
			{
				string str = *dic.end();
				dic.erase(*dic.end());
				j = last.count(str);

				output.insert(pair<int, string>(j, str));
			}
			for (int len = 0; len < 260000; len++)
			{
				auto it = output.find(len);

				if (it != output.end())
				{
					stringstream ss;
					string s;
					ss << len;
					string str2 = ss.str() + output.begin()->second;
					finally.push(str2);
				}
			}
			for (int k = 0; k < 10; k++)
			{
				cout << finally.top() << endl;
				finally.pop();
			}
			return 0;
		}
	
		else
		{
			cout << "please input the str:";
			string word;
			cin >> word;

			file.open("dictionary.txt");
			while (getline(file, line))
			{
				if (line.length() >= n && line.find(word)!=NULL)
				{
					cout << line << endl;
				}
			}

		}
}
