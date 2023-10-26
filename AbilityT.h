#ifndef ABILITY_H_
#define ABILITY_H_

#include <string>
#include <iostream>

const std::string ABILITIES[]{"strong", "weak", "tough", "sickly", "clever", "dense", "wise", "foolish", "dexterous", "fumbling", "agile", "clumsy", "fast", "slow", "charming", "unpleasant", "attractive", "ugly", "none"};

enum class AbilityT : size_t
{
    STRONG,
    WEAK,
    TOUGH,
    SICKLY,
    CLEVER,
    DENSE,
    WISE,
    FOOLISH,
    DEXTEROUS,
    FUMBLING,
    AGILE,
    CLUMSY,
    FAST,
    SLOW,
    CHARMING,
    UNPLEASANT,
    ATTRACTIVE,
    UGLY,
    NONE
};

const AbilityT FIRST_ABILITY = AbilityT::STRONG;

std::string AbilityTToString(AbilityT);
AbilityT StringToAbilityT(const std::string &);

AbilityT operator + (AbilityT a, size_t b);
AbilityT& operator ++ (AbilityT& a);
AbilityT operator ++ (AbilityT& a, int);
AbilityT operator - (AbilityT& a);

std::ostream & operator << (std::ostream & s, const AbilityT & ability);
std::istream & operator >> (std::istream & s, AbilityT & ability);

#endif
