#define PRE_RELEASE 1

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

struct Student {
	std::string firstName;
	std::string lastName;
#if PRE_RELEASE
	std::string email;
#endif
};

int main() {
#if PRE_RELEASE
	std::ifstream file("StudentData_Emails.txt");
#else
	std::ifstream file("StudentData.txt");
#endif

	#if PRE_RELEASE
		std::cout << "(Pre-relase branch)" << std::endl;
	#else
		std::cout << "(Main branch)" << std::endl;
	#endif

	if (!file) {
		throw std::runtime_error("Failed to open StudentData.txt");
	}

	std::vector<Student> students;
	std::string line;

	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}

		std::stringstream ss(line);
		std::string lastName;
		std::string firstName;
#if PRE_RELEASE
		std::string email;
#endif
#if PRE_RELEASE
		if (std::getline(ss, lastName, ',') &&
			std::getline(ss, firstName, ',') &&
			std::getline(ss, email)) {
			students.push_back({
				.firstName = firstName,
				.lastName = lastName,
				.email = email
				});
		}
#else
		if (std::getline(ss, lastName, ',') &&
			std::getline(ss, firstName, ',')) {
			students.push_back({
				.firstName = firstName,
				.lastName = lastName
				});
		}
#endif
	}

	for (Student student : students) {
#if PRE_RELEASE
#ifdef _DEBUG
		std::cout << student.firstName << ", " << student.lastName << ": " << student.email << std::endl;
#endif
#else
#ifdef _DEBUG
		std::cout << student.firstName << ", " << student.lastName << std::endl;
#endif
#endif
	}
}