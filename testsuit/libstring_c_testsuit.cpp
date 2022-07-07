extern "C"
{
    #include <string_c.h>
}

#include <iostream>

using namespace std;

int (f)(void) f_test;

class Test
{
    private:
        f_test m_test;

    public:
        string testName;

        Test(f_test test, string name)
        {
            testName = name;
            m_test = test;
        }

        int execTest(void){ return m_test(); };
};

class Testsuit
{
    private:
        int m_total;
        int m_success;
        int m_failure;
        Test* m_tests;
    
    public:
        Testsuit(Test* tests)
        {
            m_total = sizeof (tests);
            m_success = 0;
            m_failure = 0;
            m_tests = tests;
        }

        void execTests(void)
        {
            for (int t = 0; t < m_total; ++t)
            {
                if (m_tests[t].execTest())
                {
                    m_success++;
                    cout << "\e[0;32m" << m_tests[t].testName << " OK\e[0m\n";
                }
                else
                {
                    m_failure++;
                    cout << "\e[0;31m" << m_tests[t].testName << " FAILED\e[0m\n";
                }
            }

            cout << "=============================================\n";
            cout << "\e[0;34mFinished all \e[1;34m" << m_total << " \e[0;34mtests\e[0m\n";
            if (m_success) // If one or more successes had happened prints how many
                cout << "\e[1;32m" << m_success << " \e[0;34msuccessfully completed\e[0m\n";
            if (m_failure) // If one or more failures had happened prints how many
                cout << "\e[1;31m" << m_failure << " \e[0;34mfailed\e[0m\n";
        }
};

int test3(void)
{
    string_t str = " \t\rtrim this\n\v\f";

    trim_string_t(str);

    // Return if str was correctly trimmed
    return (!strcmp(str, "trim this"));
}

int test2(void)
{
    string_t str = "does not trim this";

    trim_string_t(str);

    // Return if str didn't lose any data, making strcmp return 0
    return (!strcmp(str, "does not trim this"));
}

int test1(void)
{
    string_t str = "         trim this          ";
    trim_string_t(str);
    
    // Return if str was correctly trimmed, making strcmp return 0
    return (!strcmp(str, "trim this"));
}

int main(void)
{
    Test execTest1(test1, "Test if trim_string_t trims string_t str");
    Test execTest2(test2, "Test if trim_string_t does not trim trimmed string";
    Test execTest3(test3, "Test if trim_string_t works with various whitespace chars");

    Test tests[] = {
        execTest1,
        execTest2,
        execTest3
    };

    Testsuit testbattery(tests);

    testbattery.execTests();

    return 0;
}
