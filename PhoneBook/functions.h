#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class functions
{
private:
	struct Contact {
		string name, surname, patronymic;
		string home_phone, jobe_phone, mobile_phone;
		string additional_information;
	};
	int id{ 20 }, count{ 0 };

public:
	Contact* contact = new Contact[id];

	void add_contact() {
		setlocale(LC_ALL, "Russian");
		int temp{ 0 };

		if ((id - count ) == 0) {
			cout << endl << "� ��� ��� ������ ����� ��� ���������� ����� ���������" << endl << endl;
		}
		else {
			cout << endl << "�������� ��� ��������: " << id - count << endl;

			if (temp > (id - count)) {
				cout << endl << "���������� �������� ����������" << endl << endl;
			}
			else {

				cout << endl << "���� ��� ������������� ���������� ��������� '-'" << endl;

				cout << endl << "������� ���: ";
				cin >> contact[count].name;
				cout << "������� �������: ";
				cin >> contact[count].surname;
				cout << "������� ��������: ";
				cin >> contact[count].patronymic;

				cout << endl << "������� �������� �������: ";
				cin >> contact[count].home_phone;
				cout << "������� ������� �������: ";
				cin >> contact[count].jobe_phone;
				cout << "������� ��������� �������: ";
				cin >> contact[count].mobile_phone;

				cout << endl << "������� �������������� ���������� � ��������: ";
				cin >> contact[count].additional_information;

				count += 1;
			}
		}
	}
	void watch_all_contact() {
		setlocale(LC_ALL, "Russian");
		if (count <= 0) {
			cout << endl << "��� ������ ��������� ����" << endl << endl;
		}
		else {
			for (int i{ 0 }; i < count; i++) {
				cout << "������� " << i + 1 << endl << endl

					<< "���: " << contact[i].name << endl
					<< "�������: " << contact[i].surname << endl
					<< "��������: " << contact[i].patronymic << endl << endl

					<< "�������� �������: " << contact[i].home_phone << endl
					<< "������� �������: " << contact[i].jobe_phone << endl
					<< "��������� �������: " << contact[i].mobile_phone << endl << endl

					<< "�������������� ����������: " << contact[i].additional_information << endl << endl;
			}
		}
	}
	void save_contact(const string& fileName) {
		setlocale(LC_ALL, "Russian");
		ofstream outfile(fileName, ios::out);
		if (count <= 0) {
			cout << endl << "��� ������ ��������� ����" << endl << endl;
		}
		else {
			if (outfile.is_open()) {
				for (int i{ 0 }; i < count; i++) {
					outfile << contact[i].name << contact[i].surname << contact[i].patronymic
						<< contact[i].home_phone << contact[i].jobe_phone << contact[i].mobile_phone
						<< contact[i].additional_information;
				}
				outfile.close();
				cout << "������ ��������� � ����" << fileName <<endl << endl;
			}
			else {
				cerr << "������ ���������� �����: " << endl << endl;
			}
		}
	}
};

