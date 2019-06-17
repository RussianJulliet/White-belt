#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

#include <map>

class Person {
public:
  map <int, string> name;
  map <int, string> surname;

  int Min(const map<int, string>& m) {
      int min = -1;
      for (const auto& item : m) {
          if (min == -1) 
              min = item.first;
          if (item.first < min) {
              min = item.first;
          }
      }
      return min;
  }

  void ChangeFirstName(int year, const string& first_name) {
    name[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    surname[year] = last_name;
  }

  string GetFullName(int year) {
    string answer;  
    if ((year < Min(name)) && (year < Min(surname))) {
        answer = "Incognito";
        return answer;
    }
    
    else if ((year < Min(name)) && (year >= Min(surname))) {
        while (surname[year].length() == 0) {
            year = year - 1;
        }
        answer = surname[year] + " with unknown first name";      
        return answer;
    }
    
    else if ((year >= Min(name)) && (year < Min(surname))) {
         while (name[year].length() == 0) {
            year = year - 1;
         }
         answer = name[year] + " with unknown last name";      
         return answer;
    }

    else/* ((year >= Min(name)) && (year >= Min(surname)))*/ {
        int year1 = year, year2 = year;
        while (name[year1].length() == 0) {
            year1 = year1 - 1;
        }
        while (surname[year2].length() == 0) {
            year2 = year2 - 1;
        }

         answer = name[year1] + " " + surname[year2];          
         return answer;
    }
    //return answer;
 }

private:
  // приватные поля
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  person.ChangeFirstName(1900, "Polya");
  person.ChangeLastName(1965, "Sergunkovna");
  for (int year : {1899, 1900, 1961, 1965, 1990}) {
      cout << person.GetFullName(year) << endl;
      }
  
  return 0;
}
