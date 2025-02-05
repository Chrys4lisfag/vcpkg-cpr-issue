﻿#include <iostream>
#include <cpr/cpr.h>

//cryptolib
#pragma comment(lib, "Crypt32.lib")
//ws2_32
#pragma comment(lib, "ws2_32.lib")

int main()
{
    cpr::Response r = cpr::Get( cpr::Url{ "https://api.github.com/repos/whoshuu/cpr/contributors" },
        cpr::Authentication{ "user", "pass", cpr::AuthMode::BASIC },
        cpr::Parameters{ {"anon", "true"}, {"key", "value"} } );
    std::cout << "Status code: " << r.status_code << '\n';
    std::cout << "Header:\n";
    for ( const std::pair<const std::basic_string<char>, std::basic_string<char>>& kv : r.header ) {
        std::cout << '\t' << kv.first << ':' << kv.second << '\n';
    }
    std::cout << "Text: " << r.text << '\n';

	system( "pause" );
	return 0;
}