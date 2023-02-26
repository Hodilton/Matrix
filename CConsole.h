#pragma once

#if defined(max)
#undef max
#endif

#if defined(min)
#undef min
#endif

template<typename T>
class CConsole {
public:
	static T ReadNumber(const vector<string>& text, istream& out = cin, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max())
	{
		T input;

		do {
			system("cls");
			copy(text.begin(), text.end(), ostream_iterator<string>(cout));

			if ((out >> input).good() && (min <= input) && (input <= max))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return input;
			}
			else
			{
				cin.clear();
				cout << "Please enter a number from the acceptable range of values." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");
				
				/*if (!cin.eof())*/
			}
			
			/*if (cin.fail())*/

		} while (true);
	}

	static T ReadString(const vector<string>& text, istream& in = cin)
	{
		string str;

		system("cls");
		copy(text.begin(), text.end(), ostream_iterator<string>(cout));

		//cin.ignore();
		getline(in, str);

		return str;
	}
};