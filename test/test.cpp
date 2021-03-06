#include <iostream>
#include <string>

#include "pystring14/pystring.hpp"
#include "unittest.h"

using namespace std::string_literals;

PYSTRING_TEST_APP(PyStringUnitTests)

PYSTRING_ADD_TEST(pystring, endswith)
{
    PYSTRING_CHECK_EQUAL(pystring::endswith(""s, ""s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith(""s, "a"s), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("a"s, ""s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith(""s, ".mesh"s), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s, 0), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s, 1), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s, 1, 2), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s, 1, 1), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s, 1, -1), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("help"s, ".mesh"s, -1), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith(".mesh"s, ".mesh"s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith("a.mesh"s, ".mesh"s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith("a."s, "."s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith("abcdef"s, "ef"s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith("abcdef"s, "cdef"s), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith("abcdef"s, "cdef"s, 2), true);
    PYSTRING_CHECK_EQUAL(pystring::endswith("abcdef"s, "cdef"s, 3), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("abcdef"s, "cdef"s, 2, 3), false);
    PYSTRING_CHECK_EQUAL(pystring::endswith("abcdef"s, "cdef"s, -10), true);
}

PYSTRING_ADD_TEST(pystring, alnum)
{
    PYSTRING_CHECK_EQUAL(bool(std::isalnum('1')), true);
    PYSTRING_CHECK_EQUAL(bool(std::isalnum(' ')), false);
    PYSTRING_CHECK_EQUAL(pystring::isalnum(""s), false);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("  "s), false);
    PYSTRING_CHECK_EQUAL(pystring::isalnum(" \n\b\t"), false);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("123"s), true);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("1"s), true);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("wqe"s), true);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("w"s), true);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("1"), true);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("W"), true);
    PYSTRING_CHECK_EQUAL(pystring::isalnum("1123"), true);
}

PYSTRING_ADD_TEST(pystring, find)
{
    PYSTRING_CHECK_EQUAL(pystring::find("", ""), 0);
    PYSTRING_CHECK_EQUAL(pystring::find("", "a"), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("a", ""), 0);
    PYSTRING_CHECK_EQUAL(pystring::find("a", "a"), 0);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, ""), 0);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "", -1), 5);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "", -2), 4);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "", -5), 1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "", -6), 0);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "", -7), 0);
    
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "def"), 3);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "def", 3), 3);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "def", 4), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "def", -5), 3);
    PYSTRING_CHECK_EQUAL(pystring::find("abcdef"s, "def", -1), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 5), 7);
    
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc"s, "bc"s, -2), 7);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", -1), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 0), 1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 1), 1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 2), 4);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 4), 4);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 7), 7);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 4, 3), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 4, 4), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 4, 5), -1);
    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 4, -1), 4);

    PYSTRING_CHECK_EQUAL(pystring::find("abcabcabc", "bc", 4, 6), 4);
}

PYSTRING_ADD_TEST(pystring, rfind)
{
    PYSTRING_CHECK_EQUAL(pystring::rfind("", ""), 0);
    PYSTRING_CHECK_EQUAL(pystring::rfind("", "a"), -1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("a", ""), 1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("a", "a"), 0);
    
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, ""), 6);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "", 0, 1), 1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "", 0, 5), 5);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "", 0,-1), 5);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "", 0,-3), 3);
    
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "def"), 3);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "def", 3), 3);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "def", 4), -1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "def", -5), 3);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcdef"s, "def", -1), -1);
    
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", -2), 7);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", -1), -1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 0), 7);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 1), 7);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 4), 7);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 7), 7);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 4, -5), -1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 4, -10), -1);
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "bc", 4, 20), 7);
    
    PYSTRING_CHECK_EQUAL(pystring::rfind("abcabcabc", "abc", 6, 8), -1);
}

