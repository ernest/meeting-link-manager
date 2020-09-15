#include <iostream>
#include <string>
#include <fstream>
using std::cout, std::cin, std::endl, std::string, std::ofstream;

int main() {

    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // open html file
    ofstream outFS;
    outFS.open("index.html");

    // continue if file is valid
    if (outFS.is_open()) {

        outFS << "<!DOCTYPE html>" << endl;
        outFS << "<html lang=\"en\" dir=\"ltr\">" << endl;
        outFS << "<head>" << endl;
        outFS << "  <meta charset=\"utf-8\">" << endl;
        outFS << "  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">" << endl;
        outFS << "  <title>Timetable</title>" << endl;
        outFS << "  <link rel=\"stylesheet\" href=\"stylesheets/style.css\">" << endl;
        outFS << "  <link rel=\"stylesheet\" href=\"stylesheets/font.css\">" << endl;
        outFS << "</head>" << endl;
        outFS << "<body>" << endl;
        outFS << "  <h1 id=\"title\">Timetable</h1>" << endl;

        unsigned classesInDay;
        string className;
        string startTime;
        string endTime;
        string meetingId;
        string hasPassword;

        cout << "Do not enter spaces." << endl;

        // iterate for each day of the week
        for (size_t i = 0; i < 7; i++) {
            cout << "Enter the number of meetings you have on " << days[i] << ": ";
            cin >> classesInDay;

            outFS << "  <div class=\"day\" id=\"d" << i << "\">" << endl;
            if (classesInDay == 0) {
                outFS << "    <p>Nothing today!</p>" << endl;
            }

            // iterate for each class
            for (size_t j = 0; j < classesInDay; j++) {
                outFS << "    <div class=\"event\">" << endl;

                cout << "  Enter the name of class " << (j + 1) << ": ";
                cin >> className;

                cout << "  Enter the time it starts (eg. 12:00): ";
                cin >> startTime;

                cout << "  Enter the time it ends: ";
                cin >> endTime;

                cout << "  Enter its meeting id: ";
                cin >> meetingId;

                outFS << "      <p>" << startTime << " - " << endTime << "<span>" << className << "</span></p>" << endl;
                outFS << "      <p>" << meetingId << "</p>" << endl;

                cout << "  Does the meeting require a password? (y/n): ";
                cin >> hasPassword;

                if (hasPassword == "y" || hasPassword == "yes") {
                    string password = "";
                    cout << "    Enter its password: ";
                    cin >> password;
                    outFS << "      <p>" << password << "</p>" << endl;
                }
                outFS << "    </div>" << endl;
            }

            if (classesInDay > 0) {
                cout << endl;
            }
            outFS << "  </div>" << endl;
        }

        outFS << "  <script type=\"text/javascript\" src=\"scripts/day.js\"></script>" << endl;
        outFS << "</body>" << endl;
        outFS << "</html>" << endl;

        cout << "Your configuration has been saved. Open index.html to see your timetable. You can also make changes there." << endl;
        outFS.close();

    } else {
        cout << "Problem opening file." << endl;
    }

    return 0;
}

