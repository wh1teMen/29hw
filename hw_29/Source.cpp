#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int overwrite(string &path,string &str) {
	ofstream out2;
	out2.open(path,ios::in||ios::out);
	if (out2.is_open()) {
		out2 << str << "\n";
		out2.close();
		return true;
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "ru");
	system("title �������� ������� #29(������ � �������� ��������)");
	cout<<"������ 1\n";
	ofstream out;
	string path="file.txt";
	out.open(path,ios::app);
	if (out.is_open()) {
		string input;
		do {
			cout << "������� ������: \n";
			getline(cin, input);
			out << input << "\n";
		} while (input != "end");
	}
	else
		cout << "������ �������� �����";
	out.close();
	ifstream in;
	in.open(path);
	if (in.is_open()) {
		while (!in.eof()) {
			string str;
			getline(in, str);
			cout << str << endl;
		}
	}
	else
		cout << "������ �������� �����";
	in.close();
	remove("file.txt");
	cout << "������ 2\n";
	string path2 = "file2.txt";
	string str="������� ���������� �����, �� ��� �������!!! ";
	(overwrite(path2, str) == 1) ? cout << "TRUE"<<endl :  cout << "FALSE"<<endl;
	system("pause>nul");
	return 0;
}