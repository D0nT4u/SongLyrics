#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void wait(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void typeText(string text, int speed = 100) { // slower typing: 100 ms per char
    for (char c : text) {
        cout << c << flush;
        wait(speed);
    }
    cout << "\n";
}

void printSection(string title) {
    cout << "\n";
    cout << "----------------------------------------\n";
    typeText("  " + title, 80); // slower section title typing
    cout << "----------------------------------------\n\n";
    wait(500); // longer pause after section title
}

void printLines(vector<string> lines, int speed = 100, int pauseBetween = 600) {
    for (string line : lines) {
        if (line == "") {
            cout << "\n";
            wait(400); // pause for blank line
        } else {
            typeText(line, speed);
            wait(pauseBetween);
        }
    }
}

// =============================================
void verse2() {
    printSection(" "); // fixed typo
    vector<string> lines = {
        "And I say, good girl's got her mind right",
        "She been raised right, being patient I know you waiting",
        "Waiting on the good things when the time's right",
        "You should let me get to know you baby",
        "But I just wanna put it on you, if you want to",
        "Baby tell me what you gon' do girl",
        "I can make you feel perfect, girl you're worth it",
        "I just need to see you work it girl"
    };
    printLines(lines, 50, 600); // slower typing + longer pause
}

// =============================================
int main() {
    cout << "\n";
    cout << "========================================\n";
    typeText("   Right Here - Justin Bieber", 80);
    cout << "========================================\n";
    wait(1000); // pause before starting lyrics

    verse2();
    wait(800);

    cout << "\n========================================\n";
    typeText("            ~ End of Song ~", 80);
    cout << "========================================\n\n";

    return 0;
}
