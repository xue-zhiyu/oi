#ifndef __INTERGER_HPP__
#define __INTERGER_HPP__

#include <iostream>
#include <string>
#include <vector>

namespace BigNumbers {
	class Interger {
	public:
		Interger() : isNegative(false), num(1, 0) {
		}

		Interger(long long _num) : isNegative(_num < 0) {
			if (_num == 0) {
				this->num = std::vector<short>(1, 0);
			} else {
				for (; _num; _num /= 10000) {
					this->num.push_back(_num % 10000);
				}
			}
		}

		Interger(std::string _num) {
			if (_num.empty()) _num = "0";
			if (_num.front() == '-') {
				this->isNegative = true;
				_num = _num.substr(1);
			}
			for (char i : _num) {
				if (i < '0' || i > '9') {
					throw "The number '" + _num + "' is invalid.";
				}
			}
			while (_num.size() % 4) _num = '0' + _num;
			for (int i = ((int) _num.size()) / 4 - 1; ~i; i--) {
				short curNum = 0;
				for (int j = 0; j < 4; j++) curNum = curNum * 10 + _num[(i << 2) + j] - '0';
				this->num.push_back(curNum);
			}
		}

		Interger(const Interger& other) : isNegative(other.isNegative), num(other.num) {
		}

		void operator=(const Interger& other) {
			this->isNegative = other.isNegative;
			this->num = other.num;
		}

		friend std::istream& operator>>(std::istream& input, Interger& num) {
			std::string str;
			input >> str;
			num = Interger(str);
			return input;
		}

		friend std::ostream& operator<<(std::ostream& output, Interger& num) {
			output << num.back() << setfill()
		}

	private:
		bool isNegative;
		std::vector<short> num;
	};
}

#endif

