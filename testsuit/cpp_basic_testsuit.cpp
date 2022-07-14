#include "cpp_basic_testsuit.hpp"

Test::Test(int (*test)(void), string testName)
{
    m_testName = testName;
    m_test = test;
}

int Test::execTest(void)
{
    int res = m_test();
    cout << "\e[0;34m" << m_testName;

    if (res)
        cout << " \e[1;32mOK\e[0m" << endl;
    else
        cout << " \e[1;32mFAIL\e[0m" << endl;

    return res;
}

Testsuit::Testsuit(Test* tests, size_t total)
{
    m_total = total;
    m_success = 0;
    m_failure = 0;
    m_tests = tests;
}

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
