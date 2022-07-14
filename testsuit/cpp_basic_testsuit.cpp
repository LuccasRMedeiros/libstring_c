#include "cpp_basic_testsuit.hpp"

/**
 * @brief Test class constructor
 *
 * @param test Pointer to the test routine
 * @param testName The name of the test
 */
Test::Test(int (*test)(void), string testName)
{
    m_testName = testName;
    m_test = test;
}

/**
 * @brief Executes the test routine assigned to the instance and tell if it was
 * successful or not
 *
 * @return Return if the expected result was obtained or not
 */
int Test::execTest(void)
{
    int res = m_test();
    cout << "\e[0;34m" << m_testName;

    if (res)
        cout << " \e[1;32mOK\e[0m" << endl;
    else
        cout << " \e[1;31mFAIL\e[0m" << endl;

    return res;
}

/**
 * @brief Testsuit class constructor
 *
 * @param tests Array of tests that will be executed
 * @param total How many tests there are
 */
Testsuit::Testsuit(Test* tests, size_t total)
{
    m_total = total;
    m_success = 0;
    m_failure = 0;
    m_tests = tests;
}

/**
 * @brief Execute all the tests, in the end yells how many tests passed and how
 * many failed
 */
void Testsuit::execTests(void)
{
    for (size_t t = 0; t < m_total; ++t)
    {
        if (m_tests[t].execTest())
            m_success++;
        else
            m_failure++;
    }

    cout << "=============================================\n";
    cout << "\e[0;34mFinished all \e[1;34m" << m_total << " \e[0;34mtests\e[0m\n";
    if (m_success) // If one or more successes had happened prints how many
        cout << "\e[1;32m" << m_success << " \e[0;34msuccessfully completed\e[0m\n";
    if (m_failure) // If one or more failures had happened prints how many
        cout << "\e[1;31m" << m_failure << " \e[0;34mfailed\e[0m\n";
}

int assert_strings_are_equal(const string received, const string expected)
{
    if (expected != received)
    {
        cout << "\n\e[0mExpected:\e[1;31m " << expected << "\e[0m received:\e[1;31m " << received << "\e[0m\n";
        return 0;
    }

    return 1;
}
