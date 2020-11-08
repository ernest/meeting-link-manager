#include <fstream>
#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string, std::ofstream;

int main() {
  // open html file
  ofstream ofs("index.html");

  // continue if file is valid
  if (ofs.is_open()) {
    ofs << "<!DOCTYPE html>" << endl;
    ofs << "<html lang=\"en\" dir=\"ltr\">" << endl;
    ofs << "<head>" << endl;
    ofs << "  <meta charset=\"utf-8\">" << endl;
    ofs << "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">" << endl;
    ofs << "  <title>Timetable</title>" << endl;
    ofs << "  <link rel=\"stylesheet\" href=\"stylesheets/style.css\">" << endl;
    ofs << "  <link rel=\"stylesheet\" href=\"stylesheets/font.css\">" << endl;
    ofs << "</head>" << endl;
    ofs << "<body>" << endl;
    ofs << "  <h1 id=\"title\">Timetable</h1>" << endl;

    unsigned classesInDay;
    string className, startTime, endTime, meetingId, hasPassword;
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // iterate for each day of the week
    for (size_t i = 0; i < 7; i++) {
      cout << "Enter the number of meetings you have on " << days[i] << ": ";
      cin >> classesInDay;

      if (!cin.good()) {
        cout << "You must enter a number." << endl;
        return 1;
      }
      cin.ignore();

      ofs << "  <div class=\"day\" id=\"d" << i << "\">" << endl;

      // special <div> if there are no classes
      if (classesInDay == 0) {
        ofs << "    <p>Nothing today!</p>" << endl;
      }

      // iterate for each class
      for (size_t j = 0; j < classesInDay; j++) {
        // <div> starting tag
        ofs << "    <div class=\"event\">" << endl;

        cout << "  Enter the name of class " << (j + 1) << ": ";
        getline(cin, className);

        cout << "  Enter the time it starts (eg. 12:00): ";
        getline(cin, startTime);

        cout << "  Enter the time it ends: ";
        getline(cin, endTime);

        cout << "  Enter its meeting id: ";
        getline(cin, meetingId);

        ofs << "      <p>" << startTime << " - " << endTime << "<span>" << className << "</span></p>" << endl;
        ofs << "      <p>" << meetingId << "</p>" << endl;

        cout << "  Does the meeting require a password? (y/n): ";
        getline(cin, hasPassword);

        if (hasPassword == "y" || hasPassword == "yes") {
          string password = "";
          cout << "    Enter its password: ";
          getline(cin, password);
          ofs << "      <p>" << password << "</p>" << endl;
        }
        ofs << "    </div>" << endl;
      }

      ofs << "  </div>" << endl;
    }

    ofs << "  <script type=\"text/javascript\" src=\"scripts/day.js\"></script>" << endl;
    ofs << "</body>" << endl;
    ofs << "</html>" << endl;

    cout << "Your configuration has been saved. Open index.html to see your timetable. You can also make changes there." << endl;

  } else {
    cout << "Problem opening file." << endl;
    return 1;
  }

  return 0;
}

