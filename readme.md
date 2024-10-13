# Arg++
A quick and dirty console argument parsing library for C++, inspired by Go's Flag library

Keep in mind this was written in ~3 hours and is probably quite slow

Here's an example of usage
```cpp
#include <iostream>

#include "argpp.hpp"
using namespace argpp;

int main(int argc, char** argv) {
    vector<Flag> flags = vector<Flag>();
    Flag help("h", "help", "Shows the help message");
    flags.push_back(help);
    Flag msg("m", "msg", "Shows a message");
    flags.push_back(msg);

    Parser parser(argc, argv, flags, "example");

    auto parsed = parser.parse();

    if (parsed.first.at(help.mkey()).exists) {
        cout << parser.help() << "\n";
        return 0;
    }

    if (parsed.first.at(msg.mkey()).exists) {
        cout << "hello!\n";
    }

    return 0;
}
```