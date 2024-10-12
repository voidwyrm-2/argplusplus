#include <iostream>

#include "../argpp.hpp"
using namespace argpp;

int main(int argc, char** argv) {
    vector<Flag>* flags = new vector<Flag>();
    Flag help("h", "help", "Shows the help message");
    flags->push_back(help);
    Flag msg("m", "msg", "Shows a message");
    flags->push_back(msg);
    Flag say("", "say", "Says the given message", false, false);
    flags->push_back(say);

    Parser parser(argc, argv, *flags, "example");

    auto parsed = parser.parse();

    if (parsed.first.at(help.mkey()).exists) {
        cout << parser.help() << "\n";
        return 0;
    }

    if (parsed.first.at(msg.mkey()).exists) {
        cout << "hello!\n";
    }

    if (parsed.first.at(say.mkey()).exists) {
        auto result = parsed.first.at(say.mkey());
        cout << "you said: " + result.value + "\n";
    }

    return 0;
}