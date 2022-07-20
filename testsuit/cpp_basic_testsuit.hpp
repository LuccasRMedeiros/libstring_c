#ifndef CPP_BASIC_TESTSUIT_HPP
#define CPP_BASIC_TESTSUIT_HPP

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief f_testcase is a alias for bool to better describe a test routine 
 */
typedef bool f_testcase;

// Classes

/**
 * @brief Assertion class is a interface for a assertion. It contains a testcase
 * and the name of the testcase
 */
class Assertion
{
    private:
        f_testcase (*_testcase)(void); // The testcase of the assertion
        string _testName; // The descriptive name of the test

    public:
        Assertion(f_testcase (*testcase)(void), string testName);
        int assert(void);
};

/**
 * @brief AssertionSet class is a interface for a group of assertions. Contains
 * counters for sucesses, failures, and a vector of tests that are to be 
 * asserted.
 */
class AssertionSet
{
    private:
        int _success; // Count how many successes ocurred
        int _failure; // Count how many failures ocurred
        vector<Assertion> _tests; // Vector of the tests that are to be executed

    public:
        AssertionSet(vector<Assertion> tests);
        void doAssertions(void);
};

// Commom functions
bool assert_strings_are_equal(const string result, const string expected);
bool assert_integer_values_are_equal(const int result, const int expected);

#endif
