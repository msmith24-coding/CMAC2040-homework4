/*
 *  Michael Smith
 *  Homework 2,
 *  
 *  Worked with Aidenn Shay
 */

#include "AbilityT.h"

/**
 * @brief This function is used to convert an AbilityT to a string.
 * 
 * @param ability The AbilityT we want to convert to a string.
 * 
 * @return The passed in AbilityT as a string.
*/
std::string AbilityTToString(AbilityT ability)
{
    std::string result;
    bool found = false;
    for(unsigned int i = 0; i < sizeof(ABILITIES) / sizeof(ABILITIES[0]); i++) {
        AbilityT tempAbility = static_cast<AbilityT>(i);
        if((ability == tempAbility) && !found) {
            found = true;
            result = ABILITIES[i];
        }
    }
    return result;
}

AbilityT StringToAbilityT(const std::string & abilityStr)
{
    AbilityT result(AbilityT::NONE);

    std::string str = abilityStr;
   
    for(unsigned int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]);
    }

    bool found = false;
    for(unsigned int i = 0; i < sizeof(ABILITIES) / sizeof(ABILITIES[0]); i++) {
        if((ABILITIES[i] == str) && !found) {
            found = true;
            result = static_cast<AbilityT>(i);
        }
    }
    return result;
}

AbilityT operator + (AbilityT a, size_t b) // <-- result = ability + b;
{
    size_t offset { static_cast<size_t>(a) };
    AbilityT result { AbilityT::NONE };

    // std::cout << "+ overload BEFORE: " << offset << std::endl;

    offset = offset + b;
    if(offset <= static_cast<size_t>(AbilityT::NONE)) {
        result = static_cast<AbilityT>(offset);
    }

    // std::cout << "+ overload AFTER: " << offset << std::endl;

    // result = static_cast<AbilityT>(offset);

    return result;
}

AbilityT& operator ++ (AbilityT& a) // <-- ++ability;
{
    // std::cout << std::endl;
    // std::cout << "Beginning of ++" << std::endl;

    a = a + 2;

    // std::cout << a << std::endl;
    // std::cout << "End of ++" << std::endl;
    // std::cout << std::endl;

    return a;
}

// So this is how i++ works... Interesting...
AbilityT operator++(AbilityT& a, int) // <-- ability++;
{
    AbilityT temp {a};
    a = a + 2;
    return temp;
}

AbilityT operator - (AbilityT& a)
{
    AbilityT result { AbilityT::NONE };

    size_t offset { static_cast<size_t>(a) };

    // std::cout << "offset: " << offset << " | type: " << ABILITIES[offset] << std::endl;

    // THIS NEEDS FIXED
    if(offset % 2 == 0) { // <-- Negative
        //std::cout << "TRRERUEUDSH" << std::endl;
        result = static_cast<AbilityT>(offset + 1);
    } else { // <-- Positive
        result = static_cast<AbilityT>(offset - 1);
    }

    // std::cout << "Result: " << result << std::endl;
    // std::cout << std::endl;

    return result;
}

std::ostream & operator << (std::ostream & s, const AbilityT & ability)
{
    s << AbilityTToString(ability);
    return s;
}

std::istream & operator >> (std::istream & s, AbilityT & ability)
{
    std::string value; // <-- This is not a very cool string.
    s >> value;
    ability = StringToAbilityT(value);
    return s;
}