PYSTRING_ADD_TEST(pystring, replace)
{
    PYSTRING_CHECK_EQUAL(pystring::replace("abcdef"s, "foo", "bar"), "abcdef"s);
    PYSTRING_CHECK_EQUAL(pystring::replace("abcdef"s, "ab", "cd"), "cdcdef");
    PYSTRING_CHECK_EQUAL(pystring::replace("abcdef"s, "ab", ""), "cdef");
    PYSTRING_CHECK_EQUAL(pystring::replace("abcabc", "ab", ""), "cc");
    PYSTRING_CHECK_EQUAL(pystring::replace("abcdef"s, "", ""), "abcdef"s);
    PYSTRING_CHECK_EQUAL(pystring::replace("abcdef"s, "", "."), ".a.b.c.d.e.f.");
}

PYSTRING_ADD_TEST(pystring, slice)
{
    PYSTRING_CHECK_EQUAL(pystring::slice(""), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("", 1), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("", -1), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("", -1,2), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s), "abcdef"s);
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,0), "abcdef"s);
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,1), "bcdef");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2), "cdef");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,2), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,3), "c");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,1), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,-1), "cde");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,-2), "cd");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,-3), "c");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,-4), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,2,-5), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-1), "f");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-2), "ef");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-99), "abcdef"s);
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-99,-98), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-2, 3), "");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-2, 10), "ef");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,-1), "f");
    PYSTRING_CHECK_EQUAL(pystring::slice("abcdef"s,0,-1), "abcde");
}

PYSTRING_ADD_TEST(pystring, split)
{
    {
        auto result = pystring::split(""s, "/"s, 1);
        PYSTRING_CHECK_EQUAL(result.size(), 1);
        if(result.size() == 1)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
        }
    }

    {
        auto result = pystring::split("/", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "");
        }
    }
    
    {
        auto result = pystring::split(" ", " ", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "");
        }
    }
    
    {
        auto result = pystring::split(" /", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], " ");
            PYSTRING_CHECK_EQUAL(result[1], "");
        }
    }
    
    {
        auto result = pystring::split(" //", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], " ");
            PYSTRING_CHECK_EQUAL(result[1], "/");
        }
    }
    
    {
        auto result = pystring::split("a  ", " ", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "a");
            PYSTRING_CHECK_EQUAL(result[1], " ");
        }
    }
    
    {
        auto result = pystring::split("//as//rew//gdf"s, "//"s);
        PYSTRING_CHECK_EQUAL(result.size(), 4);
        if(result.size()==4)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "as");
            PYSTRING_CHECK_EQUAL(result[2], "rew");
            PYSTRING_CHECK_EQUAL(result[3], "gdf");
        }
    }
    
    {
        auto result = pystring::split("/root", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
        }
    }
    
    {
        auto result = pystring::split("/root/world", "/", 0);
        PYSTRING_CHECK_EQUAL(result.size(), 1);
        if(result.size()==1)
        {
            PYSTRING_CHECK_EQUAL(result[0], "/root/world");
        }
    }
    
    {
        auto result = pystring::split("/root/world", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root/world");
        }
    }
    
    {
        auto result = pystring::split("/root/world", "/", 2);
        PYSTRING_CHECK_EQUAL(result.size(), 3);
        if(result.size()==3)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
            PYSTRING_CHECK_EQUAL(result[2], "world");
        }
    }
    
    {
        auto result = pystring::split("/root/world", "/", -1);
        PYSTRING_CHECK_EQUAL(result.size(), 3);
        if(result.size() == 3)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
            PYSTRING_CHECK_EQUAL(result[2], "world");
        }
    }
}

PYSTRING_ADD_TEST(pystring, splitlines)
{
    std::string str = "test\nline2\n   123line312";

    auto result = pystring::splitlines(str);
    PYSTRING_CHECK_EQUAL(result.size(), 3);
    if(result.size() == 3)
    {
        PYSTRING_CHECK_EQUAL(result[0], "test");
        PYSTRING_CHECK_EQUAL(result[1], "line2");
        PYSTRING_CHECK_EQUAL(result[2], "   123line312");
    }
}

