/*������� ���� ���������� 13501/4
�� ���������� �� ������� ����� ������� ������� �������� ������� �����, � ������� ��� ����� ������, 
��������: ������������, ����Ш���������. ������� ��� � �������� ����. ���� �� ������� ����� ������� ��������� ����
� ����� �� ������, � ������� ��� ����� ������, � �������� ���� ������� ������� �� ��� ����� �������. 
������� ���� ������������,
�� ���� ����� � � � ������� �����������.
������ �������� �����:
����������
���������
����������
����������
����������
����������
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <clocale>
using namespace std;

int main(int argc, char* argv[]){
	ifstream in(argv[1]);
		if (!in.is_open()){
			ifstream in("in.txt");
	}
	ofstream out(argv[2]);
		if (!out.is_open()){
			ofstream out("out.txt");
	}
	vector <string> arr;
	arr.resize(1);
	int size = 0;
	bool check=false;
	while (in){
		in >> arr[size];
		size++; 
		arr.resize(size+1);
	}
	char a, b;
	string main_string = ""; 
	int max_length = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < arr[i].length(); j++){
			a = arr[i][j];
			for (int k = 0; k < arr[i].length(); k++){
				b = arr[i][k];
				if (j != k){
					const short int difference = 32;
					if (a == b || b == (a + difference) || b == (a - difference)){
						check = true; 
						break;
					}
					else continue;
				}

			}
			if (check){
				break;
			}
			else continue;

		}
		if (check){
			check = false;
			continue;
		}
		else{
			if (arr[i].length() > max_length){
				main_string = arr[i];
				max_length = arr[i].length();
			}
			else{
				if (arr[i].length() == max_length){
					main_string+="," + arr[i];
				}
			}
		}

	}
	out << main_string;
	cout << "Just work";
	return 0;
}