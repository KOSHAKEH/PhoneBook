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
			cout << endl << "У вас нет больше места для добавления новых контактов" << endl << endl;
		}
		else {
			cout << endl << "Возможно еще добавить: " << id - count << endl;

			if (temp > (id - count)) {
				cout << endl << "Превышенно возможно количество" << endl << endl;
			}
			else {

				cout << endl << "Если нет запрашиваемой информации поставьте '-'" << endl;

				cout << endl << "Введите имя: ";
				cin >> contact[count].name;
				cout << "Введите фамилию: ";
				cin >> contact[count].surname;
				cout << "Введите отчество: ";
				cin >> contact[count].patronymic;

				cout << endl << "Введите домашний телефон: ";
				cin >> contact[count].home_phone;
				cout << "Введите рабочий телефон: ";
				cin >> contact[count].jobe_phone;
				cout << "Введите мобильный телефон: ";
				cin >> contact[count].mobile_phone;

				cout << endl << "Введите дополнительную информацию о контакте: ";
				cin >> contact[count].additional_information;

				count += 1;
			}
		}
	}
	void watch_all_contact() {
		setlocale(LC_ALL, "Russian");
		if (count <= 0) {
			cout << endl << "Ваш список контактов пуст" << endl << endl;
		}
		else {
			for (int i{ 0 }; i < count; i++) {
				cout << "Контакт " << i + 1 << endl << endl

					<< "Имя: " << contact[i].name << endl
					<< "Фамилия: " << contact[i].surname << endl
					<< "Отчество: " << contact[i].patronymic << endl << endl

					<< "Домашний телефон: " << contact[i].home_phone << endl
					<< "Рабочий телефон: " << contact[i].jobe_phone << endl
					<< "Мобильный телефон: " << contact[i].mobile_phone << endl << endl

					<< "Дополнительная информация: " << contact[i].additional_information << endl << endl;
			}
		}
	}
	void save_contact(const string& fileName) {
		setlocale(LC_ALL, "Russian");
		ofstream outfile(fileName, ios::out);
		if (count <= 0) {
			cout << endl << "Ваш список контактов пуст" << endl << endl;
		}
		else {
			if (outfile.is_open()) {
				for (int i{ 0 }; i < count; i++) {
					outfile << contact[i].name << contact[i].surname << contact[i].patronymic
						<< contact[i].home_phone << contact[i].jobe_phone << contact[i].mobile_phone
						<< contact[i].additional_information;
				}
				outfile.close();
				cout << "Данные сохранены в файл" << fileName <<endl << endl;
			}
			else {
				cerr << "Ошибка сохранения файла: " << endl << endl;
			}
		}
	}
};