PYSTRING_ADD_TEST(pystring, join)
{
    std::array<std::string, 3> a{"abc", "def", "ghijklm"};
    PYSTRING_CHECK_EQUAL(pystring::join(", ", a), "abc, def, ghijklm");
    std::vector<pystring::string_view> b{"abc", "def", "ghijklm"};
    PYSTRING_CHECK_EQUAL(pystring::join(" || ", b), "abc || def || ghijklm");
    std::vector<std::string> c =  {"test"};
    PYSTRING_CHECK_EQUAL(pystring::join(", ", c), "test");
    std::vector<std::string> d = {"abc", "def", "ghijklm"};
    PYSTRING_CHECK_EQUAL(pystring::join(" x ", d), "abc x def x ghijklm");
}


PYSTRING_ADD_TEST(pystring, rsplit)
{
    {
        auto result = pystring::rsplit("", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 1);
        if(result.size()==1)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
        }
    }
    
    {
        // "".rsplit(None, 1)
        auto result = pystring::rsplit("", "", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 0);
    }
    
    {
        // " ".rsplit(None, 1)
        auto result = pystring::rsplit(" ", "", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 0);
    }
    
    {
        auto result = pystring::rsplit("  ", "", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 0);
    }
    
    {
        auto result = pystring::rsplit("/", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "");
        }
    }
    
    {
        auto result = pystring::rsplit(" /", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], " ");
            PYSTRING_CHECK_EQUAL(result[1], "");
        }
    }
    
    {
        auto result = pystring::rsplit(" //", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], " /");
            PYSTRING_CHECK_EQUAL(result[1], "");
        }
    }
    
    {
        auto result = pystring::rsplit("/root", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
        }
    }
    
    {
        auto result = pystring::rsplit("/root/world", "/", 0);
        PYSTRING_CHECK_EQUAL(result.size(), 1);
        if(result.size()==1)
        {
            PYSTRING_CHECK_EQUAL(result[0], "/root/world");
        }
    }
    
    {
        auto result = pystring::rsplit("/root/world", "/", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "/root");
            PYSTRING_CHECK_EQUAL(result[1], "world");
        }
    }
    
    {
        auto result = pystring::rsplit("/root/world", "/", 2);
        PYSTRING_CHECK_EQUAL(result.size(), 3);
        if(result.size()==3)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
            PYSTRING_CHECK_EQUAL(result[2], "world");
        }
    }
    
    {
        auto result = pystring::rsplit("/root/world", "/", -1);
        PYSTRING_CHECK_EQUAL(result.size(), 3);
        if(result.size()==3)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
            PYSTRING_CHECK_EQUAL(result[2], "world");
        }
    }
    
    {
        // " root world".rsplit(None, 0)
        auto result = pystring::rsplit(" root world", "", 0);
        PYSTRING_CHECK_EQUAL(result.size(), 1);
        if(result.size()==1)
        {
            PYSTRING_CHECK_EQUAL(result[0], " root world");
        }
    }
    
    {
        // " root world".rsplit(None, 1)
        auto result = pystring::rsplit(" root world", "", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], " root");
            PYSTRING_CHECK_EQUAL(result[1], "world");
        }
    }
    
    {
        // " root world".rsplit(None, 2)
        auto result = pystring::rsplit(" root world", "", 2);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], "root");
            PYSTRING_CHECK_EQUAL(result[1], "world");
        }
    }
    
    
    {
        // " root world".rsplit(" ", 0)
        auto result = pystring::rsplit(" root world", " ", 0);
        PYSTRING_CHECK_EQUAL(result.size(), 1);
        if(result.size()==1)
        {
            PYSTRING_CHECK_EQUAL(result[0], " root world");
        }
    }
    
    {
        // " root world".rsplit(" ", 1)
        auto result = pystring::rsplit(" root world", " ", 1);
        PYSTRING_CHECK_EQUAL(result.size(), 2);
        if(result.size()==2)
        {
            PYSTRING_CHECK_EQUAL(result[0], " root");
            PYSTRING_CHECK_EQUAL(result[1], "world");
        }
    }
    
    {
        // " root world".rsplit(" ", 2)
        auto result = pystring::rsplit(" root world", " ", 2);
        PYSTRING_CHECK_EQUAL(result.size(), 3);
        if(result.size()==3)
        {
            PYSTRING_CHECK_EQUAL(result[0], "");
            PYSTRING_CHECK_EQUAL(result[1], "root");
            PYSTRING_CHECK_EQUAL(result[2], "world");
        }
    }
}

