#include "cpp_basic_testsuit.hpp"

/**
 * @brief Assertion class constructor
 *
 * @param testcase Pointer to the test routine
 * @param testName The name of the test
 */
Assertion::Assertion(f_testcase (*testcase)(void), string testName)
{
    _testName = testName;
    _testcase = testcase;
}

/**
 * @brief Executes the test routine assigned to the instance and tell if it was
 * successful or not
 *
 * @return Return if the expected result was obtained or not
 */
int Assertion::assert(void)
{
    int res = _testcase();
    cout << "\e[0;34m" << _testName;

    if (res)
        cout << " \e[1;32mOK\e[0m" << endl;
    else
        cout << " \e[1;31mFAIL\e[0m" << endl;

    return res;
}

/**
 * @brief AssertionSet class constructor
 *
 * @param tests Vector of tests that will be executed
 * @param total How many tests there are
 */
AssertionSet::AssertionSet(vector<Assertion> tests)
{
    _success = 0;
    _failure = 0;
    _tests = tests;
}

/**
 * @brief Execute all the tests, in the end yells how many tests passed and how
 * many failed
 */
void AssertionSet::doAssertions(void)
{
    for (size_t t = 0; t < _tests.size(); ++t)
    {
        if (_tests[t].assert())
            _success++;
        else
            _failure++;
    }

    cout << "=============================================\n";
    cout << "\e[0;34mFinished all \e[1;34m" << _tests.size() << " \e[0;34mtests\e[0m\n";
    
    if (_success) // If one or more successes had happened prints how many
        cout << "\e[1;32m" << _success << " \e[0;34msuccessfully completed\e[0m\n";
    if (_failure) // If one or more failures had happened prints how many
        cout << "\e[1;31m" << _failure << " \e[0;34mfailed\e[0m\n";
}

/**
 * @brief Assert that both strings received and expected are equal. When that
 * is not the case yell what happened
 *
 * @param received: The result of a routine
 * @param expected: The expected result of a routine
 * @return True if they are equal or false
 */
bool assert_strings_are_equal(const string received, const string expected)
{
    if (expected != received)
    {
        cout << "\n\e[0mExpected string:\e[1;31m" << expected << "\e[0m; received string:\e[1;31m" << received << "\e[0m;\n";
        return false;
    }

    return true;
}

/**
 * @brief Assert that both integer values are equal. When that is not the case
 * yell what happened
 *
 * @param received: The result of a routine
 * @param expected: The expected result
 * @return True if they are equal or false
 */
bool assert_values_are_equal(const unsigned int received, const unsigned int expected)
{
    if (expected != received)
    {
        cout << "\n\e[0mExpected value:\e[1;31m" << expected << "\e[0m; received value:\e[1;31m" << received << "\e[0m;\n";
        return false;
    }

    return true;
}

/**
 * @brief Assert that the value of the received integer is zero, not more nor
 * less. When that is not the case yell what happened
 *
 * @param received: The result of a routine
 * @return True if received is zero or false
 */
bool assert_value_is_zero(const unsigned int received)
{
    if (received)
    {
        cout << "\n\e[0mValue is not zero, received:\e[1;31m" << received << "\e[0m;\n";
        return false;
    }

    return true;
}
