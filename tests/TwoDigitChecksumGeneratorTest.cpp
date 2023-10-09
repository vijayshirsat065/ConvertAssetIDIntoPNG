// TwoDigitChecksumGeneratorTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "TwoDigitChecksumGenerator.h"

using namespace testing;

TEST(TwoDigitChecksumGeneratorTest, ChecksumBase)
{
	unsigned int checksumBase = 68;

	CTwoDigitChecksumGenerator twoDigitChecksumGenerator(checksumBase);

	EXPECT_EQ(checksumBase, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 0;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_NE(0, twoDigitChecksumGenerator.getChecksumBase());
	EXPECT_EQ(1u, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 99;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_EQ(checksumBase, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 100;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_EQ(99u, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 1267;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_EQ(99u, twoDigitChecksumGenerator.getChecksumBase());
}

TEST(TwoDigitChecksumGeneratorTest, generateChecksumForNumber)
{
	const auto numberOfExpectedDigits = 4;
	auto number = 1337u;
	auto checksumBase = 97u;
	auto checksum = 0u;

	CTwoDigitChecksumGenerator twoDigitChecksumGenerator(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(56, checksum);

	number = 1;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(30, checksum);

	number = 27;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(22, checksum);

	number = 389;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(33, checksum);

	number = 2000;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(2, checksum);

	checksumBase = 65;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(2, checksum);

	number = 389;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(15, checksum);
}

TEST(TwoDigitChecksumGeneratorTest, generateChecksumAndGetDigitsOfTheChecksummedCode)
{
	const auto numberOfExpectedDigits = 4;
	auto number = 1337u;
	auto checksumBase = 97u;
	auto checksum = 0u;	

	CTwoDigitChecksumGenerator twoDigitChecksumGenerator(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(56, checksum);

	number = 1;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(30, checksum);

	number = 27;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(22, checksum);

	number = 389;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(33, checksum);

	number = 2000;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(2, checksum);

	checksumBase = 65;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(2, checksum);

	number = 389;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	twoDigitChecksumGenerator.generateChecksumForNumber(number, numberOfExpectedDigits, checksum);
	EXPECT_EQ(15, checksum);
}