PYSTRING_ADD_TEST(pystring, startswith)
{
    PYSTRING_CHECK_EQUAL(pystring::startswith("", ""), true);
    PYSTRING_CHECK_EQUAL(pystring::startswith("", "a"), false);
    PYSTRING_CHECK_EQUAL(pystring::startswith("a", ""), true);
    PYSTRING_CHECK_EQUAL(pystring::startswith("abc", "ab"), true);
    PYSTRING_CHECK_EQUAL(pystring::startswith("abc", "abc"), true);
    PYSTRING_CHECK_EQUAL(pystring::startswith("abc", "abcd"), false);
    PYSTRING_CHECK_EQUAL(pystring::startswith("abcdef"s, "abc"), true);
    PYSTRING_CHECK_EQUAL(pystring::startswith("abcdef"s, "abc", 1), false);
    PYSTRING_CHECK_EQUAL(pystring::startswith("abcdef"s, "bc", 1), true);
}

PYSTRING_ADD_TEST(pystring, strip)
{
    PYSTRING_CHECK_EQUAL(pystring::strip(""), "");
    PYSTRING_CHECK_EQUAL(pystring::strip("a"), "a");
    PYSTRING_CHECK_EQUAL(pystring::strip("a "), "a");
    PYSTRING_CHECK_EQUAL(pystring::strip(" a"), "a");
    PYSTRING_CHECK_EQUAL(pystring::strip("\n a "), "a");
    PYSTRING_CHECK_EQUAL(pystring::strip("\r\n a \r\n"), "a");
    PYSTRING_CHECK_EQUAL(pystring::strip("\r\n a \r\n\t"), "a");
    pystring::string seps("xyz");
    pystring::string_view xsep(seps.c_str(), 1); // just select x
    PYSTRING_CHECK_EQUAL(pystring::strip("xxxyyayzyzxxx", xsep), "yyayzyz");
    PYSTRING_CHECK_EQUAL(pystring::strip("xxxayzyzxxx", seps), "a");
}

PYSTRING_ADD_TEST(pystring, expandtabs)
{
    std::string a = "this\n\tis just a test\tregarding tabs\n\tttt\ttttt";
    auto res = pystring::expandtabs(a);
    std::string exp_a = "this\n        is just a test  regarding tabs\n        ttt     tttt";
    PYSTRING_CHECK_EQUAL(res, exp_a);
}

PYSTRING_ADD_TEST(pystring, zfill)
{
    PYSTRING_CHECK_EQUAL(pystring::zfill("350", 10), "0000000350");
    PYSTRING_CHECK_EQUAL(pystring::zfill("350", 2), "350");
    PYSTRING_CHECK_EQUAL(pystring::zfill("350", 3), "350");
    PYSTRING_CHECK_EQUAL(pystring::zfill("-350", 5), "-0350");
}

PYSTRING_ADD_TEST(pystring, rjust)
{
    PYSTRING_CHECK_EQUAL(pystring::rjust("350", 10), "       350");
    PYSTRING_CHECK_EQUAL(pystring::rjust("350", 2), "350");
    PYSTRING_CHECK_EQUAL(pystring::rjust("350", 3), "350");
    PYSTRING_CHECK_EQUAL(pystring::rjust("-350", 5), " -350");
}

