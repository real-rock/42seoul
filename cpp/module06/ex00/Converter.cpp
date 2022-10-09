/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:25:22 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/06 12:28:34 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"


bool Converter::_is_invalid(std::string &s) {
    return s == "inf" || s == "inff" || s == "-inf" || \
     s == "-inff" || s == "nan" || s == "nanf";
}

bool Converter::_is_invalid(double d) {
    return abs(d) == std::numeric_limits<double>::infinity() || std::isnan(abs(d));
}

void Converter::_handle_invalid() {
    if (_src == "inf" || _src == "inff")
        _data = __DBL_MAX__ * 1000;
    else if (_src == "-inf" || _src == "-inff")
        _data = __DBL_MAX__ * (-1000);
    else
        _data = sqrt(-1.0);
}

double Converter::_handle_int(std::string s) {
    double res = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            throw ConvertException();
        res *= base;
        res += static_cast<double>(s[i] - '0');
    }
    return res;
}

double Converter::_handle_frac(std::string s) {
    double res = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] < '0' || s[i] > '9')
            throw ConvertException();
        res /= base;
        res += static_cast<double>(s[i] - '0');
    }
    return res;
}

double Converter::_str_to_doub(std::string &s) {
    std::string::size_type dot, f;
    double n, r;
    int sign = 0;

    dot = s.find('.');
    if (s[0] == '-')
        sign = 1;
    n = _handle_int(s.substr(sign, dot - sign));
    if (dot != std::string::npos) {
        f = s.find('f', s.length() - 1);
        r = _handle_frac(s.substr(dot + 1, f));
    }
    if (sign)
        return (n + r / base) * (-1);
    return n + r / base;
}

float Converter::_str_to_float(std::string &s) {
    double d = _str_to_doub(s);
    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
        throw OverflowException();
    return static_cast<float>(d);
}

char Converter::_str_to_char(std::string &s) {
    
}

int Converter::_str_to_int(std::string &s) {
    double d = _str_to_doub(s);
    if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
        throw OverflowException();
    return static_cast<float>(d);
}

Converter::Converter() {
    _src = std::string("");
    _data = 0;
    _type = NONE;
}

Converter::Converter(char *s) {
    _src = std::string(s);
    _data = 0;
    _type = NONE;
}

Converter::~Converter() {}

Converter::Converter(const Converter &c) {
    *this = c;
}

void Converter::parse() {
    if (_src.length() == 1) {
        if (_src[0] >= '0' && _src[0] <= '9') {
            this->_data = static_cast<double>(_src[0] - '0');
            this->_type = INT;
        }
        else {
            this->_data = static_cast<double>(_src[0]);
            this->_type = CHAR;
        }
        return;
    }
    if (_is_invalid(_src)) {
        _handle_invalid();
        return;
    }
    if (_src.find('f', _src.length() - 1) != std::string::npos)
        this->_type = FLOAT;
    else
        this->_type = DOUBLE;
    this->_data = _str_to_doub(_src);
}

void Converter::print_all() const {
    std::stringstream ss;

    int n = static_cast<int>(_data);
    char c = static_cast<char>(_data);
    float f = static_cast<float>(_data);

    ss << "char: ";
    if (n >= 32 && n <= 127)
        ss << "'" << c << "'\n";
    else
        ss << "Not displayable\n";
    ss << "int: ";
    if (_data > INT_MAX || _data < INT_MIN)
        ss << "Conversion to integer is impossible\n";
    else
        ss << n << "\n";
    std::cout << ss.str();
    ss.str(std::string());
	ss.clear();
    ss << "float: " << f;
    if (!_is_invalid(static_cast<double>(f)) && ss.str().find('.') == std::string::npos)
        ss << ".0";
    ss << "f\n";
    std::cout << ss.str();
    ss.str(std::string());
	ss.clear();
    ss << "double: " << _data;
    if (!_is_invalid(static_cast<double>(f)) && ss.str().find('.') == std::string::npos)
        ss << ".0";
    std::cout << ss.str() << std::endl;
}

Converter& Converter::operator=(const Converter &c) {
    _src = c._src;
    _data = c._data;
    _type = c._type;
    return *this;
}
