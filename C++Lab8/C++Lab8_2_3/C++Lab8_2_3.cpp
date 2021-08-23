#include <iostream>
#include <fstream>
using namespace std;

const char fname[] = "NewFile";
int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream ofs(fname, ios::out|ios::_Noreplace);
	if (!ofs) {
		cout << "Ошибочная ситуация! Файл "
			<< fname
			<< "уже существует."
			<< endl;
		return 0;
	}
	else {
		ofs << "Эта строка записывается в новый файл";
		ofs.close();
		ofstream fs;
		fs.open(fname, ios::ate |ios::out);
		fs << "Сейчас к ней сделано добавление";
		fs.close();
		fstream ifs(fname);
		if (ifs) {
			cout << "В старом файле содержится"
				<< "..."
				<< endl;
			char Line[80]; 
			ifs.getline(Line, sizeof(Line));
			cout << Line;
		}
		else {
			cout << "Ошибочная ситуайия "
				<< "при повторном открытии"
				<< fname
				<< endl;
		}
	}
}
