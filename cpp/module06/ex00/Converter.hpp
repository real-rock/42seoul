/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:58:20 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/10 11:24:05 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <sstream>

class Converter {
private:
    enum Type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        NONE,
    };

public:
    class NotConvertableException : public std::exception {
    public:
        const char* what() const throw () { return "Can't convert type you selected."; }
    };

    class NotDisplayableException : public std::exception {
    public:
        const char* what() const throw () { return "Non displayable"; }
    };

    class OverflowException : public std::exception {
    public:
        const char* what() const throw () { return "Overflow found."; }
    };

public:
    const static int base = 10;

private:
    std::string _src;
    char _char_data;
    int _int_data;
    float _float_data;
    double _double_data;
    Type _type;

    void _handle_invalid();
    void _handle_digit();
    double _hanlde_float();

    void _to_int();
    void _to_float();
    void _to_double();
    
    static double _handle_exp(std::string s);
    static double _handle_frac(std::string s);

public:
    Converter();
    Converter(char *s);
    Converter(const Converter &c);
    ~Converter();

    void detect_type();
    void as_number();
    bool is_invalid() const;

    void parse();
    void print_all() const;

    void print_char(std::stringstream &ss) const;
    void print_int(std::stringstream &ss) const;
    void print_float(std::stringstream &ss) const;
    void print_double(std::stringstream &ss) const;

    Converter &operator=(const Converter &c);
};

#endif