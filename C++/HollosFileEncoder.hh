#ifndef ENCODER_H
#define ENCODER_H

#include <string>
#include <unordered_map>

static const std::unordered_map<char, std::string> char_list = {
    {'a', "9a&"}, {'b', "e*;"}, {'c', "{~>"}, {'d', ";iv"}, {'e', "ps&"},
    {'f', "ps5"}, {'g', "xn^"}, {'h', "8f{"}, {'i', "$2*"}, {'j', ":x$"},
    {'k', "^rv"}, {'l', "#c~"}, {'m', "*v$"}, {'n', "}l@"}, {'o', "o%;"},
    {'p', "fzb"}, {'q', "c=3"}, {'r', ";#y"}, {'s', "%*z"}, {'t', "_u>"},
    {'u', "(3!"}, {'v', "k+s"}, {'w', "yn_"}, {'x', "{t."}, {'y', "<<m"},
    {'z', "=j>"}, {'A', "p!s"}, {'B', "-^r"}, {'C', "..+"}, {'D', "0?8"},
    {'E', "+7h"}, {'F', "q2^"}, {'G', "h2;"}, {'H', "1jc"}, {'I', "xx%"},
    {'J', "ioq"}, {'K', "!n$"}, {'L', "}$5"}, {'M', "7$$"}, {'N', "5<#"},
    {'O', "n:g"}, {'P', "zar"}, {'Q', "lo("}, {'R', "xs!"}, {'S', "j%>"},
    {'T', "lh~"}, {'U', "r)v"}, {'V', "/-b"}, {'W', "0*#"}, {'X', "l2>"},
    {'Y', "t6;"}, {'Z', "4l!"}, {'`', "1;c"}, {'~', "ex*"}, {'!', "d(2"},
    {'@', "/s%"}, {'#', "01="}, {'$', "/&b"}, {'%', "$=k"}, {'^', ":<n"},
    {'&', "2#g"}, {'*', "li="}, {'(', "#h5"}, {')', "z`("}, {'_', "2cw"},
    {'+', "_<;"}, {'-', "0?_"}, {'=', "c+u"}, {'[', "y?#"}, {']', "r6o"},
    {'{', "vra"}, {'}', "/$#"}, {'|', "d9<"}, {'\\', "tri"}, {';', "7o&"},
    {'\'', "@22"}, {'"', "hx`"}, {':', "{_y"}, {'<', "`/k"}, {'>', ")3s"},
    {'?', "bk!"}, {'/', "dgr"}, {'.', ";{l"}, {',', "*q;"}, {'1', "_-t"},
    {'2', "tqn"}, {'3', "7g1"}, {'4', "$z+"}, {'5', "*:f"}, {'6', "db5"},
    {'7', "/_?"}, {'8', "g49"}, {'9', "xg)"}, {'0', "+o}"}
};

std::string encode(const std::string& data) {
    std::string encoded_data;
    for (char ch : data) {
        auto it = char_list.find(ch);
        if (it != char_list.end()) {
            encoded_data += it->second;
        } else {
            // Keep non-mapped characters as they are
            encoded_data += ch;
        }
    }
    return encoded_data;
}

std::string decode(const std::string& data) {
    std::string decoded_data;
    std::unordered_map<std::string, char> reverse_char_list;
    for (const auto& entry : char_list) {
        reverse_char_list[entry.second] = entry.first;
    }

    for (size_t i = 0; i < data.length(); ) {
        bool found = false;
        for (int length = 3; length > 0; --length) {
            std::string current_slice = data.substr(i, length);
            auto it = reverse_char_list.find(current_slice);
            if (it != reverse_char_list.end()) {
                decoded_data += it->second;
                i += length;
                found = true;
                break;
            }
        }
        if (!found) {
            // Keep non-mapped characters as they are
            decoded_data += data[i];
            ++i;
        }
    }
    return decoded_data;
}

#endif // ENCODER_H