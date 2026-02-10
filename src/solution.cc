#include "solution.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  // your implementation here...
  std::string first_name, last_name;
  char comma = '\0';
  unsigned int uin = 0;
  double gpa = 0.0;
  is >> first_name >> last_name >> uin >> comma >> gpa;
  if (is.fail()) {
    return Student{};
  }
  if (comma != ',') {
    return Student{};
  }
  if (last_name.back() != ',') {
    return Student{};
  }

  last_name.pop_back();

  Student student{first_name + " " + last_name, uin, gpa};

  return student;
}