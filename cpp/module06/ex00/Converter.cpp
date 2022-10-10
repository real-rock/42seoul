/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:25:22 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/10 12:01:39 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

void Converter::_handle_invalid() {
    if (_src == "inf" || _src == "-inf") {
        if (_src == "inf")
            _double_data = std::numeric_limits<double>::max() * 1000;
        else
            _double_data = std::numeric_limits<double>::max() * (-1000);
        _type = DOUBLE;
    }
    else if (_src == "inff" || _src == "-inff") {
        if (_src == "inff")
            _float_data = std::numeric_limits<float>::max() * 1000;
        else
            _float_data = std::numeric_limits<float>::max() * (-1000);
        _type = FLOAT;
    }
    else {
        if (_src == "nanf") {
            _float_data = sqrt(-1.0);
            _type = FLOAT;
        }
        else {
            _double_data = sqrt(-1.0);
            _type = DOUBLE;
        }
    }
}

void Converter::_handle_digit() {
    if (std::isdigit(_src[0])) {
        _int_data = static_cast<int>(_src[0] - '0');
        _type = INT;
    }
    else {
        _char_data = _src[0];
        _type = CHAR;
    }
}

double Converter::_handle_exp(std::string s) {
    double res = 0;

    for (int i = 0; i < s.length(); i++) {
        if (!std::isdigit(s[i]))
            throw NotConvertableException();
        res *= base;
        res += static_cast<double>(s[i] - '0');
    }
    return res;
}

double Converter::_handle_frac(std::string s) {
    double res = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        if (!std::isdigit(s[i]))
            throw NotConvertableException();
        res /= base;
        res += static_cast<double>(s[i] - '0');
    }
    return res;
}

double Converter::_hanlde_float() {
    std::string::size_type dot, f;
    double exp, frac;
    int sign = 0;

    dot = _src.find('.');
    if (_src[0] == '-')
        sign = 1;
    exp = _handle_exp(_src.substr(sign, dot - sign));
    if (dot != std::string::npos) {
        f = _src.find('f', _src.length() - 1);
        frac = _handle_frac(_src.substr(dot + 1, f - dot - 1));
    }
    if (sign)
        return (exp + frac / base) * (-1);
    return exp + frac / base;
}

Converter::Converter() {
    _src = std::string("");
    _char_data = 0;
    _int_data = 0;
    _float_data = 0;
    _double_data = 0;
    _type = NONE;
}

Converter::Converter(char *s) {
    _src = std::string(s);
    _char_data = 0;
    _int_data = 0;
    _float_data = 0;
    _double_data = 0;
    _type = NONE;
}

Converter::~Converter() {}

Converter::Converter(const Converter &c) {
    *this = c;
}

void Converter::detect_type() {
    if (_src.length() == 1) {
        _handle_digit();
        return;
    }
    if (is_invalid()) {
        _handle_invalid();
        return;
    }
    as_number();
}

