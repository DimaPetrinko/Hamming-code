// HammingCodeCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <bitset>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string message;
bool binaryMessage[16];
bool codedMessage[21];

void Convert(string myString)
{
	string bitString;
	for (std::size_t i = 0; i < myString.size(); ++i)
	{
		std::bitset<8> b(myString.c_str()[i]);
		bitString += b.to_string();
	}

	unsigned short i = 0;
	for each (unsigned char c in bitString)
	{
		binaryMessage[i++] = c - '0';
	}
}

void Input()
{
	cin >> message;
	Convert(message);
}

int CheckBit(unsigned short &i)
{
	int bitCount = 0;
	if (i != 0 && i != 1 && i != 3 && i != 7 && i != 15)
	{
		return codedMessage[i];
	}
	else
	{
		for (unsigned short j = i + 1; j < 21; j++)
		{
			if (((j + 1) / (i + 1)) % 2)
			{
				if (codedMessage[j]) bitCount++;
			}
		}
		return bitCount % 2;
	}
}

bool CheckCode(bool(&message)[21])
{
	for (unsigned short i = 0; i < 21; i++)
	{
		bool b = CheckBit(i);
		if (message[i] != b) return false;
	}
	return true;
}

void Code(bool(&message)[16])
{
	unsigned short iOriginal = 0;
	for (unsigned short i = 0; i < 21; i++)
	{
		if (i != 0 && i != 1 && i != 3 && i != 7 && i != 15)
			codedMessage[i] = message[iOriginal++];
		else
			codedMessage[i] = 0;
	}
	for (unsigned short i = 0; i < 21; i++)
	{
		codedMessage[i] = CheckBit(i);
	}
}


int main()
{
	cout << "Please enter the message\n";
	Input();
	Code(binaryMessage);
	{
		{
			cout << "The original message:\n";
			unsigned short j = 0;
			for (unsigned short i = 0; i < 21; i++)
			{
				if (i != 0 && i != 1 && i != 3 && i != 7 && i != 15) cout << binaryMessage[j++];
				else cout << ' ';
			}
			cout << endl;
		}

		cout << "The coded message:\n";
		for each (unsigned short s in codedMessage)
		{
			cout << s;
		}
		cout << endl;

		//codedMessage[18] = !codedMessage[18];

		cout << "The coded message:\n";
		for each (unsigned short s in codedMessage)
		{
			cout << s;
		}
		cout << endl;

		for (unsigned short i = 0; i < 21; i++)
		{
			if (i != 0 && i != 1 && i != 3 && i != 7 && i != 15) cout << '-';
			else cout << 'c';
		}
		cout << endl;

		cout << (CheckCode(codedMessage) ? "true" : "false") << endl;
	}
	unsigned char c;
	cin >> c;
	cout << (int)c << endl;
	cin >> message;
	return 0;
}