PYSTRING_ADD_TEST(pystring, ljust)
{
    PYSTRING_CHECK_EQUAL(pystring::ljust("350", 10), "350       ");
    PYSTRING_CHECK_EQUAL(pystring::ljust("350", 2), "350");
    PYSTRING_CHECK_EQUAL(pystring::ljust("350", 3), "350");
    PYSTRING_CHECK_EQUAL(pystring::ljust("-350", 5), "-350 ");
}

PYSTRING_ADD_TEST(pystring, center)
{
    PYSTRING_CHECK_EQUAL(pystring::center("350", 10), "   350    ");
    PYSTRING_CHECK_EQUAL(pystring::center("350", 2), "350");
    PYSTRING_CHECK_EQUAL(pystring::center("350", 3), "350");
    PYSTRING_CHECK_EQUAL(pystring::center("-350", 6), " -350 ");
}

PYSTRING_ADD_TEST(pystring, translate)
{
    char t1data[256];
    for(int i=0; i<256; ++i) t1data[i] = (char)i;
    std::string t1(t1data, 256);
    PYSTRING_CHECK_EQUAL(pystring::translate("", t1), "");
    PYSTRING_CHECK_EQUAL(pystring::translate("cheese", t1), "cheese");
    PYSTRING_CHECK_EQUAL(pystring::translate("cheese", t1, "e"), "chs");
    
    char t2data[256];
    for(int i=0; i<256; ++i) t2data[i] = (char)i;
    t2data[101] = 111; // Map e -> o
    std::string t2(t2data, 256);
    PYSTRING_CHECK_EQUAL(pystring::translate("", t2), "");
    PYSTRING_CHECK_EQUAL(pystring::translate("cheese", t2), "chooso");
}


// PYSTRING_ADD_TEST(pystring, abspath)
// {
//     PYSTRING_CHECK_EQUAL(pystring::os::path::abspath("", "/net"), "/net");
//     PYSTRING_CHECK_EQUAL(pystring::os::path::abspath("../jeremys", "/net/soft_scratch/users/stevel"), "/net/soft_scratch/users/jeremys");
//     PYSTRING_CHECK_EQUAL(pystring::os::path::abspath("../../../../tmp/a", "/net/soft_scratch/users/stevel"), "/tmp/a");
 
// }

// PYSTRING_ADD_TEST(pystring_os_path, splitdrive)
// {
//     using namespace pystring::os::path;
    
//     std::string drivespec, pathspec;
//     splitdrive_posix(drivespec, pathspec, "/Users/test"); PYSTRING_CHECK_EQUAL(drivespec, ""); PYSTRING_CHECK_EQUAL(pathspec, "/Users/test");
//     splitdrive_nt(drivespec, pathspec, "C:\\Users\\test"); PYSTRING_CHECK_EQUAL(drivespec, "C:" ); PYSTRING_CHECK_EQUAL(pathspec, "\\Users\\test" );
//     splitdrive_nt(drivespec, pathspec, "\\Users\\test"); PYSTRING_CHECK_EQUAL(drivespec, "" ); PYSTRING_CHECK_EQUAL(pathspec, "\\Users\\test" );
// }

// PYSTRING_ADD_TEST(pystring_os_path, isabs)
// {
//     using namespace pystring::os::path;
    
//     PYSTRING_CHECK_EQUAL(isabs_posix("/Users/test"), true );
//     PYSTRING_CHECK_EQUAL(isabs_posix("\\Users\\test"), false);
//     PYSTRING_CHECK_EQUAL(isabs_posix("../Users"), false);
//     PYSTRING_CHECK_EQUAL(isabs_posix("Users"), false);
    
//     PYSTRING_CHECK_EQUAL(isabs_nt("C:\\Users\\test"), true);
//     PYSTRING_CHECK_EQUAL(isabs_nt("C:/Users"), true);
//     PYSTRING_CHECK_EQUAL(isabs_nt("/Users"), true);
//     PYSTRING_CHECK_EQUAL(isabs_nt("../Users"), false);
//     PYSTRING_CHECK_EQUAL(isabs_nt("..\\Users"), false);
// }

