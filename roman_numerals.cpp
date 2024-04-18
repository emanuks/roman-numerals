/*******************************************************
* Copyright (C) 2024 emanuks <emanuels313@gmail.com>
*
* This file is part of roman-numerals.
*
* roman-numerals can not be copied and/or distributed without the express
* permission of emanuks
*******************************************************/

#include <string>
#include <algorithm>

#include "./roman_numerals.hpp"

int get_roman_numeral_value(char numeral) {
    switch (numeral) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }

    return -1;
}

int get_roman_numeral_priority(char numeral) {
    switch (numeral) {
        case 'I': return 1;
        case 'V': return 2;
        case 'X': return 3;
        case 'L': return 4;
        case 'C': return 5;
        case 'D': return 6;
        case 'M': return 7;
    }

    return -1;
}

bool can_have_multiple_consecutive_occurrences(char numeral) {
    return !(numeral == 'V' || numeral == 'L' || numeral == 'D');
}

int roman_numerals_to_decimal(std::string roman_numerals) {
    int decimal = 0;
    int occurrence_qty = 0;
    int priority = -1;
    std::reverse(roman_numerals.begin(), roman_numerals.end());

    std::string::iterator c;
    for (c = roman_numerals.begin(); c != roman_numerals.end(); ++c) {
        int current_value = get_roman_numeral_value(*c);
        int current_priority = get_roman_numeral_priority(*c);

        if (current_priority != priority) {
            priority = current_priority;
            occurrence_qty = 0;
        }

        occurrence_qty++;
        if (can_have_multiple_consecutive_occurrences(*c) && occurrence_qty > 3)
            return -1;
        else if (!can_have_multiple_consecutive_occurrences(*c) && occurrence_qty > 1)
            return -1;

        if (current_value == -1) {
            return -1;
        } else {
            decimal += current_value;
        }
    }

    return decimal;
}
