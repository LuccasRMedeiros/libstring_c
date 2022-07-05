import ctypes
import pytest
from assertpy import assert_that

cdll.LoadLibrary("../libstring_c.so")
libstring_c = CDLL("../libstring_c.so")

def test_1_test_if_trim_string_t_trims_a_string():
    TrimThisString = c_char() * 64
