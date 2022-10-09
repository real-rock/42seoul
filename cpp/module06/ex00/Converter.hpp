/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:58:20 by jiheo             #+#    #+#             */
/*   Updated: 2022/10/06 12:21:32 by jiheo            ###   ########.fr       */
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
    class ConvertException : public std::exception {
    public:
        const char* what() const throw () { return "Can't convert type you selected."; }
    };

    class OverflowException : public std::exception {
    public:
        const char* what() const throw () { return "Overflow found."; }
    };

public:
    const static int base = 10;

private:
    std::string _src;
    double _data;
    Type _type;

    static bool _is_invalid(std::string &s);
    static bool _is_invalid(double n);
    static double _handle_int(std::string s);
    static double _handle_frac(std::string s);
    static double _str_to_doub(std::string &s);
    static float _str_to_float(std::string &s);
    static char _str_to_char(std::string &s);
    static int _str_to_int(std::string &s);
    void _handle_invalid();

public:
    Converter();
    Converter(char *s);
    Converter(const Converter &c);
    ~Converter();

    void parse();
    void print_all() const;
    Converter &operator=(const Converter &c);
};

#endif