#define BRANCH "main"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

struct Student {
	std::string firstName;
	std::string lastName;
};

int main() {
	std::ifstream file("StudentData.txt");

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

		if (std::getline(ss, lastName, ',') &&
			std::getline(ss, firstName)) {
			students.push_back({
				.firstName = firstName,
				.lastName = lastName
				});
		}
	}
}