#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <stack>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

/* the comparation between the value of the map*/
struct Compare 
{
	bool operator()(const pair<string,int>& lhs, const pair<string, int>& rhs) {
		return lhs.second < rhs.second;
	}
};  

int main()
{
	ifstream file;

	while (true)
	{
		int thing;
		
		cout << "input '0' to input 'n','1' to input str:";
		cin >> thing;

		if (thing == 0)
		{
			int n;
			string line;
			map <string, int> output;
			
			while (true)
			{
				cout << "please input the number 'n': ";
				cin >> n;
				if (n > 0)
				{
					file.open("dictionary.txt");
					while (getline(file, line))
					{
						if (line.length() >= n)
						{
							string str = line.substr(line.length() - n); // read the last-n suffix
							output[str] += 1;   // count the number of suffix
						}

					}
					vector <pair<string, int>> get_all(output.begin(), output.end());
					sort(get_all.begin(), get_all.end(), Compare());//use Compare to let the number be descending oder
					for (int i = get_all.size() - 1; i >= get_all.size() - 10; i--)
					{
						cout << get_all[i].first << "     " << get_all[i].second << endl;
					}
					file.close();
					break;
				}
				else continue;
			}
		}

		if (thing == 1)
		{
			string line;
			string word;
			stack<string> outside;

			int count = 0;

			cout << "please input the str:";	
			cin >> word;

			file.open("dictionary.txt");
			while (getline(file, line))
			{
				if (line.length() >= word.length())
				{
					string str = line.substr(line.length() - word.length()); // get the last-word.length() latters
					if (str == word)
					{
						outside.push(line);		//  output into a stack				
					}
				}
			}
			/* output by descending order */
			for (int i = 0; i < outside.size(); i++)
			{
				cout << outside.top() << endl;
				outside.pop();
			}
			cout << "the number of words is: " << outside.size() << endl;
			file.close();
		}
		else continue;
	}
	
}