// PYSTRING_ADD_TEST(pystring_os_path, join)
// {
//     using namespace pystring::os::path;
    
//     PYSTRING_CHECK_EQUAL(join_posix("a","b"), "a/b" );
//     PYSTRING_CHECK_EQUAL(join_posix("/a","b"), "/a/b" );
//     PYSTRING_CHECK_EQUAL(join_posix("/a","/b"), "/b" );
//     PYSTRING_CHECK_EQUAL(join_posix("a","/b"), "/b" );
//     PYSTRING_CHECK_EQUAL(join_posix("//a","b"), "//a/b" );
//     PYSTRING_CHECK_EQUAL(join_posix("//a","b//"), "//a/b//" );
//     PYSTRING_CHECK_EQUAL(join_posix("../a","/b"), "/b" );
//     PYSTRING_CHECK_EQUAL(join_posix("../a","b"), "../a/b" );
    
//     std::vector< std::string > paths;
//     PYSTRING_CHECK_EQUAL(join_posix(paths), "" );
//     paths.push_back("/a");
//     PYSTRING_CHECK_EQUAL(join_posix(paths), "/a" );
//     paths.push_back("b");
//     PYSTRING_CHECK_EQUAL(join_posix(paths), "/a/b" );
//     paths.push_back("c/");
//     PYSTRING_CHECK_EQUAL(join_posix(paths), "/a/b/c/" );
//     paths.push_back("d");
//     PYSTRING_CHECK_EQUAL(join_posix(paths), "/a/b/c/d" );
//     paths.push_back("/e");
//     PYSTRING_CHECK_EQUAL(join_posix(paths), "/e" );
    
//     PYSTRING_CHECK_EQUAL(join_nt("c:","/a"), "c:/a" );
//     PYSTRING_CHECK_EQUAL(join_nt("c:/","/a"), "c:/a" );
//     PYSTRING_CHECK_EQUAL(join_nt("c:/a","/b"), "/b" );
//     PYSTRING_CHECK_EQUAL(join_nt("c:","d:/"), "d:/" );
//     PYSTRING_CHECK_EQUAL(join_nt("c:/","d:/"), "d:/" );
//     PYSTRING_CHECK_EQUAL(join_nt("a","b"), "a\\b" );
//     PYSTRING_CHECK_EQUAL(join_nt("\\a","b"), "\\a\\b" );
//     PYSTRING_CHECK_EQUAL(join_nt("c:\\a","b"), "c:\\a\\b" );
//     PYSTRING_CHECK_EQUAL(join_nt("c:\\a","c:\\b"), "c:\\b" );
//     PYSTRING_CHECK_EQUAL(join_nt("..\\a","b"), "..\\a\\b" );
// }

// PYSTRING_ADD_TEST(pystring_os_path, normpath)
// {
//     using namespace pystring::os::path;
    
//     PYSTRING_CHECK_EQUAL(normpath_posix("A//B"), "A/B" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("A/./B"), "A/B" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("A/foo/../B"), "A/B" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("/A//B"), "/A/B" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("//A//B"), "//A/B" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("///A//B"), "/A/B" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("../A"), "../A" );
//     PYSTRING_CHECK_EQUAL(normpath_posix("../A../"), "../A.." );
//     PYSTRING_CHECK_EQUAL(normpath_posix("FOO/../A../././B"), "A../B" );
    
//     PYSTRING_CHECK_EQUAL(normpath_nt(""), "." );
//     PYSTRING_CHECK_EQUAL(normpath_nt("A"), "A" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("A./B"), "A.\\B" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:\\"), "C:\\" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:\\A"), "C:\\A" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:/A"), "C:\\A" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:/A..\\"), "C:\\A.." );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:/A..\\..\\"), "C:\\" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:\\\\A"), "C:\\A" );
//     PYSTRING_CHECK_EQUAL(normpath_nt("C:\\\\\\A\\\\B"), "C:\\A\\B" );
// }