void Converter::as_number() {
    std::string::size_type dot, f;

    dot = _src.find('.');
    f = _src.find('f', _src.length() - 1);
    if (dot == std::string::npos) {
        try {
            _to_int();
            _type = INT;
        } catch (OverflowException &ie) {
            try {
                _to_double();
                _type = DOUBLE;
            } catch (std::exception &de) {
                std::cout << de.what() << std::endl;
            }
        } catch (std::exception &e) {
            try {
                _to_float();
                _type = FLOAT;
            } catch (std::exception &de) {
                std::cout << de.what() << std::endl;
            }
        }
    }
    else if (f == std::string::npos) {
        try {
            _to_double();
            _type = DOUBLE;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    else {
        try {
            _to_float();
            _type = FLOAT;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

bool Converter::is_invalid() const {
    return _src == "inf" || _src == "inff" || _src == "-inf" || \
     _src == "-inff" || _src == "nan" || _src == "nanf";
}

void Converter::_to_int() {
    int res = 0;
    int i = 0;
    int sign = 0;
    int d;

    if (_src[i] == '+' || _src[i] == '-') {
        sign = static_cast<int>(_src[i] == '-');
        i++;
    }
    for (int i = 0; i < _src.length(); i++) {
        if (!std::isdigit(_src[i]))
            throw NotConvertableException();
        d = static_cast<int>(_src[i] - '0');
        if (sign && res < std::numeric_limits<int>::min() / base)
            throw OverflowException();
        else if (!sign && res > std::numeric_limits<int>::max() / base)
            throw OverflowException();
        res *= base;
        if (sign && res < std::numeric_limits<int>::min() + d)
            throw OverflowException();
        else if (!sign && res > std::numeric_limits<int>::max() - d)
            throw OverflowException();
        if (sign)
            res -= d;
        else
            res += d;
    }
    _int_data = static_cast<int>(res);
}

void Converter::_to_float() {
    float res = 0;

    res = _hanlde_float();
    if (res > std::numeric_limits<float>::max() || res < std::numeric_limits<float>::min())
        throw OverflowException();
    _float_data = static_cast<float>(res);
}

void Converter::_to_double() {
    float res = 0;

    res = _hanlde_float();
    _double_data = res;
}

void Converter::parse() {
    detect_type();
    print_all();
}

void Converter::print_char(std::stringstream &ss) const {
    ss << "char: ";
    switch (_type) {
    case CHAR:
        ss << "'" << _char_data << "'";
        return;
    case INT:
        if (_int_data >= 32 && _int_data <= 127) {
            ss << "'" << static_cast<char>(_int_data) << "'";
            return;
        }
    case FLOAT:
        if (is_invalid()) {
            ss << "impossible";
            return;
        }
        if (_float_data >= 32.0f && _float_data <= 127.0f) {
            ss << "'" << static_cast<char>(_float_data) << "'";
            return;
        }
        break;
    case DOUBLE:
        if (is_invalid()) {
            ss << "impossible";
            return;
        }
        if (_double_data >= 32.0 && _double_data <= 127.0) {
            ss << "'" << static_cast<char>(_double_data) << "'";
            return;
        }
        break;
    default:
        break;
    }
    ss << "Non displayable";
}

void Converter::print_int(std::stringstream &ss) const {
    ss << "int: ";
    switch (_type) {
    case CHAR:
        ss << static_cast<int>(_char_data);
        return;
    case INT:
        ss << _int_data;
        return;
    case FLOAT:
        if (is_invalid() || \
            (_float_data > std::numeric_limits<int>::max() || _float_data < std::numeric_limits<int>::min()))
            ss << "impossible";
        else
            ss << static_cast<int>(_float_data);
        return;
    case DOUBLE:
        if (is_invalid() || \
            (_double_data > std::numeric_limits<int>::max() || _double_data < std::numeric_limits<int>::min()))
            ss << "impossible";
        else
            ss << static_cast<int>(_double_data);
        return;
    default:
        break;
    }
}

void Converter::print_float(std::stringstream &ss) const {
    ss << "float: ";
    switch (_type) {
    case CHAR:
        ss << static_cast<float>(_char_data);
        return;
    case INT:
            ss << static_cast<float>(_int_data);
        return;
    case FLOAT:
        ss << _float_data;
        return;
    case DOUBLE:
        if (_double_data > std::numeric_limits<float>::max() || _double_data < std::numeric_limits<float>::min())
            ss << static_cast<float>(_double_data);
        else
            ss << "impossible";
        return;
    default:
        break;
    }
}

void Converter::print_double(std::stringstream &ss) const {
    ss << "double: ";
    switch (_type) {
    case CHAR:
        ss << static_cast<double>(_char_data);
        return;
    case INT:
            ss << static_cast<double>(_int_data);
        return;
    case FLOAT:
        ss << static_cast<double>(_float_data);
        return;
    case DOUBLE:
        ss << _double_data;
        return;
    default:
        break;
    }
}

void Converter::print_all() const {
    std::stringstream ss;

    print_char(ss);
    ss << std::endl;
    print_int(ss);
    std::cout << ss.str() << std::endl;
    ss.str(std::string());
	ss.clear();
    print_float(ss);
    if (!is_invalid() && ss.str().find('.') == std::string::npos)
        ss << ".0";
    ss << "f\n";
    std::cout << ss.str();
    ss.str(std::string());
	ss.clear();
    print_double(ss);
    if (!is_invalid() && ss.str().find('.') == std::string::npos)
        ss << ".0";
    std::cout << ss.str() << std::endl;
}

Converter& Converter::operator=(const Converter &c) {
    _src = c._src;
    _char_data = c._char_data;
    _int_data = c._int_data;
    _float_data = c._float_data;
    _double_data = c._double_data;
    _type = c._type;
    return *this;
}
