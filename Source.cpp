#include<iostream>
using namespace std;

class User {
	static int next_ID;
	int ID;
	string fullname;
	string gmail;
	int age;
	float height;
public:

	User(string fullname, string gmail, int age, float height) {
		ID = ++next_ID;
		Set_fullname(fullname);
		Set_gmail(gmail);
		Set_age(age);
		Set_height(height);
	}

	int Get_ID() {
		return ID;
	}

	string Get_fullname() {
		return fullname;
	}
	string Get_gmail() {
		return gmail;
	}
	int Get_age() {
		return age;
	}
	float Get_height() {
		return height;
	}



	void Set_fullname(string fullname) {
		this->fullname = fullname;
	}

	void Set_gmail(string gmail) {
		this->gmail = gmail;
	}

	void Set_age(int age) {
		if (age <= 6) {
			cout << endl;
			cout << "Age cannot be younger than 6" << endl;
			exit(1);
		}
		else {
			this->age = age;
		}
	}

	void Set_height(float height) {
		if (height <= 0) {
			cout << endl;
			cout << "Height cannot be younger than 0" << endl;
			exit(1);
		}
		else {
			this->height = height;
		}
	}

	void Reset_ID(int new_ID) {
		ID = new_ID;
	}


};

int User::next_ID = 0;

User* Create_Student(string fullname, string gmail, int age, float height) {
	return new User(fullname, gmail, age, height);
}

void Show_Students(User* students[], int count) {
	cout << endl;
	cout << "---------------------------------------------List of all students-------------------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < count; i++) {
		cout << "ID: " << students[i]->Get_ID()
			<< ", Full Name: " << students[i]->Get_fullname()
			<< ", Gmail: " << students[i]->Get_gmail()
			<< ", Age: " << students[i]->Get_age()
			<< ", Height: " << students[i]->Get_height() << "m" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
	}
}

void Search_Student(User* students[], int count, int id) {
	for (size_t i = 0; i < count; i++)
	{
		if (id == students[i]->Get_ID()) {
			cout << "ID: " << students[i]->Get_ID()
				<< ", Full Name: " << students[i]->Get_fullname()
				<< ", Gmail: " << students[i]->Get_gmail()
				<< ", Age: " << students[i]->Get_age()
				<< ", Height: " << students[i]->Get_height() << "m" << endl;
			return;
		}
	}
	cout << "No student found with ID " << id << endl;
}
void Delete_Student(User* students[], int& count, int id) {
	for (int i = 0; i < count; i++) {
		if (students[i]->Get_ID() == id) {
			delete students[i];

			for (int j = i; j < count - 1; j++) {
				students[j] = students[j + 1];
			}
			students[count - 1] = nullptr;
			count--;


			for (int k = 0; k < count; k++) {
				students[k]->Reset_ID(k + 1);
			}

			cout << "Student with ID " << id << " has been deleted." << endl;
			return;
		}
	}
	cout << "No student found with ID " << id << endl;
}

void Update_Student(User* students[], int& count, int id, string fullname, string gmail, int age, float height) {
	for (size_t i = 0; i < count; i++)
	{
		if (students[i]->Get_ID() == id) {
			students[i]->Set_fullname(fullname);
			students[i]->Set_gmail(gmail);
			students[i]->Set_age(age);
			students[i]->Set_height(height);
			cout << "Student with ID " << id << " has been updated." << endl;
			return;
		}
	}
	cout << "No student found with ID " << id << endl;
}


void Clean_Arrays(User* students[], int count) {
	for (int i = 0; i < count; i++) {
		delete students[i];
	}
}

int main() {
	cout << "Select one : " << endl;
	cout << "1 -> Show Students" << endl;
	cout << "2 -> Student registration" << endl;
	cout << "3 -> Search Student" << endl;
	cout << "4 -> Delete Students" << endl;
	cout << "5 -> Update Students" << endl;
	cout << "6 -> Exit system" << endl;

	string fullname;
	string gmail;
	int age;
	float height;
	User* students[100];
	int count = 0;

	students[count++] = Create_Student("Turgut Sofuyev", "turgut.sofuyev@gmail.com", 18, 1.78);
	students[count++] = Create_Student("Aysel Eliyeva", "aysel.eliyeva@gmail.com", 16, 1.67);
	students[count++] = Create_Student("Elmir Sofuyev", "elmir.sofuyev@gmail.com", 20, 1.86);

	while (true) {
		char select;
		cout << endl;
		cout << "Enter select : ";
		cin >> select;

		switch (select) {
		case '1':
			Show_Students(students, count);
			break;
		case '2':
			cout << endl;
			cout << "------------------------------------------------Student registration------------------------------------------------" << endl;
			cout << endl;
			cout << "Enter fullname : ";
			cin >> fullname;
			cout << "Enter gmail : ";
			cin >> gmail;
			cout << "Enter age : ";
			cin >> age;
			cout << "Enter height : ";
			cin >> height;
			cout << endl;

			students[count++] = Create_Student(fullname, gmail, age, height);
			cout << "The student was successfully registered" << endl;
			break;
		case '3': {
			int id;
			cout << "Enter student ID : ";
			cin >> id;
			cout << endl;
			Search_Student(students, count, id);
			break;
		}
		case '4': {
			int id;
			cout << "Enter student ID : ";
			cin >> id;
			cout << endl;
			Delete_Student(students, count, id);
			break;
		}
		case '5': {
			cout << endl;
			cout << "------------------------------------------------Student Update------------------------------------------------" << endl;
			cout << endl;
			int id;
			cout << "Enter student ID : ";
			cin >> id;
			cout << "Enter fullname : ";
			cin >> fullname;
			cout << "Enter gmail : ";
			cin >> gmail;
			cout << "Enter age : ";
			cin >> age;
			cout << "Enter height : ";
			cin >> height;
			cout << endl;
			Update_Student(students, count, id, fullname, gmail, age, height);
			break;
		}
		case '6':
			cout << endl;
			cout << "-----------------------------------------------------Exit-----------------------------------------------------";
			cout << endl;
			Clean_Arrays(students, count);
			exit(1);
		default:
			cout << endl;
			cout << "Invalid selection, please try again." << endl;
			break;
		}
	}
}