// PYSTRING_ADD_TEST(pystring_os_path, split)
// {
//     using namespace pystring::os::path;
    
//     std::string head, tail;
//     split_posix(head, tail, "");  PYSTRING_CHECK_EQUAL(head, "" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_posix(head, tail, "/");  PYSTRING_CHECK_EQUAL(head, "/" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_posix(head, tail, "a");  PYSTRING_CHECK_EQUAL(head, "" );  PYSTRING_CHECK_EQUAL(tail, "a" );
//     split_posix(head, tail, "a/");  PYSTRING_CHECK_EQUAL(head, "a" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_posix(head, tail, "/a");  PYSTRING_CHECK_EQUAL(head, "/" );  PYSTRING_CHECK_EQUAL(tail, "a" );
//     split_posix(head, tail, "/a/b/");  PYSTRING_CHECK_EQUAL(head, "/a/b" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_posix(head, tail, "/a/b");  PYSTRING_CHECK_EQUAL(head, "/a" );  PYSTRING_CHECK_EQUAL(tail, "b" );
    
//     split_nt(head, tail, "");  PYSTRING_CHECK_EQUAL(head, "" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_nt(head, tail, "\\");  PYSTRING_CHECK_EQUAL(head, "\\" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_nt(head, tail, "a");  PYSTRING_CHECK_EQUAL(head, "" );  PYSTRING_CHECK_EQUAL(tail, "a" );
//     split_nt(head, tail, "a\\");  PYSTRING_CHECK_EQUAL(head, "a" );  PYSTRING_CHECK_EQUAL(tail, "" );
//     split_nt(head, tail, "c:\\a");  PYSTRING_CHECK_EQUAL(head, "c:\\" );  PYSTRING_CHECK_EQUAL(tail, "a" );
//     split_nt(head, tail, "c:\\a\\b");  PYSTRING_CHECK_EQUAL(head, "c:\\a" );  PYSTRING_CHECK_EQUAL(tail, "b" );
//     split_nt(head, tail, "c:\\a\\b\\");  PYSTRING_CHECK_EQUAL(head, "c:\\a\\b" );  PYSTRING_CHECK_EQUAL(tail, "" );
// }

// PYSTRING_ADD_TEST(pystring_os_path, splitext)
// {
//     using namespace pystring::os::path;
    
//     std::string root, ext;
//     splitext_nt(root, ext, ""); PYSTRING_CHECK_EQUAL(root, ""); PYSTRING_CHECK_EQUAL(ext, "");
//     splitext_nt(root, ext, "."); PYSTRING_CHECK_EQUAL(root, "."); PYSTRING_CHECK_EQUAL(ext, "");
//     splitext_nt(root, ext, ".foo"); PYSTRING_CHECK_EQUAL(root, ".foo"); PYSTRING_CHECK_EQUAL(ext, "");
//     splitext_nt(root, ext, ".foo."); PYSTRING_CHECK_EQUAL(root, ".foo"); PYSTRING_CHECK_EQUAL(ext, ".");
//     splitext_nt(root, ext, ".foo.e"); PYSTRING_CHECK_EQUAL(root, ".foo"); PYSTRING_CHECK_EQUAL(ext, ".e");
//     splitext_nt(root, ext, "c"); PYSTRING_CHECK_EQUAL(root, "c"); PYSTRING_CHECK_EQUAL(ext, "");
//     splitext_nt(root, ext, "a_b.c"); PYSTRING_CHECK_EQUAL(root, "a_b"); PYSTRING_CHECK_EQUAL(ext, ".c");
//     splitext_nt(root, ext, "c:\\a.b.c"); PYSTRING_CHECK_EQUAL(root, "c:\\a.b"); PYSTRING_CHECK_EQUAL(ext, ".c");
//     splitext_nt(root, ext, "c:\\a_b.c"); PYSTRING_CHECK_EQUAL(root, "c:\\a_b"); PYSTRING_CHECK_EQUAL(ext, ".c");
// }
